# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/05 12:24:50 by mtaquet      #+#   ##    ##    #+#        #
#    Updated: 2018/11/22 11:23:14 by mtaquet     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libftprintf.a
CONVDIR = converter/
SRCDIR = srcs/
INCDIR = includes/
CONVFILES =	ft_itoa.c\
			ft_itoa_base.c\
			ft_atoi.c\
			ft_dtoa.c\

SRCFILES =	utils.c\
			str.c\
			check.c\
			addother.c\
			addunsigned.c\
			addbonus.c\
			fill.c\
			treatlenth.c\
			$(addprefix $(CONVDIR),$(CONVFILES))\

INCFILES = printf.h
SRC = $(addprefix $(SRCDIR),$(SRCFILES)) ft_printf.c
INC = $(addprefix $(INCDIR),$(INCFILES))
OBJ = $(SRC:.c=.o)
FLAG = -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c $(INC)
	gcc -c -o $@ $< -I includes $(FLAG)

$(NAME): $(OBJ) $(INC)
	ar rc $@ $(OBJ)
	ranlib $@

clean:
	rm -f $(OBJ)


fclean: clean
	rm -f $(NAME)

re: fclean all
