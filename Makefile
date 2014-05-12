# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/26 13:13:47 by rbenjami          #+#    #+#              #
#    Updated: 2014/05/08 14:13:13 by dsousa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include		libft/Makefile.sources

export	CC		=	clang

export	INC		=	-I $(PWD)/libft

NAME		=	philo

CFLAGS	= -Wall -Wextra -Werror -g

INC			+=	-I includes

INC_DIR		=	includes/

INC_FILES	=	$(NAME).h\
				struct.h

INC_SRC			=	$(addprefix $(INC_DIR), $(INC_FILES))

SRC_DIR		=	srcs/

FILES		=	$(NAME).c \
				action.c \
				pv.c \
				thread.c

SRC			=	$(addprefix $(SRC_DIR), $(FILES))

OBJ			=	$(SRC:.c=.o)

LIB			=	-L./ -lft -ltermcap

OBJ_LIB		=	$(libft/SRC_LIB:.c=.o)

HEAD_LIB	=	libft/libft.h

all:			libft.a $(NAME)

libft.a:		libft/$(OBJ_LIB) $(HEAD_LIB)
	@make -C libft

$(NAME):		$(OBJ)
	@$(CC) $(CFLAGS) -ltermcap -o $(NAME) $(OBJ) $(LIB)
	@echo ""
	@echo "\033[33m"compilation of $(NAME) : "\033[32m"Success"\033[0m"

$(OBJ):			$(INC_SRC) libft.a

%.o:			%.c $(INC_SRC)
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[31m"Objects of $(NAME) : deleted"\033[0m"

fclean:			clean
	@/bin/rm -f $(NAME)
	@echo "\033[31m"$(NAME) : deleted"\033[0m"
	@make fclean -C libft
re:				fclean all

.PHONY:			all clean fclean re
