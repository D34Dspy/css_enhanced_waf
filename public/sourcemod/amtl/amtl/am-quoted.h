#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

namespace compat {
    struct QuotedProxy {
        std::string& s;
        char delim;
        char escape;
    };

    struct ConstQuotedProxy {
        const std::string& s;
        char delim;
        char escape;
    };

    // Output manipulator: Handles escaping when writing to a stream
    template <typename CharT, typename Traits>
    std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const ConstQuotedProxy& proxy) {
        os << proxy.delim;
        for (char c : proxy.s) {
            if (c == proxy.delim || c == proxy.escape) {
                os << proxy.escape;
            }
            os << c;
        }
        os << proxy.delim;
        return os;
    }

    // Input manipulator: Handles unescaping when reading from a stream
    template <typename CharT, typename Traits>
    std::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT, Traits>& is, QuotedProxy proxy) {
        proxy.s.clear();
        CharT c;
        if (!(is >> c)) return is;
        if (c != proxy.delim) {
            is.putback(c);
            is >> proxy.s;
            return is;
        }

        while (is.get(c) && c != proxy.delim) {
            if (c == proxy.escape) {
                if (!is.get(c)) break;
            }
            proxy.s.push_back(c);
        }
        return is;
    }
}


// The manipulator function
inline compat::ConstQuotedProxy quoted(const std::string& s, char delim = '"', char escape = '\\') {
    return {s, delim, escape};
}

inline compat::QuotedProxy quoted(std::string& s, char delim = '"', char escape = '\\') {
    return {s, delim, escape};
}