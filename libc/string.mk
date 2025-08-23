SOURCE_FILES_NAMES += \
		atoi$(SOURCE_C_EXT) \
		itoa$(SOURCE_C_EXT) \
		isalnum$(SOURCE_C_EXT) \
		isalpha$(SOURCE_C_EXT) \
		isascii$(SOURCE_C_EXT) \
		isdigit$(SOURCE_C_EXT) \
		isprint$(SOURCE_C_EXT) \
		isspace$(SOURCE_C_EXT) \
		memccpy$(SOURCE_C_EXT) \
		memchr$(SOURCE_C_EXT) \
		memcmp$(SOURCE_C_EXT) \
		memcpy$(SOURCE_C_EXT) \
		memmove$(SOURCE_C_EXT) \
		memset$(SOURCE_C_EXT) \
		bzero$(SOURCE_C_EXT) \
		strchr$(SOURCE_C_EXT) \
		strlcat$(SOURCE_C_EXT) \
		strlcpy$(SOURCE_C_EXT) \
		strlen$(SOURCE_C_EXT) \
		strncmp$(SOURCE_C_EXT) \
		strnstr$(SOURCE_C_EXT) \
		strrchr$(SOURCE_C_EXT) \
		tolower$(SOURCE_C_EXT) \
		toupper$(SOURCE_C_EXT) \

SOURCE_FILES +=	$(foreach P, $(SOURCE_FILES_NAMES), $(shell find ./string/ -name "$(P)"))
