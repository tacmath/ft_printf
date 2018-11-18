# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/05 12:24:50 by mtaquet      #+#   ##    ##    #+#        #
#    Updated: 2018/11/16 11:24:27 by mtaquet     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libftprintf.a
FLAG = -Wall -Werror -Wextra -I includes/
SRC = \
	  srcs/converter/ft_itoa.c\
	  srcs/converter/ft_itoa_base.c\
	  srcs/converter/ft_itoa_octal.c\
	  srcs/converter/ft_atoi.c\
	  srcs/converter/ft_dtoa.c\
	  srcs/utils.c\
	  srcs/str.c\
	  srcs/check.c\
	  srcs/addother.c\
	  srcs/addunsigned.c\
	  srcs/fill.c\
	  srcs/treatlenth.c\
	  ft_printf.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar sur $@ $^

%.o: %.c
	gcc -c -o $@ $< $(FLAG)

clean:
	rm -f $(OBJ)


fclean: clean
	rm -f $(NAME)

re: fclean all
