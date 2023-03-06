/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:52:41 by razasharuku       #+#    #+#             */
/*   Updated: 2023/03/06 12:29:46 by razasharuku      ###   ########.fr       */
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
        printf("---------------1--------------\n");
        str = get_next_line(fd);
        printf("---------------2--------------\n");
        printf("str = %s\n", str);
        printf("---------------3--------------\n");
        if (str == NULL)
            break ;
        printf("str = %s\n", str);
        printf("---------------4--------------\n");
    }
    printf("---------------5--------------\n");
    return (0);
}
