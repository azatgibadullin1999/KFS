TARGET = libc.a

SOURCE_FILES :=

include ./stdio.mk
include ./stdlib.mk
include ./string.mk

OBJECT_FILES =	$(SOURCE_FILES:$(SOURCE_C_EXT)=$(OBJECT_EXT))

all:: $(TARGET)

$(TARGET): $(OBJECT_FILES)
	ar rcT $(TARGET) $^

%$(OBJECT_EXT) : %$(SOURCE_C_EXT)
	$(CC) $(CFLAGS) -I./ -I./../kernel/api/ -o $@ -c $<

clean::
	rm -f $(OBJECT_FILES)

fclean:: clean
	rm -f $(TARGET)

re:: fclean all

.PHONY: all clean fclean run re