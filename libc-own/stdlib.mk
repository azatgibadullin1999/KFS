SOURCE_FILES_NAMES += malloc$(SOURCE_C_EXT)

SOURCE_FILES +=	$(foreach P, $(SOURCE_FILES_NAMES), $(shell find . -name "$(P)"))
