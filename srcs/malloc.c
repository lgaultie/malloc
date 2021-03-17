/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heylor <heylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:19:46 by heylor            #+#    #+#             */
/*   Updated: 2021/03/17 13:45:18 by heylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void *g_var_start = NULL;

/*
** init_memory() creates a new block and point g_var_start to it
*/

int init_memory()
{
    t_block *new_block;

    new_block = create_new_block(NULL);
    if (new_block == NULL)
        return ERROR;
    g_var_start = new_block;
    return SUCCESS;
}

/*
** ft_malloc(): if cannot find a place for the block, create new block until
** he can places it
** maybe needs a step of defragmentation 
*/

void *ft_malloc(int size)
{
    void    *allocated_block;
    t_block  *block_to_place;

    if (size < 1)
        return NULL;
    if (!g_var_start)
    {
        ft_putstr("-----------------------------\n");
        printf("g_var_exist not found: first malloc!\n");
        if (init_memory() != SUCCESS)
            return NULL;
    }
    else
    {
        ft_putstr("-----------------------------\n");
        printf("g_var_exist: no first malloc\n");
    }
    while ((block_to_place = find_space_in_heap(g_var_start, size)) == NULL)
    {
        ft_putstr("find_space_in_block --> FAIL\n");
        if (create_new_block(g_var_start) == NULL)
            return NULL;
        // TODO need to merge blocks to have bigger space? If size > pagesize
    }
    allocated_block = place_in_heap(block_to_place, size);
    return (allocated_block);
}