/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heylor <heylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:19:46 by heylor            #+#    #+#             */
/*   Updated: 2021/03/15 22:08:48 by heylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void *start = NULL;

void *allocate(size_t size)
{
    printf("%s %d bytes\n", "allocated memory: ", (int)size);
    return (mmap(NULL, size, PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANON, -1, 0));    
}

bool can_find_space_in_heap(size)
{
    (void)size;
    return false;

}

void *place_in_heap(int size)
{
    (void)size;
    return NULL;
}

int create_new_heap()
{
    t_heap *new_heap;
    size_t pagesize;
    
    pagesize = getpagesize();
    new_heap = allocate(pagesize);
    if (new_heap == MAP_FAILED) {
        return (ERROR);
    }
    new_heap->next = NULL;
    start = new_heap;
    return (SUCCESS);
}

void *ft_malloc(int size)
{
    // True: could find heap and place block
    // False: could not place block
    bool blocked_placed = can_find_space_in_heap(size);

    // if false: create new heap
    while (can_find_space_in_heap(size) == false)
    {
        // create heap
        if (create_new_heap() == ERROR)
        {
            printf("%s", "could not create new heap");
            return;
        }
    }
    // place block
    return (place_in_heap(size));



    // // Populate
    // strcpy(region, "Hello, world!");
    // printf("Contents of region: %s\n", region);

    // // Free
    // int unmap_result = munmap(region, pagesize);
    // if (unmap_result != 0) {
    //     // return -1;
    // }
    // // return 0;
}

int main(int ac, char **av) {
    int space;

    printf("%p\n", &start);
    if (start)
        printf("heap exists alrdy\n");    
    else
        printf("first malloc\n");
    if (ac == 2)
        space = ft_atoi(av[1]);
    else
        return (ERROR);
    void *mallocated_space = ft_malloc(space);
    void *mallocated_space2 = ft_malloc(space);
    return (SUCCESS);
}