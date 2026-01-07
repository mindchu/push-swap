NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I $(INCLUDE_PATH)

SOURCE_PATH = srcs/
INCLUDE_PATH = includes/
BUILD_PATH  = build/

LIBFT_PATH  = ./lib/libft
GNL_PATH    = ./lib/get_next_line

LIBFT       = $(LIBFT_PATH)/libft.a
GNL         = $(GNL_PATH)/gnl.a

SRC_NAMES   = main.c \
              sub/subfile.c \
			  libsafealloc/safealloc.c
            #   parsing/parser.c

SOURCES     = $(addprefix $(SOURCE_PATH), $(SRC_NAMES))

OBJS        = $(SOURCES:$(SOURCE_PATH)%.c=$(BUILD_PATH)%.o)

all: $(NAME)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C $(LIBFT_PATH) bonus

$(GNL):
	@echo "Compiling get_next_line..."
	@make -C $(GNL_PATH)

$(NAME): $(LIBFT) $(GNL) $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL) -o $(NAME)
	@echo "$(NAME) build successful."

$(BUILD_PATH)%.o: $(SOURCE_PATH)%.c $(INCLUDE_PATH)/push_swap.h Makefile
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "Compiling: $(notdir $<)\n"

clean:
	@make -C $(LIBFT_PATH) clean -s
	@make -C $(GNL_PATH) clean -s
	@rm -rf $(BUILD_PATH)

fclean: clean
	@make -C $(LIBFT_PATH) fclean -s
	@make -C $(GNL_PATH) fclean -s
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re