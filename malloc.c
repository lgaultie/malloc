/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 09:23:38 by lgaultie          #+#    #+#             */
/*   Updated: 2021/08/30 20:23:26 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void *g_var_start = NULL;

void	show_alloc_mem() {
    t_block     *tmp;
    int         total;
    // 1 = tiny, 2 = small, 3 = large
    int         tiny_small_large;

    total = 0;
    tmp = g_var_start;
    tiny_small_large = 0;
    while (tmp) {
        if (tmp->size <= TINY && tiny_small_large != 1) {
            printf("TINY: %p\n", tmp);
            tiny_small_large = 1;
        }
        if (tmp->size <= LARGE && tmp->size > TINY && tiny_small_large != 2) {
            printf("SMALL: %p\n", tmp);
            tiny_small_large = 2;
        }
        if (tmp->size > LARGE && tiny_small_large != 3) {
            printf("LARGE: %p\n", tmp);
            tiny_small_large = 3;
        }
        printf("%p - %p : %d octets\n", tmp, tmp->next, tmp->size);
        total = total + tmp->size;
        tmp = tmp->next;
    }
    printf("Total: %d octets\n", total);
}

/*
** init_memory() creates a new block and point g_var_start to it
** if block is null, return ERROR
*/

int init_memory(size_t data_size)
{
    t_block *new_block;

    if ((new_block = create_new_block(NULL, data_size)) == NULL)
        return ERROR;
    g_var_start = new_block;
    return SUCCESS;
}

/*
** ft_malloc(): if cannot find a place for the block, create new block until
** he can places it
**  You start off with a sentinel to keep track of the start of the heap and 
** deal with ease with chunk removal, then for each call of malloc you increment 
** the program break by a word-aligned value of sizeof(struct chunk) + size, 
** where size is the parameter passed to malloc.
** maybe needs a step of defragmentation :
As we reuse free spaces, the must here would be to split the reused chunks 
** if they are oversized and insert a new chunk right after. In the same manner, 
** it would be a shame to let free chunks congregate without merging them into 
** one big free chunk, as it might cause issues with performance for programs 
** that need to allocate large amounts of memory, as they would spawn a lot of chunks.
*/

void *ft_malloc(size_t data_size)
{
    void    *allocated_block;
    t_block  *block_with_space;

    if (data_size < 1)
        return NULL;
    if (!g_var_start) {
        if (init_memory(data_size) != SUCCESS)
            return NULL;
    }
    while ((block_with_space = find_space_in_heap(g_var_start, data_size)) == NULL) {
        printf("Couldn't find space: goes to create new block\n");
        if (create_new_block(g_var_start, data_size) == NULL)
            return NULL;
    }
    allocated_block = place_in_heap(block_with_space, data_size);
    return (allocated_block);
}