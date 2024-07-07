SOURCE_EXT =	.c
OBJECT_EXT =	.o
INCLUDE_EXT =	.h
OUT_EXT =	.a

SOURCE_FILES_NAMES =	malloc$(SOURCE_EXT)

SOURCE_FILES =	$(foreach P, $(SOURCE_FILES_NAMES), $(shell find . -name "$(P)"))
OBJECT_FILES =	$(SOURCE_FILES:$(SOURCE_EXT)=$(OBJECT_EXT))


# ifeq( $(HOSTTYPE), ) 
	# HOSTTYPE := $(shell uname -m)_$(shell uname -s)
# endif
# OUT_FILE = libft_malloc$(OUT_EXT)
OUT_FILE = stdlib$(OUT_EXT)

all: $(OUT_FILE)

# $(OUT_FILE): $(OBJECT_FILES)
# 	$(CC) -shared -fPIC -o $(OUT_FILE) $^

$(OUT_FILE): $(OBJECT_FILES)
	ar rc $(OUT_FILE) $^

%$(OBJECT_EXT): %$(SOURCE_EXT)
	$(CC) $(CFLAGS) -I./../../kernel/api -c -o $@ $<

clean:
	rm -rf $(OBJECT_FILES)

fclean: clean
	rm -rf $(OUT_FILE)

re: fclean all

.PHONY: all clean fclean re
