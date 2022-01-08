NAME	= libftprintf.a
#Implicit rules:
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

SRCS	= ft_printf.c conversions_pdiuxX.c
BONUS	= ft_printf_bonus.c conversion_util_bonus.c conversions_csp_bonus.c conversions_diuxX_bonus.c
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

bonus: ${BONUS_O}
	$(MAKELIB)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) ${OBJS}

clean:
	$(MAKELIB) clean
	rm -f ${OBJS}
	rm -f ${BONUS_O}

fclean: clean
	$(MAKELIB) fclean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re