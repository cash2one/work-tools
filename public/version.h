
#ifndef VERSION_H_
#define VERSION_H_

#define BASE_VERSION "1.0.0"
#if defined(DEBUG) || defined(_DEBUG) || defined(_DEBUG_)
#define VERSION BASE_VERSION "_debug_" "4dd9e76c9f1b328c021744af5203eb53fcaad27d" "_" __DATE__ " "  __TIME__
#else
#define VERSION BASE_VERSION "_release_" "4dd9e76c9f1b328c021744af5203eb53fcaad27d" "_" __DATE__ " "  __TIME__
#endif

#endif

