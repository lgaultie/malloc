/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heylor <heylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:11:35 by heylor            #+#    #+#             */
/*   Updated: 2021/03/14 16:46:12 by heylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include "../libft/libft.h"
# include <stdio.h>
# include <sys/mman.h>

typedef struct		s_heap
{
	int				total_size;
	int				free_block;
	int				nb_block;
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

#endif