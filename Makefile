NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror


SRC = main.c chunks_process.c sort_num.c sort.c sort_utils.c \
	ft_atoi.c instruction.c error.c rotate.c ft_split.c ft_substr.c \
	push_swap.c

OBJS = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FCLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME)

re: fclean all
.PHONY: all clean fclean re
