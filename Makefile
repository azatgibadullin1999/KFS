CC = i686-elf-g++
ASM = i686-elf-as
CFLAGS =	-O0 \
		-g \
		-std=c++17 \
		-Wall \
		-Wextra \
		-Werror \
		-fno-builtin \
		-fno-exceptions \
		-fno-stack-protector \
		-fno-rtti \
		-fno-threadsafe-statics \
		-ffreestanding \
		-nostdlib \
		-nodefaultlibs

export CC
export ASM
export CFLAGS

NAME = kfs
ISO = $(NAME).iso
GRUB_FILE = grub/grub.cfg
LIBFT_DIR = kernel/utils
LIBFT_MK = libft.mk
LIBFT = libft.a

SOURCE_CPP_EXT = .cc
SOURCE_ASM_EXT = .S
LINKER_SCRIPT_EXT = .ld
OBJECT_EXT = .o
INCLUDE_EXT = .hpp

SOURCE_ASM_NAME = boot$(SOURCE_ASM_EXT)

SOURCE_CPP_NAME =	kernel_main$(SOURCE_CPP_EXT) \
			keyboard$(SOURCE_CPP_EXT) \
			textmode$(SOURCE_CPP_EXT) \
			port$(SOURCE_CPP_EXT) \
			console$(SOURCE_CPP_EXT) \
			usqwerty$(SOURCE_CPP_EXT) \
			specialsymbolprocessor$(SOURCE_CPP_EXT)

LINKER_SCRIPT_NAME = linker$(LINKER_SCRIPT_EXT)


SOURCE_ASM_FILES = $(foreach P, $(SOURCE_ASM_NAME), $(shell find . -name "$(P)"))
SOURCE_CPP_FILES = $(foreach P, $(SOURCE_CPP_NAME), $(shell find . -name "$(P)"))
LINKER_SCRIPT_FILES = $(foreach P, $(LINKER_SCRIPT_NAME), $(shell find . -name "$(P)"))

OBJECT_FILES =	$(SOURCE_ASM_FILES:$(SOURCE_ASM_EXT)=$(OBJECT_EXT)) \
		$(SOURCE_CPP_FILES:$(SOURCE_CPP_EXT)=$(OBJECT_EXT))

ISO_BUILD_DIR = root


all:: $(ISO)

$(ISO): $(NAME)
	@grub-file --is-x86-multiboot $(NAME)
	@mkdir -pv $(ISO_BUILD_DIR)/boot/grub
	@cp $(NAME) $(ISO_BUILD_DIR)/boot
	@cp $(GRUB_FILE) $(ISO_BUILD_DIR)/boot/grub
	@grub-mkrescue -o $(ISO) $(ISO_BUILD_DIR)

$(NAME): $(OBJECT_FILES) $(LIBFT)
	$(CC) -T $(LINKER_SCRIPT_FILES) -o $(NAME) -ffreestanding -nostdlib $^ $(LIBFT) -lgcc

%$(OBJECT_EXT): %$(SOURCE_ASM_EXT)
	$(ASM) $< -o $@

%$(OBJECT_EXT): %$(SOURCE_CPP_EXT)
	$(CC) $(CFLAGS) -c -o $@ $<

clean::
	@rm -rf $(OBJECT_FILES)
	@rm -rf $(ISO_BUILD_DIR)

fclean:: clean
	@rm -rf $(NAME)
	@rm -rf $(ISO)
	@rm -rf $(LIBFT)

run:
	@qemu-system-i386 -cdrom $(ISO)

re:: fclean all

include $(LIBFT_DIR)/$(LIBFT_MK)

.PHONY: all clean fclean run re