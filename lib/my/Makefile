##
## EPITECH PROJECT, 2021
## mypoke
## File description:
## Makefile
##

SRC	=	my_putchar.c			\
		my_put_nbr.c			\
		my_putstr.c				\
		my_strlen.c				\
		my_put_nbr_base.c		\
		my_put_nbr_positive.c	\
		my_printf.c				\
		my_str_to_word_array.c	\
		my_strncpy.c			\
		my_strndup.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

a11:	$(NAME)

$(NAME):	$(OBJ)
	@echo -e "\e[40;1m----Lib maked----\e[0m"
	@ar rc  $(NAME) $(OBJ)
	@mkdir -p ../../include
	@cp libmy.a ../
	@cp my.h ../../include

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -f $(NAME)
