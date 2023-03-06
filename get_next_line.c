/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:37:59 by razasharuku       #+#    #+#             */
/*   Updated: 2023/03/06 12:21:28 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_change_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (buffer[i] != '\0')
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_create_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	//have to come back and check if it is really works.
	if (buffer[i] == '\0' || buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_free_joined(char *buffer, char *tmp)
{
	char *joined;

	joined = ft_strjoin(buffer, tmp);
	free(buffer);
	return (joined);
}


char	*ft_read_file(int fd, char *buffer)
{
	char	*tmp;
	int		read_count;

	if (buffer == 0)
		return (NULL);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_count = 1;
	while (read_count > 0)
	{
		read_count = read(fd, tmp, BUFFER_SIZE);
		if (read_count == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[read_count] = '\0';
		buffer = ft_free_joined(buffer, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static	char	*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (buffer == 0)
		return (NULL);
	line = ft_create_line(buffer);
	buffer = ft_change_buffer(buffer);
	return (line);
}

