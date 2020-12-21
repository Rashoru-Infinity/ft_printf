CC	=	gcc
CFLAGS	=	-Wall -Werror -Wextra
NAME	=	libftprintf.a
SRCS	=	ft_count_digit.c ft_charform.c ft_close.c ft_diform.c ft_hex.c ft_lowxform.c ft_pform.c ft_prcntform.c ft_printf.c ft_sethex.c ft_setnbr.c ft_strform.c ft_uform.c ft_upxform.c ft_zerocut.c ft_int_close.c ft_write.c 
OBJS	=	$(SRCS:.c=.o)
AR		=	ar
AFLAGS	=	rcs

all	:	$(NAME)

.c.o	:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS) libcreate
	$(AR) $(AFLAGS) $(NAME) $(OBJS)

libcreate	:
	$(MAKE) -C libft all
	cp libft/libft.a $(NAME)

clean	:
	$(RM) $(OBJS)
	$(MAKE) -C libft clean

fclean	:	clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re		:	fclean all

.PHONY	:	clean fclean all re
