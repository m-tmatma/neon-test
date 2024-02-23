all: run_neon_test1 run_neon_test_select run_neon_test_select_normal
clean:
	rm -f neon_test1 neon_test_select
asm: neon_test1.S neon_test_select.S neon_test_select_normal.S

CC=arm-linux-gnueabi-gcc-12 -mfpu=neon -mfloat-abi=softfp -std=c99
QENU=qemu-arm  -L /usr/arm-linux-gnueabi

neon_test1: neon_test1.c
	$(CC) neon_test1.c -o neon_test1

neon_test_select: neon_test_select.c
	$(CC) neon_test_select.c -o neon_test_select

neon_test_select_normal: neon_test_select_normal.c
	$(CC) neon_test_select_normal.c -o neon_test_select_normal

neon_test1.S: neon_test1.c
	$(CC) -S neon_test1.c

neon_test_select.S: neon_test_select.c
	$(CC) -S neon_test_select.c

neon_test_select_normal.S: neon_test_select_normal.c
	$(CC) -S neon_test_select_normal.c

run_neon_test1: neon_test1
	$(QENU) neon_test1

run_neon_test_select: neon_test_select
	$(QENU) neon_test_select

run_neon_test_select_normal: neon_test_select_normal
	$(QENU) neon_test_select_normal
