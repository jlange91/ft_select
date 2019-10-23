C_FILES= \
	main.c \
	init_term.c \
	singleton.c \
	read.c \
	init_layout.c \
	init_params.c

C_FILES += $(foreach SUB_DIR,$(SUB_DIRS),$(addprefix $(SUB_DIR)/,$(C_FILES_$(SUB_DIR))))
