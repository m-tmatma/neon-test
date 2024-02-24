CC=arm-linux-gnueabi-gcc-12 -mfpu=neon -mfloat-abi=softfp -std=c99
QEMU=qemu-arm  -L /usr/arm-linux-gnueabi
TARGETS=neon_test1 neon_test_select neon_test_select_normal

all: $(addprefix run_, $(TARGETS))
clean:
	rm -f $(TARGETS) $(addsuffix .S, $(TARGETS))
asm: $(addsuffix .S, $(TARGETS))

$(TARGETS): %: %.c
	$(CC) $< -o $@

$(addsuffix .S, $(TARGETS)): %.S: %.c
	$(CC) -S $<

$(addprefix run_, $(TARGETS)): run_%: %
	$(QEMU) $<
