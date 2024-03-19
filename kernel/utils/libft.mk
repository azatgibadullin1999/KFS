TARGET = libft.a

FUNCTION =	ft_printf.c \
		ft_atoi.c \
		ft_itoa.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_bzero.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \

FILE =  $(foreach P, $(FUNCTION), $(shell find . -name "$(P)"))
OFILE = $(FILE:.c=.o)

HEAD = libft.h

all:: $(TARGET) $(OFILE)

$(TARGET): $(OFILE)
	ar rc $(TARGET) $^

%.o : %.c
	$(CC) $(CFLAGS) -Wall -Wextra -Werror -o $@ -c $<

clean::
	rm -f $(OFILE)

fclean:: clean
	rm -f $(TARGET)

re:: fclean all

.PHONY: all clean fclean run re