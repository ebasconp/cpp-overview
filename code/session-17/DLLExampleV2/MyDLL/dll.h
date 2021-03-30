#pragma once

#ifdef _WIN32

#ifdef MYDLL_EXPORTS
#define MYDLL_EXPORT __declspec(dllexport)
#else
#define MYDLL_EXPORT __declspec(dllimport)
#endif

#else

#define MYDLL_EXPORT

#endif
