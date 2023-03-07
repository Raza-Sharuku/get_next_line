/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:52:41 by razasharuku       #+#    #+#             */
/*   Updated: 2023/03/07 20:47:35 by sraza            ###   ########.fr       */
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
        printf("str = %s", str);
        fflush(stdout);
        free(str);
        if (str == NULL)
            break ;
    }
    system("leaks a.out");
    return (0);
}
