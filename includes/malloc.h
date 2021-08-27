/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 09:29:55 by lgaultie          #+#    #+#             */
/*   Updated: 2021/08/27 13:16:46 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include "../libft/libft.h"
# include <stdio.h>
# include <sys/mman.h>
# include <stdbool.h>

# define SUCCESS	0
# define ERROR		-1
# define FAILURE	-2

typedef struct		s_block
{
	int				size;
	int				is_free; //0 no, 1 yes
	struct s_block	*next;
	// void			*data;
	// struct s_block	*prev;
}					t_block;

void	*ft_malloc(int size);
void	*create_new_block();
void	*find_space_in_heap(void *start, int size);
void	*place_in_heap(t_block *fitting_space, int size);

#endif