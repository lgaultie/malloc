# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/26 15:38:56 by lgaultie          #+#    #+#              #
#    Updated: 2021/08/27 16:52:44 by lgaultie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
LINK = libft_malloc.so
CFLAGS = -Wall -Werror -Wextra -g3 #TO DO to g3 to remove (its for valgrind)
CC = @clang
SRCS = malloc.c				\
		create_block.c		\
		find_and_place.c
OBJ = $(SRCS:.c=.o)
INC = ./includes/

all: $(NAME)
	@printf "$(_CYAN)  _                   _ _   _      _                         _ _  \n"            
	@printf "$(_CYAN) | |                 | | | (_)    | |                       | | |           \n"
	@printf "$(_CYAN) | | __ _  __ _ _   _| | |_ _  ___|/  ___    _ __ ___   __ _| | | ___   ___  \n"
	@printf "$(_CYAN) | |/ _' |/ _' | | | | | __| |/ _ \  / __|  | '_ ' _ \ / _' | | |/ _ \ / __| \n"
	@printf "$(_CYAN) | | (_| | (_| | |_| | | |_| |  __/  \__ \  | | | | | | (_| | | | (_) | (__  \n"
	@printf "$(_CYAN) |_|\__, |\__,_|\__,_|_|\__|_|\___|  |___/  |_| |_| |_|\__,_|_|_|\___/ \___| \n"
	@printf "$(_CYAN)     __/ |                                                                 \n"
	@printf "$(_CYAN)    |___/                                                                 \n$(_END)"


$(NAME):
	@printf "Creating .o ...\n"
	@$(CC) $(CFLAGS) -c $(SRCS) -I$(INC)
	@printf "Creating static library...\n"
	@ar rcs $(NAME) $(OBJ)
	@printf "Creating symlink...\n"
	@ln -s $(NAME) $(LINK)
# s permet de lancer ranlib
clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LINK)

re: fclean all

.PHONY: all re fclean clean

# NAME = malloc
# CC = @clang
# CFLAGS = -Wall -Werror -Wextra -g3 #TO DO to g3 to remove (its for valgrind)
# OBJDIR = obj
# SRCDIR = srcs
# INC = ./includes/

# SRCS =	malloc.c			\
# 		create_block.c		\
# 		find_and_place.c	\
# 		main.c #TO DO REMOVE

# OBJ = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
# #voir GNU 8.3 Functions for File Names

# _GREEN=\e[32m
# _PURPLE=\e[35m
# _BLUE=\e[34m
# _YELLOW=\e[33m
# _CYAN=\e[36m
# _RED=\e[31m
# _END=\e[0m

# all: $(NAME)
# 	@printf "$(_CYAN)  _                   _ _   _      _                         _ _  \n"            
# 	@printf "$(_CYAN) | |                 | | | (_)    | |                       | | |           \n"
# 	@printf "$(_CYAN) | | __ _  __ _ _   _| | |_ _  ___|/  ___    _ __ ___   __ _| | | ___   ___  \n"
# 	@printf "$(_CYAN) | |/ _' |/ _' | | | | | __| |/ _ \  / __|  | '_ ' _ \ / _' | | |/ _ \ / __| \n"
# 	@printf "$(_CYAN) | | (_| | (_| | |_| | | |_| |  __/  \__ \  | | | | | | (_| | | | (_) | (__  \n"
# 	@printf "$(_CYAN) |_|\__, |\__,_|\__,_|_|\__|_|\___|  |___/  |_| |_| |_|\__,_|_|_|\___/ \___| \n"
# 	@printf "$(_CYAN)     __/ |                                                                 \n"
# 	@printf "$(_CYAN)    |___/                                                                 \n$(_END)"

# $(NAME): $(OBJ)
# 	@printf "$(_YELLOW)Compilation...$(_END)"
# 	@$(CC) $(CFLAGS) $(OBJ) -I$(INC) -o $(NAME)
# 	@printf "$(_GREEN) malloc done [✓]$(_END)\n"

# $(OBJDIR)/%.o: $(SRCDIR)/%.c includes/malloc.h
# 	@$(CC) $(CFLAGS) -c -I$(INC) $< -o $@

# $(OBJDIR) :
# 	@printf "$(_YELLOW)Creating $(_PURPLE)Malloc$(_YELLOW) obj folder... $(_END)"
# 	@mkdir $@
# 	@printf "$(_CYAN)done$(_END)\n"

# $(OBJ) : | $(OBJDIR)
# #voir GNU make 4.3 Types of Prerequisites

# clean:
# 	@printf "$(_YELLOW)clean... $(_END)"
# 	@rm -rf $(OBJDIR)
# 	@printf "$(_CYAN)done$(_END)\n"

# fclean: clean
# 	@printf "$(_YELLOW)fclean... $(_END)"
# 	@rm -rf $(NAME)
# 	@printf "$(_CYAN)done $(_END)\n"

# re: fclean all clean

# .PHONY: clean fclean all re