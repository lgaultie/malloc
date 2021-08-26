/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 09:22:59 by lgaultie          #+#    #+#             */
/*   Updated: 2021/08/26 17:01:40 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

int main(int ac, char **av) {
    int space;

    if (ac == 2)
    {
        space = ft_atoi(av[1]);
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

    printf(" \\\\\\\\ %s\n", "ft_malloc(500) \\\\\\\\");
    void *mallocated_space2 = ft_malloc(500);
    printf("%p\n\n", mallocated_space2);

    printf(" \\\\\\\\ %s\n", "ft_malloc(5) \\\\\\\\");
    void *mallocated_space3 = ft_malloc(5);
    printf("%p\n\n", mallocated_space3);

    printf(" \\\\\\\\ %s\n", "ft_malloc(3535) \\\\\\\\");
    void *mallocated_space4 = ft_malloc(3535);
    printf("%p\n\n", mallocated_space4);

    printf(" \\\\\\\\ %s\n", "ft_malloc(61) \\\\\\\\");
    void *mallocated_space5 = ft_malloc(61);
    printf("%p\n\n", mallocated_space5);

    // int i = 0;
    // while (i < 4096){
    //     mallocated_space[i] = 'c';
    //     i++;
    // }

    printf("\n\n%s\n", "ft_strcpy Hello into ft_malloc(space)");
    ft_strcpy(mallocated_space, "Hello");
    printf("%s\n", mallocated_space);
    printf("%p\n\n", mallocated_space);

    printf("%s\n", "ft_strcpy Byyyye into ft_malloc(546)");
    ft_strcpy(mallocated_space2, "Byyyye");
    printf("%s\n", mallocated_space2);
    printf("%p\n\n", mallocated_space2);
    
    printf("%s\n", "ft_strcpy Sayonara into ft_malloc(5)");
    ft_strcpy(mallocated_space3, "Sayonara");
    printf("%s\n", mallocated_space3);
    printf("%p\n\n", mallocated_space3);

    printf("%s\n", "ft_strcpy Sayonara into ft_malloc(6)");
    ft_strcpy(mallocated_space4, "Sayonara");
    printf("%s\n", mallocated_space4);
    printf("%p\n\n", mallocated_space4);

    printf("%s\n", "ft_strcpy Sayonara into ft_malloc(7)");
    ft_strcpy(mallocated_space5, "Sayonara");
    printf("%s\n", mallocated_space5);
    printf("%p\n\n", mallocated_space5);

    // Free
    // int unmap_result = munmap(region, pagesize);
    // if (unmap_result != 0) {
        // return -1;
    // }
    // return 0;
    return (SUCCESS);
}