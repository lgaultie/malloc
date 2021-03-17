/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heylor <heylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 09:34:46 by heylor            #+#    #+#             */
/*   Updated: 2021/03/17 13:54:07 by heylor           ###   ########.fr       */
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
        printf("%s: %d && %s: %d\n", "size of block", size, "tmp->size: ", tmp->size);
        printf("tmp->is_free = %d\n", tmp->is_free);
        while (tmp->next != NULL)
        {
            ft_putstr("in loop of find_space_in_heap\n");
            if (tmp->is_free == true && tmp->size >= size)
            {
                ft_putstr("FOUND PLACE\n");
                return (tmp);
            }
            tmp = tmp->next;
        }
    }
    return NULL;
}

/*
** place_in_heap(): split the heap to create new area for block,
** returns the pointer to the allocated area.
** https://stackoverflow.com/questions/49999524/recoding-malloc-with-mmap-strange-segfault
*/

// block devient celui de devant, et on cree un new qui prend la suite
void *place_in_heap(t_block *block, int size)
{

    t_block *new;

    if (block != NULL)
    {
        // put new pointer after block
        // should I consider size of struct?
        new = block + sizeof(struct s_block) + size;

        // new->size is what is left
        new->size = block->size - size - sizeof(struct s_block);

        block->is_free = false;
        block->next = new;
        new->next = NULL;
        new->is_free = true;
    }
    return block;
}