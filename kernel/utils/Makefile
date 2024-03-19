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

FILE =  $(foreach P, $(FUNCTION), $(shell find . -name "$(P)"))
OFILE = $(FILE:.cc=.o)

HEAD = libft.hpp

all:: $(TARGET) $(OFILE)

$(TARGET): $(OFILE)
	ar rc $(TARGET) $^

%.o : %.cc
	$(CC) $(CFLAGS) -I./../api/ -o $@ -c $<

clean::
	rm -f $(OFILE)

fclean:: clean
	rm -f $(TARGET)

re:: fclean all

.PHONY: all clean fclean run re