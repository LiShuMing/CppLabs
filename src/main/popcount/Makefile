


COMPILER=$(notdir $(CXX))
FLAGS=-std=c++11 -O2 -Wall -pedantic -Wextra -Wfatal-errors
FLAGS_INTEL=$(FLAGS) -mpopcnt -fabi-version=6
FLAGS_ARM=$(FLAGS) -mfpu=neon -DHAVE_NEON_INSTRUCTIONS
# It seems that for AArch64 no extra flags are needed (NEON is always available)
FLAGS_AARCH64=$(FLAGS) -DHAVE_NEON_INSTRUCTIONS -DHAVE_AARCH64_ARCHITECTURE

FLAGS_SSE=$(FLAGS_INTEL) -mssse3 -DHAVE_SSE_INSTRUCTIONS
FLAGS_AVX=$(FLAGS_INTEL) -mavx -DHAVE_AVX_INSTRUCTIONS
FLAGS_AVX2=$(FLAGS_INTEL) -mavx2 -DHAVE_AVX2_INSTRUCTIONS
FLAGS_AVX512BW=$(FLAGS_INTEL) -mavx512bw -DHAVE_AVX512BW_INSTRUCTIONS
FLAGS_AVX512VBMI=$(FLAGS_INTEL) -mavx512vbmi -DHAVE_AVX512BW_INSTRUCTIONS -DHAVE_AVX512VBMI_INSTRUCTIONS
FLAGS_AVX512VPOPCNT=$(FLAGS_INTEL) -mavx512bw -mavx512vpopcntdq -DHAVE_AVX512VPOPCNT_INSTRUCTIONS

DEPS=popcnt-*.cpp function_registry.cpp sse_operators.cpp config.h
ALL=speed_$(COMPILER) verify_$(COMPILER)
ALL_AVX=speed_avx_$(COMPILER) verify_avx_$(COMPILER)
ALL_AVX2=speed_avx2_$(COMPILER) verify_avx2_$(COMPILER)
ALL_AVX512BW=speed_avx512bw_$(COMPILER) verify_avx512bw_$(COMPILER)
ALL_AVX512VBMI=speed_avx512vbmi_$(COMPILER) verify_avx512vbmi_$(COMPILER)
ALL_AVX512VPOPCNT=verify_avx512vpopcnt_$(COMPILER)
ALL_ARM=speed_arm_$(COMPILER) verify_arm_$(COMPILER)
ALL_AARCH64=speed_aarch64_$(COMPILER) verify_aarch64_$(COMPILER)
ALL_TARGETS=$(ALL) $(ALL_AVX) $(ALL_AVX2) $(ALL_AVX512) $(ALL_AVX512BW) $(ALL_AVX512VPOPCNT)

SIZE=10000000
ITERS=100

#### ALIAS
speed: speed_$(COMPILER)
speed_avx: speed_avx_$(COMPILER)
speed_avx2: speed_avx2_$(COMPILER)
speed_avx512bw: speed_avx512bw_$(COMPILER)
speed_avx512vbmi: speed_avx512vbmi_$(COMPILER)
speed_arm: speed_arm_$(COMPILER)
speed_aarch64: speed_aarch64_$(COMPILER)

verify: verify_$(COMPILER)
verify_avx: verify_avx_$(COMPILER)
verify_avx2: verify_avx2_$(COMPILER)
verify_avx512bw: verify_avx512bw_$(COMPILER)
verify_avx512vbmi: verify_avx512vbmi_$(COMPILER)
verify_arm: verify_arm_$(COMPILER)
verify_aarch64: verify_aarch64_$(COMPILER)

##### AVX
avx: $(ALL_AVX)

run_avx: speed_avx
	./speed_avx_$(COMPILER) $(SIZE) $(ITERS)

speed_avx_$(COMPILER): $(DEPS) speed.cpp
	$(CXX) $(FLAGS_AVX) speed.cpp -o $@

verify_avx_$(COMPILER): $(DEPS) verify.cpp
	$(CXX) $(FLAGS_AVX) verify.cpp -o $@

##### AVX2
avx2: $(ALL_AVX2)

run_avx2: speed_avx2
	./speed_avx2_$(COMPILER) $(SIZE) $(ITERS)

speed_avx2_$(COMPILER): $(DEPS) speed.cpp
	$(CXX) $(FLAGS_AVX2) speed.cpp -o $@

verify_avx2_$(COMPILER): $(DEPS) verify.cpp
	$(CXX) $(FLAGS_AVX2) verify.cpp -o $@


run_avx512bw: speed_avx512bw
	./speed_avx512bw_$(COMPILER) $(SIZE) $(ITERS)

##### AVX512
avx512bw: $(ALL_AVX512BW)

speed_avx512bw_$(COMPILER): $(DEPS) speed.cpp
	$(CXX) $(FLAGS_AVX512BW) speed.cpp -o $@

verify_avx512bw_$(COMPILER): $(DEPS) verify.cpp
	$(CXX) $(FLAGS_AVX512BW) verify.cpp -o $@

run_avx512bw: speed_avx512bw
	./speed_avx512bw_$(COMPILER) $(SIZE) $(ITERS)

run_verify_avx512bw: verify_avx512bw_$(COMPILER)
	./$^

##### avx512vbmi
avx512vbmi: $(ALL_AVX512VBMI)

speed_avx512vbmi_$(COMPILER): $(DEPS) speed.cpp
	$(CXX) $(FLAGS_AVX512VBMI) speed.cpp -o $@

verify_avx512vbmi_$(COMPILER): $(DEPS) verify.cpp
	$(CXX) $(FLAGS_AVX512VBMI) verify.cpp -o $@

run_avx512vbmi: speed_avx512vbmi
	./speed_avx512vbmi_$(COMPILER) $(SIZE) $(ITERS)

run_verify_avx512vbmi: verify_avx512vbmi_$(COMPILER)
	./$^