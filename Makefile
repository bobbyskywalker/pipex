CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = pipex

SRCS = src/main.c src/fork_exec.c src/parse.c

OBJS = $(SRCS:.c=.o)
BOBJS = $(BONUS_SRCS:.c=.o)

LIBFT = lib/libft
LIBFT_LIB = $(LIBFT)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB)

$(LIBFT_LIB):
	make -C $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_LIB)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
