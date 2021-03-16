/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heylor <heylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 09:36:22 by heylor            #+#    #+#             */
/*   Updated: 2021/03/16 10:53:02 by heylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void *create_new_heap(t_heap *start)
{
    t_heap *new_heap;
    size_t pagesize;
    t_heap *tmp;
    
    pagesize = getpagesize();
    printf("MMAP OF %d BYTES DONE\n", (int)pagesize);
    new_heap = mmap(NULL, pagesize, PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANON, -1, 0);
    if (new_heap == MAP_FAILED) {
        return (NULL);
    }
    new_heap->free_block = 0;
    new_heap->nb_block = 0;
    new_heap->total_size = pagesize;
    tmp = start;
    if (tmp != NULL)
    {
        while(tmp->next != NULL)
            tmp = tmp->next;
    }
    new_heap->prev = tmp;
    new_heap->next = NULL;
    return (new_heap);
}