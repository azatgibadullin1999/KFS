CC = i686-elf-g++
ASM = i686-elf-as
CFLAGS =	-O0 \
		-g \
		-std=c++17 \
		-fno-builtin \
		-fno-exceptions \
		-fno-stack-protector \
		-fno-rtti \
		-fno-threadsafe-statics \
		-ffreestanding \
		-nostdlib \
		-nodefaultlibs \
		-Wall \
		-Wextra

export CC
export ASM
export CFLAGS

NAME = kfs
ISO = $(NAME).iso
GRUB_FILE = grub/grub.cfg
LIBFT_DIR = kernel/utils
# LIBFT_MK = libft.mk
LIBFT = $(LIBFT_DIR)/libft.a

LIBRARYS += $(LIBFT_DIR)

SOURCE_CPP_EXT = .cc
SOURCE_ASM_EXT = .S
LINKER_SCRIPT_EXT = .ld
OBJECT_EXT = .o
INCLUDE_EXT = .hpp

SOURCE_ASM_NAME = boot$(SOURCE_ASM_EXT)

SOURCE_CPP_NAME =	kernel_main$(SOURCE_CPP_EXT) \
			global_variable_support$(SOURCE_CPP_EXT) \
			keyboard$(SOURCE_CPP_EXT) \
			text_display$(SOURCE_CPP_EXT) \
			port$(SOURCE_CPP_EXT) \
			console$(SOURCE_CPP_EXT) \
			usqwerty$(SOURCE_CPP_EXT) \
			command_text_display$(SOURCE_CPP_EXT) \
			command_default$(SOURCE_CPP_EXT) \
			command_default_auto_scroll$(SOURCE_CPP_EXT) \
			command_press_newline_auto_scroll$(SOURCE_CPP_EXT) \
			command_press_backspace$(SOURCE_CPP_EXT) \
			command_press_newline$(SOURCE_CPP_EXT) \
			command_press_scroll$(SOURCE_CPP_EXT) \
			command_press_tab$(SOURCE_CPP_EXT) \
			write$(SOURCE_CPP_EXT) \
			gdt_default$(SOURCE_CPP_EXT) \
			shell$(SOURCE_CPP_EXT)

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
	$(CC) $(CFLAGS) -I./kernel/ -I./kernel/api -c -o $@ $<

$(LIBFT):
	$(MAKE) --directory=$(LIBFT_DIR)

clean::
	@rm -rf $(OBJECT_FILES)
	@rm -rf $(ISO_BUILD_DIR)
	$(MAKE) --directory=$(LIBFT_DIR) clean

fclean:: clean
	@rm -rf $(NAME)
	@rm -rf $(ISO)
	@rm -rf $(LIBFT)
	$(MAKE) --directory=$(LIBFT_DIR) fclean

run:
	@qemu-system-i386 -cdrom $(ISO)

re:: fclean all

.PHONY: all clean fclean run re