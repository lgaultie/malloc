# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heylor <heylor@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 21:15:02 by lgaultie          #+#    #+#              #
#    Updated: 2021/03/14 16:38:16 by heylor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
CC = @clang
SRCS =	ft_atoi.c			\
		ft_strlen.c			\
		ft_strcmp.c			\
		ft_strdup.c			\
		ft_strcpy.c			\
		ft_strncpy.c		\
		ft_memset.c			\
		ft_bzero.c			\
		ft_memcpy.c			\
		ft_memccpy.c		\
		ft_memmove.c		\
		ft_memchr.c			\
		ft_memcmp.c			\
		ft_strcat.c			\
		ft_strncat.c		\
		ft_strlcat.c		\
		ft_strchr.c			\
		ft_strrchr.c		\
		ft_strstr.c			\
		ft_strnstr.c		\
		ft_strncmp.c		\
		ft_isalpha.c		\
		ft_isdigit.c		\
		ft_isalnum.c		\
		ft_isascii.c		\
		ft_isprint.c		\
		ft_toupper.c		\
		ft_tolower.c		\
		ft_putchar.c		\
		ft_putstr.c			\
		ft_strclr.c			\
		ft_strnew.c			\
		ft_strequ.c			\
		ft_memalloc.c		\
		ft_memdel.c			\
		ft_strdel.c			\
		ft_striter.c		\
		ft_striteri.c		\
		ft_strmap.c			\
		ft_strmapi.c		\
		ft_strnequ.c		\
		ft_strsub.c			\
		ft_strjoin.c		\
		ft_strtrim.c		\
		ft_strsplit.c		\
		ft_putnbr.c			\
		ft_putendl.c		\
		ft_putchar_fd.c		\
		ft_putstr_fd.c		\
		ft_putendl_fd.c		\
		ft_putnbr_fd.c		\
		ft_itoa.c			\
		ft_lstnew.c			\
		ft_lstdelone.c		\
		ft_lstdel.c			\
		ft_lstadd.c			\
		ft_lstiter.c		\
		ft_lstmap.c			\
		ft_lstendadd.c		\
		ft_sqrt.c			\
		ft_strrealloc.c		\
		ft_lstprintstr.c	\
		ft_display_array.c	\
		ft_intlen.c			\
		ft_strndup.c

OBJ = $(SRCS:.c=.o)
HEADER = .

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRCS) -I$(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
