NAME	= libftprintf.a
#Implicit rules:
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

SRCS	= ft_printf_bonus.c conversion_util_bonus.c
BONUS	= ft_printf_bonus.c conversion_util_bonus.c
#Implicit compliation rule used here:
OBJS	= ${SRCS:.c=.o}
BONUS_O	= ${BONUS:.c=.o}

MAKELIB	= make -C libft/

all: $(NAME)

#cp copies across the libft.a file to the current directory 
$(NAME): ${OBJS}
	$(MAKELIB)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) ${OBJS}

bonus: all

clean:
	$(MAKELIB) clean
	rm -f ${OBJS}

fclean: clean
	$(MAKELIB) fclean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re