#pragma once

// Missing declarations
#define LF_FACESIZE 32

typedef struct _GLYPHMETRICSFLOAT GLYPHMETRICSFLOAT, *PGLYPHMETRICSFLOAT, *LPGLYPHMETRICSFLOAT;
typedef struct tagTEXTMETRICA TEXTMETRICA, *PTEXTMETRICA, *NPTEXTMETRICA, *LPTEXTMETRICA;
typedef struct tagTEXTMETRICW TEXTMETRICW, *PTEXTMETRICW, *NPTEXTMETRICW, *LPTEXTMETRICW;

// #include "windows_base.h" on >2.7.1 windows_base.h doenst exist anymore
#include "windows.h"