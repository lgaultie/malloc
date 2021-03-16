/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heylor <heylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 09:34:46 by heylor            #+#    #+#             */
/*   Updated: 2021/03/16 11:27:39 by heylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

/*
** can_find_space_in_heap(): returns the pointer to the heap which has place,
** or null if he can't find place.
*/

void *can_find_space_in_heap(void *start, int size)
{
    t_heap *tmp;

    tmp = start;
    if (tmp != NULL)
    {
        printf("%s: %d && %s: %d\n", "size of block", size, "tmp->total_size: ", tmp->total_size);
        if (tmp->total_size >= size)
            return (tmp);
        else
        {
            while (tmp->next != NULL)
            {
                if (tmp->total_size >= size)
                    return (tmp);
                tmp = tmp->next;
            }
        }
    }
    return (NULL);
}

/*
** place_in_heap(): returns the pointer to the allocated area.
*/

void *place_in_heap(t_heap *heap, int size)
{
    if (heap != NULL)
    {
        ft_putstr("heap exists\n");
        (void)size;
        // TODO place block in heap

    }
    return heap;
}