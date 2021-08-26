/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 09:23:22 by lgaultie          #+#    #+#             */
/*   Updated: 2021/08/26 17:29:31 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <malloc.h>

/*
** The function getpagesize() returns the number of bytes in a
** memory page, where "page" is a fixed-length block, the unit for
** memory allocation and file mapping performed by mmap(2).
** 
** void *mmap(void *starting_addr, size_t length, int prot, int flags,
**           int fd, off_t offset);
** PROT_EXEC
**         Pages may be executed.
** PROT_READ
**         Pages may be read.
** PROT_WRITE
**         Pages may be written.
** PROT_NONE
**         Pages may not be accessed.
** On success, mmap() returns a pointer to the mapped area.  On
** error, the value MAP_FAILED (that is, (void *) -1) is returned,
** and errno is set to indicate the error.
*/

void *create_new_block(t_block *start)
{
    t_block *new_block;
    t_block *last;
    
    printf("---------------- CREATE NEW BLOCK of 4096 bytes --------------------\n");
    // The flags argument determines whether updates to the mapping are
    // visible to other processes mapping the same region, and whether
    // updates are carried through to the underlying file.
    //  MAP_ANONYMOUS
    //           The mapping is not backed by any file; its contents are
    //           initialized to zero.  The fd argument is ignored; however,
    //           some implementations require fd to be -1 if MAP_ANONYMOUS
    //           (or MAP_ANON) is specified, and portable applications
    //           should ensure this.  The offset argument should be zero.
    // MAP_PRIVATE
    //     Create a private copy-on-write mapping.  Updates to the
    //     mapping are not visible to other processes mapping the
    //     same file, and are not carried through to the underlying
    //     file.  It is unspecified whether changes made to the file
    //     after the mmap() call are visible in the mapped region.
    // getpagesize() renvoie 4096, la taille des pages
    new_block = mmap(NULL, 4096, PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (new_block == MAP_FAILED) {
        return (NULL);
    }
    // Initialize new block
    new_block->is_free = true;
    new_block->size = 4096;

    // retrieve last block and make it point to new_block
    last = start;
    if (last != NULL) {
        while(last->next != NULL)
            last = last->next;
        last->next = new_block;
    }
    // end of linked list is null
    new_block->next = NULL;
    return (new_block);
}