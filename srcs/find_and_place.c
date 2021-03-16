/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heylor <heylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 09:34:46 by heylor            #+#    #+#             */
/*   Updated: 2021/03/16 22:39:06 by heylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

/*
** can_find_space_in_heap(): returns the pointer to the heap which has place,
** or null if he can't find place.
*/

void *find_space_in_heap(void *start, int size)
{
    t_block *tmp;

    tmp = start;
    if (tmp != NULL)
    {
        printf("%s: %d && %s: %d\n", "size of block", size, "tmp->total_size: ", tmp->total_size);
        while (tmp->next != NULL)
        {
            if (tmp->free == 1 && tmp->total_size >= size)
                return (tmp);
            tmp = tmp->next;
        }
    }
    return (NULL);
}

/*
** place_in_heap(): split the heap to create new area for block,
** returns the pointer to the allocated area.
** https://stackoverflow.com/questions/49999524/recoding-malloc-with-mmap-strange-segfault
*/

void *place_in_heap(t_block *fitting_space, int size)
{
    t_block *new;

    if (fitting_space != NULL)
    {
        ft_putstr("fitting_space exists\n");
        // TODO place block in fitting_space
    }
    return fitting_space;
}