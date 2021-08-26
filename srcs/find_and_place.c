/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 09:23:27 by lgaultie          #+#    #+#             */
/*   Updated: 2021/08/26 17:28:57 by lgaultie         ###   ########.fr       */
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
    int index;

    tmp = start;
    index = 1;
    if (tmp != NULL) {
        while (tmp->next != NULL) {
            printf("Check1 %s block nb %d of size %d, trying to put %d in\n", tmp->is_free ? "FREE" : "NOT FREE", index, tmp->size, size);
            if (tmp->is_free == true && tmp->size >= size) {
                printf("FOUND PLACE in %s block nb %d of size %d, will put %d in\n", tmp->is_free ? "FREE" : "NOT FREE", index, tmp->size, size);
                return (tmp);
            }
            tmp = tmp->next;
            index++;
        }
        printf("Check2 %s block nb %d of size %d, trying to put %d in\n", tmp->is_free ? "FREE" : "NOT FREE", index, tmp->size, size);
        if (tmp->is_free == true && tmp->size >= size) {
            printf("FOUND PLACE in %s block nb %d of size %d, will put %d in\n", tmp->is_free ? "FREE" : "NOT FREE", index, tmp->size, size);
            return (tmp);
        }
    }
    return NULL;
}

/*
** 1/ take the block with space
** 2/ create a new block and place it after the data size
**    at address block_with_space but with data_size + struc size added
**    new_division = block_with_space + sizeof(struct s_block) + data_size;
** 3/ make the block with space link to the new one
** 4/ the new one has a size of block_with_space - data_size - struc size
** 5/ make new->next link to block_with_space ->next
** block_with_space->next becomes new
*/

void *place_in_heap(t_block *block_with_space, int data_size)
{

    t_block *new_division;
    int     new_division_size;

    printf("block with space before division: %d \n", block_with_space->size);
    ft_putstr("1\n");
    if (block_with_space == NULL)
        return NULL;
    // put new_division pointer after block_with_space:
    // block_with_space = 3, size struct = 1, data size = 2
    // gives: 111 1 11 --> 6 nous fait tomber sur le dernier element, 7 après
    // New div = 3 + 1 + 2 = 6 on tombe pas après! il faut faire +1 pour avoir 7 donc
    new_division_size = block_with_space->size - data_size;
    // new_division_size = block_with_space->size - data_size - sizeof(struct s_block);
    ft_putstr("2\n");
    
    // To prevent creating a block of size 0
    if (new_division_size > 0) {
        printf("New division size: %d \n", new_division_size);
        ft_putstr("3\n");
        // new_division = block_with_space + sizeof(struct s_block) + data_size;
        new_division = (t_block *)((char *)(block_with_space + 1) + data_size);
        // new_division = block_with_space + 4096 - new_division_size;
        ft_putstr("3.1\n");
        new_division->size = new_division_size;
        printf("new division->next is %p", new_division->next);
        ft_putstr("3.2\n");
        new_division->next = block_with_space->next;
        ft_putstr("3.3\n");
        new_division->is_free = true;
        ft_putstr("3.4\n");
        block_with_space->next = new_division;
        printf("New division size: %d \n", new_division->size);
    }
    ft_putstr("4\n");
    block_with_space->size = data_size;
    block_with_space->is_free = false;
    printf("block with space after division: %d \n", block_with_space->size);
    return block_with_space;
}