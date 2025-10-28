## user input parameters
FEATURES ?=
BUILD ?= build
INCLUDES += -I../../include
INCLUDES += -I/usr/x86_64-w64-mingw32/include
BOOTSTRAP_OBIN ?= $(BUILD)/bootloader.efi

## compilation parameters
TARGET := x86_64-w64-mingw32
EFI_BOOTSTRAP_SRC := .
DEPS := $(shell find $(EFI_BOOTSTRAP_SRC) -type f -name "*.c")
EFI_BOOTSTRAP_OBJS := $(patsubst $(EFI_BOOTSTRAP_SRC)/%.c,$(BUILD)/%.o,$(DEPS))

CC = clang
LD = lld-link

CFLAGS = --target=$(TARGET) -ffreestanding -O2 \
				 -Wall -Wextra \
				 -fshort-wchar \
				 -m64 \
				 -mno-red-zone \
				 $(INCLUDES) 

LDFLAGS = -subsystem:efi_application -entry:EfiMain

all: $(BOOTSTRAP_OBIN)

$(BOOTSTRAP_OBIN): $(EFI_BOOTSTRAP_OBJS)
	$(LD) $(LDFLAGS) $(EFI_BOOTSTRAP_OBJS) -out:$(BOOTSTRAP_OBIN)

$(BUILD)/%.o: $(EFI_BOOTSTRAP_SRC)/%.c
	@mkdir -p $(dir $@)
	$(CC) -o $@ $< -c $(CFLAGS) $(FEATURES) $(WARNINGS)

clean_bootstrap:
	rm -rf $(BUILD)

clean: clean_bootstrap
