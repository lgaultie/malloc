# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heylor <heylor@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/14 16:24:16 by heylor            #+#    #+#              #
#    Updated: 2021/03/16 10:02:58 by heylor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = malloc
CC = @clang
CFLAGS = -Wall -Werror -Wextra
LIBDIR = libft
LIB = $(LIBDIR)/libft.a
OBJDIR = obj
SRCDIR = srcs
INC = ./includes/

SRCS =	malloc.c			\
		create_heap.c		\
		find_and_place.c	\
		main.c #TO REMOVE

OBJ = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
#voir GNU 8.3 Functions for File Names

_GREEN=\e[32m
_PURPLE=\e[35m
_BLUE=\e[34m
_YELLOW=\e[33m
_CYAN=\e[36m
_RED=\e[31m
_END=\e[0m

all: $(NAME)
	@printf "$(_CYAN)  _                   _ _   _      _                         _ _  \n"            
	@printf "$(_CYAN) | |                 | | | (_)    | |                       | | |           \n"
	@printf "$(_CYAN) | | __ _  __ _ _   _| | |_ _  ___|/  ___    _ __ ___   __ _| | | ___   ___  \n"
	@printf "$(_CYAN) | |/ _' |/ _' | | | | | __| |/ _ \  / __|  | '_ ' _ \ / _' | | |/ _ \ / __| \n"
	@printf "$(_CYAN) | | (_| | (_| | |_| | | |_| |  __/  \__ \  | | | | | | (_| | | | (_) | (__  \n"
	@printf "$(_CYAN) |_|\__, |\__,_|\__,_|_|\__|_|\___|  |___/  |_| |_| |_|\__,_|_|_|\___/ \___| \n"
	@printf "$(_CYAN)     __/ |                                                                 \n"
	@printf "$(_CYAN)    |___/                                                                 \n$(_END)"

$(NAME): $(OBJ)
	@printf "$(_YELLOW)Compiling libft... $(_END)"
	@make -C $(LIBDIR)
	@printf "$(_CYAN)done$(_END)\n"
	@printf "$(_YELLOW)Compilation...$(_END)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -I$(INC) -o $(NAME)
	@printf "$(_GREEN) malloc done [✓]$(_END)\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.c includes/malloc.h
	@$(CC) $(CFLAGS) -c -I$(INC) $< -o $@

$(OBJDIR) :
	@printf "$(_YELLOW)Creating $(_PURPLE)Malloc$(_YELLOW) obj folder... $(_END)"
	@mkdir $@
	@printf "$(_CYAN)done$(_END)\n"

$(OBJ) : | $(OBJDIR)
#voir GNU make 4.3 Types of Prerequisites

clean:
	@printf "$(_YELLOW)clean... $(_END)"
	@cd $(LIBDIR) && make clean
	@rm -rf $(OBJDIR)
	@printf "$(_CYAN)done$(_END)\n"

fclean: clean
	@printf "$(_YELLOW)fclean... $(_END)"
	@cd $(LIBDIR) && make fclean
	@rm -rf $(NAME)
	@printf "$(_CYAN)done $(_END)\n"

re: fclean all clean

.PHONY: clean fclean all re