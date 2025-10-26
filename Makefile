## user input parameters
FEATURES ?=
TARGET ?= x86_64-w64-mingw32

## compilation parameters
SRC := src
INCLUDES := -Iinclude -I/usr/x86_64-w64-mingw32/include
ISODIR := iso
BUILD := build
DEPS := $(shell find $(SRC) -type f -name "*.c")
OBJS := $(patsubst $(SRC)/%.c,$(BUILD)/%.o,$(DEPS))
OBIN := kernel.efi

CC = clang
LD = lld-link

CFLAGS = --target=$(TARGET) -ffreestanding -O2 \
				 -Wall -Wextra \
				 -fshort-wchar \
				 -m64 \
				 -mno-red-zone \
				 $(INCLUDES) 

LDFLAGS = -subsystem:efi_application -entry:EfiMain

all: $(OBIN) $(ISODIR)

$(OBIN): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -out:$(OBIN)

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

$(BUILD)/%.o: $(SRC)/%.c
	@mkdir -p $(dir $@)
	$(CC) -o $@ $< -c $(CFLAGS) $(FEATURES) $(WARNINGS)

doc:
	git clone https://github.com/mrmonopoly-cyber/uefi_x86_64.wiki.git

setup: doc
	bear -- make

clean:
	rm -rf *.o *.elf $(ISODIR) *.iso $(ISODIR) $(BUILD)

clean-all: clean
	rm -rf ./compile_commands.json ./.cache ./uefi_x86_64.wiki

