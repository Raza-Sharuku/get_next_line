/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:36:27 by razasharuku       #+#    #+#             */
/*   Updated: 2023/03/06 12:23:08 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFFER_SIZE 2
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

//get_next_line_utils.c
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *s, int c);

//get_next_line.c
char			*ft_change_buffer(char *buffer);
char			*ft_create_line(char *buffer);
char			*ft_free_joined(char *buffer, char *tmp);
char			*ft_read_file(int fd, char *buffer);
char			*get_next_line(int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;


#endif
