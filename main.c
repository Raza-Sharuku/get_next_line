/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:52:41 by razasharuku       #+#    #+#             */
/*   Updated: 2023/03/06 21:21:21 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>


int main(void)
{
    int fd;
    char *str;
    fd = open("raza.txt", O_RDONLY);
    printf("fd = %d \n", fd);
    while (1)
    {
        str = get_next_line(fd);
        printf("str = %s\n", str);
        if (str == NULL)
        {
            printf("str is NULL \n");
            break ;
        }
        printf("str = %s\n", str);
    }
    printf("---------------5--------------\n");
    return (0);
}
