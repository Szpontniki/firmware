#if defined(BUILD_MOCK)
	#include "entrypoints/mock.cpp"
#elif defined(BUILD_HARDWARE)
	#include "entrypoints/hardware.cpp"
#else
	#error "No build target defined! Define BUILD_MOCK or BUILD_HARDWARE."
#endif
