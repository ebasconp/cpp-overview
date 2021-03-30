#pragma once

#ifdef MYDLL_EXPORTS
#define MYDLL_EXPORT __declspec(dllexport)
#else
#define MYDLL_EXPORT __declspec(dllimport)
#endif
