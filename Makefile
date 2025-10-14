## user input parameters
FEATURES ?=
TARGET ?= x86_64-elf

## compilation parameters
SRC := src
ISODIR := iso
BUILD := build
DEPS := $(shell find $(SRC) -type f -name "*.S")
LD_SCRIPT := $(shell find $(SRC) -type f -name "*.ld")
OBJS := $(patsubst $(SRC)/%.S,$(BUILD)/%.o,$(DEPS))
OBIN := kernel.elf


CC = $(TARGET)-gcc
LD = $(TARGET)-ld

CFLAGS = -ffreestanding -O2 -Wall -Wextra -m64
LDFLAGS = -nostdlib -T $(LD_SCRIPT)



all: $(OBIN) $(ISODIR)

$(OBIN): $(OBJS) src/linker.ld
	$(LD) $(LDFLAGS) $(OBJS) -o $(OBIN)

$(ISODIR): $(OBIN) grub/grub.cfg
	mkdir -p $(ISODIR)/boot/grub
	cp $(OBIN) $(ISODIR)/boot/
	cp grub/grub.cfg $(ISODIR)/boot/grub/
	grub-mkrescue -o myos.$(ISODIR) $(ISODIR)

run: $(ISODIR)
	qemu-system-x86_64 \
	-net none \
	-bios /usr/share/ovmf/x64/OVMF.4m.fd \
	-cdrom myos.$(ISODIR)

$(BUILD)/%.o: $(SRC)/%.S
	@mkdir -p $(dir $@)
	$(CC) -o $@ $< -c $(CFLAGS) $(FEATURES) $(WARNINGS)


clean:
	rm -rf *.o *.elf $(ISODIR) *.iso $(ISODIR) $(BUILD)

