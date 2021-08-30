/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 09:29:55 by lgaultie          #+#    #+#             */
/*   Updated: 2021/08/30 20:23:10 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdio.h>
# include <sys/mman.h>
# include <stdbool.h>
# include <unistd.h> // for getpagesize

# define SUCCESS	0
# define ERROR		-1
# define FAILURE	-2
# define TINY		500
// # define SMALL		entre 500 et 4096
# define LARGE		4096

typedef struct		s_block
{
	int				size;
	int				is_free; //0 no, 1 yes
	struct s_block	*next;
	// void			*data;
	// struct s_block	*prev;
}					t_block;

void	*ft_malloc(size_t size);
// void	*free(void *ptr);
// void	*realloc(void *ptr, size_t size);
void	show_alloc_mem();
void	*create_new_block(t_block *start, size_t data_size);
void	*find_space_in_heap(void *start, int size);
void	*place_in_heap(t_block *fitting_space, int size);


#endif