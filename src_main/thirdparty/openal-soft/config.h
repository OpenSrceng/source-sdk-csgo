#ifdef LINUX // Generated for linux

/* Define the alignment attribute for externally callable functions. */
#define FORCE_ALIGN 

/* Define if we have the posix_memalign function */
#define HAVE_POSIX_MEMALIGN

/* Define if we have the getopt function */
#define HAVE_GETOPT

/* Define if we have SSE CPU extensions */
#if defined(__i386__) || defined(__x86_64__)
#define HAVE_SSE
#endif

/* Define if we have ARM Neon CPU extensions */
#if defined(__arm__) || defined(__aarch64__) 
#define HAVE_NEON
#endif

/* Define if we have the SDL2 backend */
#define HAVE_SDL2

/* Define if we have dlfcn.h */
#define HAVE_DLFCN_H

/* Define if we have malloc.h */
#define HAVE_MALLOC_H

/* Define if we have cpuid.h */
#if defined(__i386__) || defined(__x86_64__)
#define HAVE_CPUID_H
#endif

/* Define if we have GCC's __get_cpuid() */
#if defined(__i386__) || defined(__x86_64__)
#define HAVE_GCC_GET_CPUID
#endif

/* Define if we have SSE intrinsics */
#if defined(__i386__) || defined(__x86_64__)
#define HAVE_SSE_INTRINSICS
#endif

/* Define if we have pthread_setschedparam() */
#define HAVE_PTHREAD_SETSCHEDPARAM

#define RESTRICT __restrict

#else // LINUX
#error "Generate and edit thirdparty/openal-soft/config.h for your platform"
#endif
