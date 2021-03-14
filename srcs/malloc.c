/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heylor <heylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:19:46 by heylor            #+#    #+#             */
/*   Updated: 2021/03/14 16:03:23 by heylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

/*
** mmap() handles the mapping of physical memory zones to virtual addresses
** and returns a pointer to its start.
** malloc is like a perfomance wrapper around mmap
** We will preallocate more memory than needed, so we can avoid system calls 
** at the cost of a small memory overhead. New malloc calls will fill 
** the preallocated space until new space is needed.
** The function getpagesize() returns the number of bytes in a memory
** page, where “page” is a fixed-length block, the unit for memory
** allocation and file mapping performed by mmap(2).
** It’s better to use a multiple of getpagesize() for defining the size of heap. 
** For example, my system has a pagesize of 4096 bytes (run getconf PAGE_SIZE).
*/

// void *mmap(void *addr, size_t length, int prot, int flags,
//                  int fd, off_t offset);

//     void *addr is the address we want to start mapping
//     size_t length is the size we want to map in as integer
//     PROT_READ|PROT_WRITE|PROT_EXEC options about page
//     MAP_ANON|MAP_PRIVATE options about page

void *allocate_memory(size_t size)
{
    printf("%s %d bytes\n", "allocated memory: ", (int)size);
    return (mmap(NULL, size, PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANON, -1, 0));    
}

int main(void)
{
    size_t pagesize = getpagesize();

    // Allocate
    char * region = allocate_memory(pagesize);
    if (region == MAP_FAILED) {
        return -1;
    }

    // Populate
    strcpy(region, "Hello, world!");
    printf("Contents of region: %s\n", region);

    // Free
    int unmap_result = munmap(region, pagesize);
    if (unmap_result != 0) {
        return -1;
    }
    return 0;
}