/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 09:22:59 by lgaultie          #+#    #+#             */
/*   Updated: 2021/08/30 20:41:53 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "includes/malloc.h"

int main(int ac, char **av) {
    int space;

    if (ac == 2)
    {
        space = atoi(av[1]);
    //     if (g_var_start)
    //         printf("heap exists alrdy\n");
    //     else
    //     {
    //         if (space > 0 || create_first_heap() != SUCCESS)
    //             return (ERROR);
    //         printf("first malloc\n");
    //     }
    }
    else
        return (ERROR);
    printf(" \n\\\\\\\\ ft_malloc(%d) \\\\\\\\\n", space);
    void *mallocated_space = ft_malloc(space);
    printf("%p\n\n", mallocated_space);

    printf(" \\\\\\\\ %s\n", "ft_malloc(3534534535) \\\\\\\\");
    void *mallocated_space4 = ft_malloc(35344);
    printf("%p\n\n", mallocated_space4);

    printf(" \\\\\\\\ %s\n", "ft_malloc(500) \\\\\\\\");
    void *mallocated_space2 = ft_malloc(500);
    printf("%p\n\n", mallocated_space2);

    printf(" \\\\\\\\ %s\n", "ft_malloc(5) \\\\\\\\");
    void *mallocated_space3 = ft_malloc(5);
    printf("%p\n\n", mallocated_space3);

    printf(" \\\\\\\\ %s\n", "ft_malloc(61) \\\\\\\\");
    void *mallocated_space5 = ft_malloc(61);
    printf("%p\n\n", mallocated_space5);

    // int i = 0;
    // while (i < 4096){
    //     mallocated_space[i] = 'c';
    //     i++;
    // }

    printf("\n\n%s\n", "strcpy Hello into ft_malloc(space)");
    strcpy(mallocated_space, "Hello");
    printf("%s\n", mallocated_space);
    printf("%p\n\n", mallocated_space);

    printf("%s\n", "strcpy Byyyye into ft_malloc(546)");
    strcpy(mallocated_space2, "Byyyye");
    printf("%s\n", mallocated_space2);
    printf("%p\n\n", mallocated_space2);
    
    printf("%s\n", "strcpy Sayonara into ft_malloc(5)");
    strcpy(mallocated_space3, "Sayonara");
    printf("%s\n", mallocated_space3);
    printf("%p\n\n", mallocated_space3);

    printf("%s\n", "strcpy Sayonara into ft_malloc(6)");
    strcpy(mallocated_space4, "Sayonara");
    printf("%s\n", mallocated_space4);
    printf("%p\n\n", mallocated_space4);

    printf("%s\n", "strcpy Sayonara into ft_malloc(7)");
    strcpy(mallocated_space5, "Sayonara");
    printf("%s\n", mallocated_space5);
    printf("%p\n\n", mallocated_space5);

    show_alloc_mem();

    // Free
    // int unmap_result = munmap(region, pagesize);
    // if (unmap_result != 0) {
        // return -1;
    // }
    // return 0;
    return (SUCCESS);
}