/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heylor <heylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:13:05 by heylor            #+#    #+#             */
/*   Updated: 2021/03/17 13:44:22 by heylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void *create_new_block(t_block *start)
{
    t_block *new_block;
    size_t pagesize;
    t_block *last;
    
    pagesize = getpagesize();
    printf("MMAP of %d bytes \n", (int)pagesize);
    new_block = mmap(NULL, pagesize, PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANON, -1, 0);
    if (new_block == MAP_FAILED) {
        return (NULL);
    }
    new_block->is_free = true;
    new_block->size = pagesize;
    last = start;
    if (last != NULL)
    {
        while(last->next != NULL)
            last = last->next;
    last->next = new_block;
    }
    new_block->next = NULL;
    ft_putstr("end of create new block\n");
    return (new_block);
}