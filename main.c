/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:52:41 by razasharuku       #+#    #+#             */
/*   Updated: 2023/03/06 12:22:27 by razasharuku      ###   ########.fr       */
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
    while (1)
    {
        printf("---------------1--------------");
        str = get_next_line(fd);
        printf("---------------2--------------");
        printf("str = %s\n", str);
        printf("---------------3--------------");
        if (str == NULL)
            break ;
        printf("str = %s\n", str);
        printf("---------------4--------------");
    }
    printf("---------------5--------------");
    return (0);
}
