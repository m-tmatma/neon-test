all: run_neon_test1 run_neon_test_select
clean:
	rm -f neon_test1 neon_test_select
asm: neon_test1.S neon_test_select.S

CC=arm-linux-gnueabi-gcc-12 -mfpu=neon -mfloat-abi=softfp -std=c99
QENU=qemu-arm  -L /usr/arm-linux-gnueabi

neon_test1: neon_test1.c
	$(CC) neon_test1.c -o neon_test1

neon_test_select: neon_test_select.c
	$(CC) neon_test_select.c -o neon_test_select

neon_test1.S: neon_test1.c
	$(CC) -S neon_test1.c

neon_test_select.S: neon_test_select.c
	$(CC) -S neon_test_select.c

run_neon_test1: neon_test1
	$(QENU) neon_test1

run_neon_test_select: neon_test_select
	$(QENU) neon_test_select
