/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:38:50 by razasharuku       #+#    #+#             */
/*   Updated: 2023/03/08 09:44:52 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dst;

	dst = (unsigned char *)s;
	if (n != 0)
	{
		while (n-- > 0)
			*dst++ = 0;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	if (size != 0 && count > (SIZE_T_MAX / size))
		return (NULL);
	if (size == 0 || count == 0)
		return (ft_calloc(1, 1));
	ret = malloc(count * size);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, count * size);
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		len_s1;
	size_t		len_s2;
	char		*str_ptr;

	str = NULL;
	len_s1 = 0;
	if (s2 == NULL)
		return (NULL);
	if (s1 != NULL)
		len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if ((len_s1 / 2 + len_s2 / 2) + 1 < SIZE_MAX / 2)
		str = (char *)malloc(len_s1 + len_s2 + 1);
	str_ptr = str;
	if (str == NULL)
		return (NULL);
	while (s1 != NULL && *s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (str_ptr);
}

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = (char)(c);
	while (*s != '\0')
	{
		if (*s == cc)
			return ((char *)s);
		s++;
	}
	if (cc == '\0' && *s == cc)
		return ((char *)s);
	return (NULL);
}
