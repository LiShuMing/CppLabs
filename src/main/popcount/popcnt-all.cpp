// includes all available implementations

#include "popcnt-lookup.cpp"
#include "popcnt-bit-parallel-scalar.cpp"
#include "popcnt-bit-parallel-scalar32.cpp"
#include "popcnt-harley-seal.cpp"
#include "popcnt-builtin.cpp"

#if defined(HAVE_SSE_INSTRUCTIONS)
#   include "sse_operators.cpp"
#   include "sse/popcnt-sse-bit-parallel.cpp"
#   include "sse/popcnt-sse-bit-parallel-better.cpp"
#   include "sse/popcnt-sse-lookup.cpp"
#   include "sse/popcnt-sse-harley-seal.cpp"
#   include "sse/popcnt-sse-cpu.cpp"
#endif

#if defined(HAVE_AVX2_INSTRUCTIONS)
#   include "avx2/popcnt-avx2-lookup.cpp"
#   include "avx2/popcnt-avx2-harley-seal.cpp"
#   include "avx2/popcnt-avx2-cpu.cpp"
#endif

#if defined(HAVE_AVX512BW_INSTRUCTIONS)
#   include "avx512/popcnt-avx512-harley-seal.cpp"
#   include "avx512/popcnt-avx512bw-lookup.cpp"
#endif

#if defined(HAVE_AVX512VBMI_INSTRUCTIONS)
#   include "avx512vbmi/popcnt-avx512vbmi-lookup.cpp"
#endif