/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heylor <heylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:19:46 by heylor            #+#    #+#             */
/*   Updated: 2021/03/16 11:24:15 by heylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void *g_var_start = NULL;

/*
** create_first_heap() creates a new heap and point g_var_start to it
*/

int create_first_heap()
{
    t_heap *new_heap;

    new_heap = create_new_heap(NULL);
    g_var_start = new_heap;
    return (SUCCESS);
}

/*
** ft_malloc(): if cannot find a place for the block, create new heap until
** he can places it
** maybe needs a step of defragmentation 
*/

void *ft_malloc(int size)
{
    void    *allocated_block;
    t_heap  *heap_to_place;

    if (size < 1)
        return (NULL);
    if (!g_var_start)
    {
        printf("g_var_exist not found: first malloc!\n");
        if (create_first_heap() != SUCCESS)
            return (NULL);
    }
    else
    {
        printf("g_var_exist: not first malloc\n");
    }
    while ((heap_to_place = can_find_space_in_heap(g_var_start, size)) == NULL)
    {
        ft_putstr("can_find_space_in_heap --> FAIL\n");
        if (create_new_heap(g_var_start) == NULL)
        {
            printf("%s", "could not create new heap");
            return (NULL);
        }
    }
    allocated_block = place_in_heap(heap_to_place, size);
    return (allocated_block);
}