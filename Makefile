NAME		= libftprintf.a
HEAD		= ft_printf.h
COMPILER	= cc
CFLAGS		= -Wall -Wextra -Werror
LIB			= ar -rcs

SRCS		= ./ft_printf_main.c ./ft_printf_outs.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEAD)
	$(LIB) $(NAME) $(OBJS)

%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	
re: fclean all
