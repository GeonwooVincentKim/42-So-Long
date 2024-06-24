/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 22:12:51 by geonwkim          #+#    #+#             */
/*   Updated: 2024/06/24 22:13:05 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *) str);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newarray;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	newarray = malloc(sizeof(char) * (len + 1));
	if (!newarray)
		return (NULL);
	while (*s1)
		newarray[i++] = *s1++;
	while (*s2)
		newarray[i++] = *s2++;
	newarray[i] = 0;
	return (newarray);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*newarray;
	char	*tmparray;
	size_t	i;

	newarray = malloc(sizeof(char) * (len + 1));
	if (!newarray)
		return (0);
	tmparray = (char *)str + start;
	i = 0;
	while (*tmparray && i < len)
		newarray[i++] = *tmparray++;
	newarray[i] = 0;
	return (newarray);
}

char	*ft_strdup(const char *s)
{
	return (ft_substr(s, 0, ft_strlen(s)));
}
