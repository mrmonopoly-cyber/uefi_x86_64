## user input parameters
FEATURES ?=

## compilation parameters
SRC := src
EFI_BOOTSTRAP_SRC := $(SRC)/bootstrap
KERNEL_SRC := $(SRC)/kernel
BUILD := build
ISODIR := iso

INCLUDES := -Iinclude

EFI_BOOTSTRAP_OBIN := $(BUILD)/bootloader.efi

LDFLAGS = -subsystem:efi_application -entry:EfiMain

.PHONY: build 

build: $(EFI_BOOTSTRAP_OBIN)

run: $(EFI_BOOTSTRAP_OBIN)
	cp $(EFI_BOOTSTRAP_OBIN) $(ISODIR)/EFI/BOOT
	qemu-system-x86_64 \
	-net none \
	-bios /usr/share/ovmf/x64/OVMF.4m.fd \
	-drive format=raw,file=fat:rw:iso

doc:
	git clone https://github.com/mrmonopoly-cyber/uefi_x86_64.wiki.git

setup: 
	bear -- make build
	make doc

clean:
	rm -rf $(ISODIR) $(BUILD)

clean-all: clean
	rm -rf ./compile_commands.json ./.cache ./uefi_x86_64.wiki

include $(EFI_BOOTSTRAP_SRC)/Makefile
