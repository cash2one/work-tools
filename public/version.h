
#ifndef VERSION_H_
#define VERSION_H_

#define BASE_VERSION "1.0.0"
#if defined(DEBUG) || defined(_DEBUG) || defined(_DEBUG_)
#define VERSION BASE_VERSION "_debug_" "6d438c6d8ae273c13f70bdc67246944483a9dbb4" "_" __DATE__ " "  __TIME__
#else
#define VERSION BASE_VERSION "_release_" "6d438c6d8ae273c13f70bdc67246944483a9dbb4" "_" __DATE__ " "  __TIME__
#endif

#endif

