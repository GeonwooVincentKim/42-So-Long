/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 02:13:34 by geonwkim          #+#    #+#             */
/*   Updated: 2024/11/28 21:44:30 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "so_long.h"
#include "libft/libft.h"

char	*ft_strrchr(const char *str, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *str, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);

static void	gnl_read(int fd, char *buf, char **str)
{
	int		i;
	char	*tmp;

	if (!*str || !ft_strchr(*str, '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		while (i > 0)
		{
			buf[i] = 0;
			if (!*str)
				*str = ft_strdup(buf);
			else
			{
				tmp = *str;
				*str = ft_strjoin(*str, buf);
				free(tmp);
			}
			if (ft_strchr(buf, '\n'))
				break ;
			i = read(fd, buf, BUFFER_SIZE);
		}
	}
	free(buf);
}

static char	*gnl_process(int fd, char **str)
{
	int		i;
	int		j;
	char	*ret;
	char	*tmp;

	if (!*str)
	{
		close(fd);
		return (0);
	}
	if (!ft_strchr(*str, '\n'))
	{
		ret = ft_strdup(*str);
		free(*str);
		*str = 0;
		return (ret);
	}
	i = ft_strlen(*str);
	j = ft_strlen(ft_strchr(*str, '\n'));
	ret = ft_substr(*str, 0, i - j);
	tmp = *str;
	*str = ft_substr(ft_strchr(*str, '\n'), 1, j - 1);
	free(tmp);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*str;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	if (fd == -1 || read(fd, buf, 0) == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}
	gnl_read(fd, buf, &str);
	return (gnl_process(fd, &str));
}
