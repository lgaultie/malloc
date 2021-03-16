/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heylor <heylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 23:08:54 by heylor            #+#    #+#             */
/*   Updated: 2021/03/16 23:08:58 by heylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void *create_new_block(t_block *start)
{
    t_block *new_block;
    size_t pagesize;
    t_block *tmp;
    
    pagesize = getpagesize();
    printf("MMAP OF %d BYTES DONE\n", (int)pagesize);
    new_block = mmap(NULL, pagesize, PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANON, -1, 0);
    if (new_block == MAP_FAILED) {
        return (NULL);
    }
    new_block->free = 1;
    new_block->total_size = pagesize;
    tmp = start;
    if (tmp != NULL)
    {
        while(tmp->next != NULL)
            tmp = tmp->next;
    }
    new_block->next = NULL;
    return (new_block);
}