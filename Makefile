.PHONY: all clean boot

NASM := nasm -f elf64

BUILD_DIR := build
SRC_DIR := src

CC := gcc
CFLAGS := -std=c99 -ffreestanding -m64 -mno-red-zone -fno-builtin -nostdinc -Wall -Wextra

SRC := $(wildcard $(SRC_DIR)/*)
OBJS := $(patsubst $(SRC_DIR)/%, $(BUILD_DIR)/%.o, $(SRC))

BOOT_IMAGE := $(BUILD_DIR)/boot_image

all: $(BOOT_IMAGE)

boot: $(BOOT_IMAGE)
	qemu-system-x86_64 -no-reboot -drive file=$<,format=raw,index=0,media=disk

$(BOOT_IMAGE): $(BUILD_DIR)/linked.o
	objcopy -O binary $< $@

$(BUILD_DIR)/linked.o: $(OBJS)
	ld -T linker.ld -o $@ $^

$(BUILD_DIR)/%.asm.o: $(SRC_DIR)/%.asm
	@mkdir -p "$(dir $@)"
	$(NASM) $< -o $@
	
$(BUILD_DIR)/%.c.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BUILD_DIR)