C_FILES= \
	main.c \
	init_term.c \
	singleton.c \
	read.c \
	init_layout.c \
	init_params.c \
	calc_layout.c \
	print_args.c \
	arrow_actions.c \
	actions.c \
	tools.c \
	signals.c
	# delete.c

C_FILES += $(foreach SUB_DIR,$(SUB_DIRS),$(addprefix $(SUB_DIR)/,$(C_FILES_$(SUB_DIR))))
