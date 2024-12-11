NAME = push_swap
BONUS_NAME = checker

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c check_args.c find_cheaper.c ft_lstclear.c ft_split.c \
		is_cheaper.c max_min.c optimize_rotation_moves.c parse_args.c \
		rotate.c sort_more_than_three_nums.c sort_three_nbrs.c swap.c \
		utils_0.c utils_1.c utils_bonus.c check_and_perform_op.c push_pop.c

BONUS_SRCS = checker_bonus.c check_args.c check_and_perform_op.c rotate.c \
			swap.c push_pop.c utils_bonus.c get_next_line.c get_next_line_utils.c \
			ft_lstclear.c ft_split.c parse_args.c utils_0.c utils_1.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

$(BONUS_NAME) : $(BONUS_OBJS)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

bonus : $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all