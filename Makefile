CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP
NAME = push_swap
INCLUDES = -I.
FT_PRINTF = ft_printf/libftprintf.a

SRCS = op_rotate.c \
	op_rev_rotate.c \
	op_push_swap.c \
	error_manager.c \
	sort_simple.c \
	sort_chunks.c \
	sort_radix.c \
	sort_init.c \
	stacks.c \
	stacks_utils.c \
	push_swap.c \
	utils.c \
	parsing.c

OBJ_DIR = objs/
OBJS =$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEP = $(OBJS:.o=.d)

all: $(NAME)

$(FT_PRINTF):
	make -C ft_printf/ all bonus

$(NAME): $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(FT_PRINTF) -o $@

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(OBJ_DIR_BONUS)
	rm -f .bonus
	rm -f $(GNL_OBJS)
	rm -f $(GNL_DEPS)
	make -C ft_printf/ clean
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	make -C ft_printf/ fclean
	make -C libft/ fclean

re: fclean all

NAME_BONUS = checker
LIBFT = libft/libft.a
GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 
GNL_OBJS = $(GNL:.c=.o)
GNL_DEPS = $(GNL_OBJS:.o=.d)
INCLUDES_BONUS = -I bonus -I get_next_line
SRCS_BONUS = bonus/checker_bonus.c \
	bonus/error_bonus.c \
	bonus/op_push_swap_bonus.c \
	bonus/op_rev_rotate_bonus.c \
	bonus/op_rotate_bonus.c \
	bonus/parsing_bonus.c \
	bonus/stacks_bonus.c \
	bonus/stacks_utils_bonus.c \
	bonus/utils_bonus.c

OBJ_DIR_BONUS = bonus/objs/
OBJS_BONUS = $(subst bonus/,$(OBJ_DIR_BONUS),$(SRCS_BONUS:.c=.o))
DEP_BONUS = $(OBJS_BONUS:.o=.d)

$(LIBFT):
	make -C libft/ all bonus

$(OBJ_DIR_BONUS)%.o: bonus/%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) $(INCLUDES_BONUS) -c $< -o $@

get_next_line/%.o: get_next_line/%.c
	$(CC) $(CFLAGS) -I get_next_line -c $< -o $@

bonus: .bonus

.bonus: $(LIBFT) $(GNL_OBJS) $(OBJS_BONUS)
	@touch .bonus
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(GNL_OBJS) $(INCLUDES_BONUS) $(LIBFT) -o $(NAME_BONUS)

.PHONY: all clean fclean re bonus

-include $(DEP) $(DEP_BONUS) $(GNL_DEPS)
