/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heylor <heylor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 09:52:11 by heylor            #+#    #+#             */
/*   Updated: 2021/03/17 13:46:03 by heylor           ###   ########.fr       */
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
    void *mallocated_space = ft_malloc(space);
    void *mallocated_space2 = ft_malloc(546);
    void *mallocated_space3 = ft_malloc(5);
    ft_strcpy(mallocated_space, "Hello");
    printf("%s\n", mallocated_space);
    ft_strcpy(mallocated_space2, "Byyyye");
    printf("%s\n", mallocated_space2);
    ft_strcpy(mallocated_space3, "Sayonara");
    printf("%s\n", mallocated_space3);

    // // Free
    // int unmap_result = munmap(region, pagesize);
    // if (unmap_result != 0) {
    //     // return -1;
    // }
    // // return 0;
    return (SUCCESS);
}