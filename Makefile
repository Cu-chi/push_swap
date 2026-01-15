CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP
NAME = push_swap
INCLUDES = -I.
FT_PRINTF = ft_printf/libftprintf.a

SRCS = ps_language_r.c \
	ps_language_rr.c \
	ps_language_sp.c \
	preprocess.c \
	simple.c \
	medium.c \
	complex.c \
	stacks_utils.c \
	stacks.c \
	push_swap.c \
	utils.c

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
	make -C ft_printf/ clean

fclean: clean
	rm -f $(NAME)
	make -C ft_printf/ fclean

re: fclean all

bonus:
	echo TODO

.PHONY: all clean fclean re bonus

-include $(DEP)
