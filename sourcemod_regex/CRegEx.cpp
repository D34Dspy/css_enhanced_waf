/**
 * vim: set ts=4 :
 * =============================================================================
 * SourceMod Regular Expressions Extension
 * Copyright (C) 2004-2008 AlliedModders LLC.  All rights reserved.
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, AlliedModders LLC gives you permission to link the
 * code of this program (as well as its derivative works) to "Half-Life 2," the
 * "Source Engine," the "SourcePawn JIT," and any Game MODs that run on software
 * by the Valve Corporation.  You must obey the GNU General Public License in
 * all respects for all other code used.  Additionally, AlliedModders LLC grants
 * this exception to all derivative works.  AlliedModders LLC defines further
 * exceptions, found in LICENSE.txt (as of this writing, version JULY-31-2007),
 * or <http://www.sourcemod.net/license.php>.
 *
 * Version: $Id$
 */

#include <regex>
#define PCRE_STATIC

#include "CRegEx.h"
#include "extension.h"


class RegExPlaceholder {
	public:
		std::regex rg;
};

RegEx::RegEx()
{
	mErrorOffset = 0;
	mErrorCode = 0;
	mError = nullptr;
	re = nullptr;
	mFree = true;
	subject = nullptr;
	mMatchCount = 0;
}

void RegEx::Clear ()
{
	mErrorOffset = 0;
	mErrorCode = 0;
	mError = nullptr;
	re = nullptr;
	mFree = true;
	if (subject)
		free(subject);
	subject = nullptr;
	mMatchCount = 0;
}

RegEx::~RegEx()
{
	Clear();
}

bool RegEx::isFree(bool set, bool val)
{
	if (set)
	{
		mFree = val;
		return true;
	} else {
		return mFree;
	}
}

int RegEx::Compile(const char *pattern, int iFlags)
{
		
		
	// re = pcre_compile2(pattern, iFlags, &mErrorCode, &mError, &mErrorOffset, nullptr);
	this->re = std::regex(pattern);


	return 1;
}

int RegEx::Match(const char *const str, const size_t offset)
{
    if (mFree || str == nullptr)
        return -1;

    this->ClearMatch();

    // 1. Assign to std::string. Note: std::string handles the copy, 
    // avoiding manual strdup/free management.
    std::string subject(str, str + strlen(str));
    size_t len = subject.length();

    if (offset > len) return 0; // Offset out of bounds

    std::match_results<std::string::iterator> results;
    
    // 2. Create the start iterator based on the offset
    std::string::iterator search_start = subject.begin() + offset;

    // 3. Execute search
    if (std::regex_search(search_start, subject.end(), results, this->re))
    {
        // rc in PCRE is the number of capturing groups + 1
        int rc = static_cast<int>(results.size());
        mMatches[0].mSubStringCount = rc;

        for (int i = 0; i < rc && i < MAX_CAPTURES; ++i)
        {
            if (results[i].matched)
            {
                // Calculate offsets relative to the START of the original string
                mMatches[0].mVector[2 * i] = 
                    static_cast<int>(std::distance(subject.begin(), results[i].first));
                mMatches[0].mVector[2 * i + 1] = 
                    static_cast<int>(std::distance(subject.begin(), results[i].second));
            }
            else
            {
                mMatches[0].mVector[2 * i] = -1;
                mMatches[0].mVector[2 * i + 1] = -1;
            }
        }

        mMatchCount = 1;
        return 1;
    }

    // No match found (equivalent to PCRE_ERROR_NOMATCH)
    return 0;
}


int RegEx::MatchAll(const char *str)
{
    if (mFree || str == nullptr)
        return -1;

    this->ClearMatch();

    // 1. Assign the input to a std::string for iterator-based searching
    std::string subject = std::string(str);
    size_t len = subject.length();

    std::match_results<std::string::iterator> results;
    std::string::iterator search_start = subject.begin();
    unsigned int matches = 0;

    // 2. Loop using std::regex_search with the current offset
    while (matches < MAX_MATCHES && search_start != subject.end() && 
           std::regex_search(search_start, subject.end(), results, this->re))
    {
        // 3. Map std::match_results to your mVector (ovector style)
        // results.size() includes the full match + capture groups
        mMatches[matches].mSubStringCount = static_cast<int>(results.size());

        for (size_t i = 0; i < results.size() && i < MAX_CAPTURES; ++i) {
            if (results[i].matched) {
                // Store start and end offsets relative to the beginning of the string
                mMatches[matches].mVector[2 * i] = 
                    static_cast<int>(std::distance(subject.begin(), results[i].first));
                mMatches[matches].mVector[2 * i + 1] = 
                    static_cast<int>(std::distance(subject.begin(), results[i].second));
            } else {
                mMatches[matches].mVector[2 * i] = -1;
                mMatches[matches].mVector[2 * i + 1] = -1;
            }
        }

        // 4. Update the search start to the end of the current full match
        search_start = results[0].second;
        matches++;

        // Prevent infinite loops on zero-length matches (e.g., /a*/)
        if (results[0].length() == 0) {
            if (search_start == subject.end()) break;
            ++search_start;
        }
    }

    if (matches == 0) {
        return 0; // No match found
    }

    mMatchCount = matches;
    return 1;
}


void RegEx::ClearMatch()
{
	// Clears match results
	mErrorOffset = 0;
	mErrorCode = 0;
	mError = nullptr;
	if (subject)
		free(subject);
	subject = nullptr;
	mMatchCount = 0;
}

bool RegEx::GetSubstring(int s, char buffer[], int max, int match)
{
	int i = 0;

	if (s >= mMatches[match].mSubStringCount || s < 0)
		return false;

	char *substr_a = subject + mMatches[match].mVector[2 * s];
	int substr_l = mMatches[match].mVector[2 * s + 1] - mMatches[match].mVector[2 * s];

	for (i = 0; i<substr_l; i++)
	{
		if (i >= max)
			break;
		buffer[i] = substr_a[i];
	}

	buffer[i] = '\0';

	return true;
}

