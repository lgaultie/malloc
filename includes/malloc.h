/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heylor <heylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:11:35 by heylor            #+#    #+#             */
/*   Updated: 2021/03/16 11:29:28 by heylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include "../libft/libft.h"
# include <stdio.h>
# include <sys/mman.h>
#include <stdbool.h>

# define SUCCESS	0
# define ERROR		-1
# define FAILURE	-2

typedef struct		s_heap
{
	int				total_size;
	int				free_block;
	int				nb_block;
	t_block			*blocks;
	struct s_heap	*prev;
	struct s_heap	*next;
}					t_heap;

typedef struct		s_block
{
	int				data_size;
	bool			freed;
	struct s_block	*prev;
	struct s_block	*next;
}					t_block;

void	*ft_malloc(int size);
void	*create_new_heap();
void	*can_find_space_in_heap(void *start, int size);
void	*place_in_heap(t_heap *heap, int size);

#endif