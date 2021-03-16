/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heylor <heylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 09:36:22 by heylor            #+#    #+#             */
/*   Updated: 2021/03/16 10:00:28 by heylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>


void *allocate(size_t size)
{
    printf("%s %d bytes\n", "allocated memory: ", (int)size);
    return (mmap(NULL, size, PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANON, -1, 0));    
}

void *create_new_heap()
{
    t_heap *new_heap;
    size_t pagesize;
    
    pagesize = getpagesize();
    new_heap = allocate(pagesize);
    if (new_heap == MAP_FAILED) {
        return (NULL);
    }
    new_heap->next = NULL;
    return (new_heap);
}