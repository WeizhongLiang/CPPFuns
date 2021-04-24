#pragma once

// Operation system flags definition
#if (defined _WIN32) || (defined _WIN64)
#define	__WINDOWS__             1
#endif

#ifdef CPPFuns_EXPORTS
#if __WINDOWS__
#define CPPFuns_API __declspec(dllexport)
#elif __APPLE__
#define CPPFuns_API
#elif __ANDROID__
#define CPPFuns_API
#endif
#else
#ifdef __WINDOWS__
#define CPPFuns_API __declspec(dllimport)
#elif __APPLE__
#define CPPFuns_API
#elif __ANDROID__
#define CPPFuns_API
#endif
#endif

extern "C" {
    CPPFuns_API int CPPFuns_Init();
    CPPFuns_API int CPPFuns_Cleanup();
    CPPFuns_API int CPPFuns_GetStringLength(const char* sz);
    CPPFuns_API const char* CPPFuns_GetDemoString(int index);
}