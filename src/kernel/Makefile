BUILD ?= ./build

CC := x86_64-elf-gcc
LD := x86_64-elf-ld

KERNEL_SRC := .

.PHONY : all

all: build 

build:
	
$(BUILD)/%.o: $(KERNEL_SRC)/%.c
	@mkdir -p $(dir $@)
	$(CC) -o $@ $< -c $(CFLAGS) $(FEATURES) $(WARNINGS)

clean:

