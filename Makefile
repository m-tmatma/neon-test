all: run_neon_test1 run_neon_test_select

neon_test1: neon_test1.c
	arm-linux-gnueabi-gcc-12 -mfpu=neon -mfloat-abi=softfp -std=c99 neon_test1.c -o neon_test1

neon_test_select: neon_test_select.c
	arm-linux-gnueabi-gcc-12 -mfpu=neon -mfloat-abi=softfp -std=c99 neon_test_select.c -o neon_test_select

run_neon_test1: neon_test1
	qemu-arm  -L /usr/arm-linux-gnueabi neon_test1

run_neon_test_select: neon_test_select
	qemu-arm  -L /usr/arm-linux-gnueabi neon_test_select
