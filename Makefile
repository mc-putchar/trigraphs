NAME := cat
CC := cc
CFLAGS := -Wall -Wextra -Werror -trigraphs -pedantic

.PHONY: all clean fclean re help

all: $(NAME)		# Compiles all targets

$(NAME): $(NAME).o		# Compiles main target
	$(info Linking...)
	@$(CC) $(NAME).o -o $(NAME)
	$(info DONE!)

%.o: %.c		# Compiles %all requested %c files
	$(info Compiling...)
	@$(CC) $(CFLAGS) -w -c $^ -o $@

clean:		# Removes compiled object binaries
	$(info Cleaning up...)
	@$(RM) $(NAME).o

fclean: clean		# Removes this abomination
	$(info Proper cleaning this mess...)
	@$(RM) $(NAME) $(NAME).c Makefile

re: clean all		# Re-compiles all

# Colors
F := \x1b[1;35m
L := \x1b[0;36m
G := \x1b[0;0m
help:		# Here to help you
	$(info Here's a bit of help on this:)
	@awk 'BEGIN { \
	FS=":.*#"; printf "\t$(L)make $(F)<target>$(G)\nTargets:\n"; } \
	/^[a-zA-Z_0-9-]+:.*?#/ { \
	printf "$(F)%-16s$(L)%s$(G)\n", $$1, $$2 } ' Makefile
