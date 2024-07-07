TARGET = libft.a

FUNCTION =	printf.cc \
		atoi.cc \
		itoa.cc \
		isalnum.cc \
		isalpha.cc \
		isascii.cc \
		isdigit.cc \
		isprint.cc \
		isspace.cc \
		memccpy.cc \
		memchr.cc \
		memcmp.cc \
		memcpy.cc \
		memmove.cc \
		memset.cc \
		bzero.cc \
		strchr.cc \
		strlcat.cc \
		strlcpy.cc \
		strlen.cc \
		strncmp.cc \
		strnstr.cc \
		strrchr.cc \
		tolower.cc \
		toupper.cc \
		malloc.cc \

STDLIB_DIR = stdlib
STDLIB = $(STDLIB_DIR)/stdlib.a

FILE =  $(foreach P, $(FUNCTION), $(shell find . -name "$(P)"))
OFILE = $(FILE:.cc=.o)

HEAD = libft.hpp

all:: $(TARGET) $(OFILE)

$(TARGET): $(OFILE) $(STDLIB)
	ar rcT $(TARGET) $(STDLIB) $^

%.o : %.cc
	$(CC) $(CFLAGS) -I./../kernel/api/ -o $@ -c $<

$(STDLIB):
	$(MAKE) --directory=$(STDLIB_DIR)

clean::
	rm -f $(OFILE)
	$(MAKE) --directory=$(STDLIB_DIR) clean

fclean:: clean
	rm -f $(TARGET)
	$(MAKE) --directory=$(STDLIB_DIR) fclean

re:: fclean all

.PHONY: all clean fclean run re