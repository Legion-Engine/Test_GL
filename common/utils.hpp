#pragma once

#include <fstream>
#include <string>

#define WINDOW_H 720
#define WINDOW_W 1280

#ifdef _WIN32
    #define ASSERT _ASSERT
    #define assert _ASSERT
    #ifdef _DEBUG 
        #define DEBUG
    #endif
#endif


using uint = unsigned int;
using ulong = unsigned long;
using ushort = unsigned short;
using byte = unsigned char;
using cstring = const char*;

const float Pi = 3.1415926535897932384626433832795f;

inline float DegToRad(float deg) { return deg * Pi / 180.0f; }

#define LOG(macro_format, ...)										\
{																	\
    printf(macro_format, ##__VA_ARGS__);							\
    const size_t macro_len = strlen(macro_format);					\
    if(macro_len > 0 && macro_format[macro_len - 1] != '\n')		\
    {																\
        printf("\n");												\
    }																\
}

std::string ReadFile(const std::string& filename);