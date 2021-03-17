/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heylor <heylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:11:35 by heylor            #+#    #+#             */
/*   Updated: 2021/03/17 13:37:30 by heylor           ###   ########.fr       */
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

typedef struct		s_block
{
	int				size;
	bool			is_free;
	struct s_block	*next;
}					t_block;

void	*ft_malloc(int size);
void	*create_new_block();
void	*find_space_in_heap(void *start, int size);
void	*place_in_heap(t_block *fitting_space, int size);

#endif