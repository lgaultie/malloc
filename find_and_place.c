/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 09:23:27 by lgaultie          #+#    #+#             */
/*   Updated: 2021/08/30 18:31:22 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

/*
** can_find_space_in_heap(): returns the pointer to the heap which has place.
** If it finds 2 free blocks in a row, merge them.
** Returns null if he can't find place.
*/

void *find_space_in_heap(void *start, int size)
{
    t_block *tmp;
    t_block *tmp2;
    int index;

    tmp = start;
    index = 1;
    if (tmp != NULL) {
        while (tmp) {
            // If needed merge blocks between them
            if (tmp->is_free == 1 && tmp->next && tmp->next->is_free == 1){
                printf("Merging blocks %d and %d of size: %d and %d\n", index, index + 1, tmp->size, tmp->next->size);
                tmp2 = tmp->next;
                tmp->next = tmp2->next;
                tmp->size = tmp->size + tmp2->size + sizeof(struct s_block);
            }
            printf("Check %s block nb %d of size %d, trying to put %d in\n", tmp->is_free == 1 ? "FREE" : "NOT FREE", index, tmp->size, size);
            if (tmp->is_free == 1 && tmp->size >= size) {
                printf("FOUND PLACE in %s block nb %d of size %d, will put %d in\n", tmp->is_free ? "FREE" : "NOT FREE", index, tmp->size, size);
                return (tmp);
            }
            tmp = tmp->next;
            index++;
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
    int     new_div_size;

    printf("block with space before division: %d \n", block_with_space->size);
    if (block_with_space == NULL)
        return NULL;
    // To prevent creating a block of size 0
    // Size = space available minus data to put in minus metadata block size
    new_div_size = block_with_space->size - data_size - sizeof(struct s_block);
    if (new_div_size > 0) {
        // put new_division pointer after block_with_space:
        // block_with_space = 3, size struct = 1, data size = 2
        // gives: 111 1 11 --> 6 nous fait tomber sur le dernier element, 7 après
        // New div = 3 + 1 + 2 = 6 on tombe pas après! il faut faire +1 pour avoir 7 donc
        // we return block+1 because we want to return a pointer to the region 
        // after block_meta. 
        // Here, since block is a pointer of type struct block_meta, +1 increments the address by one sizeof(struct(block_meta)).
        // if you do int *block; block++ it will increment of size(int)
        // If we increment a pointer by 1, the pointer will start pointing to the immediate next location. 
        // This is somewhat different from the general arithmetic since the value of the pointer will 
        // get increased by the size of the data type to which the pointer is pointing.
        // So we cast in char * becausesize of char is 1, so block_with_space + 1) points to size 1
        new_division = (t_block *)((char *)(block_with_space + 1) + data_size);
        // new_division = block_with_space + 1 + sizeof(struct s_block) + data_size;
        // new_division = block_with_space + 4096 - new_division_size;
        new_division->size = new_div_size;
        new_division->next = block_with_space->next;
        new_division->is_free = 1;
        block_with_space->next = new_division;
        printf("New division size: %d and address: %p\n", new_division->size, new_division);
    }
    block_with_space->size = data_size;
    block_with_space->is_free = 0;
    printf("block with space after division: %d and address: %p\n", block_with_space->size, block_with_space);
    // return address+sizeof(s_block) to prevent overwritting metadata of the structure (as they are at the start of the block space)
    return block_with_space + sizeof(struct s_block);
}