/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 02:13:34 by geonwkim          #+#    #+#             */
/*   Updated: 2024/07/03 20:25:13 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "so_long.h"
#include "libft/libft.h"

static void	buf_free(char **buf)
{
	if (*buf != NULL)
	{
		free(*buf);
		buf = NULL;
	}
}

// Get a line from a buffer or string, such as might 
// be used in reading lines from a file one at a time
static char	*get_next_line_process(int num_of_line, char **buffer)
{
	char	*result;
	char	*str_tmp;

	str_tmp = NULL;
	if (num_of_line <= 0)
	{
		if (**buffer == '\0')
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		result = *buffer;
		*buffer = NULL;
		return (result);
	}
	str_tmp = ft_substr(*buffer, num_of_line, BUFFER_SIZE);
	result = *buffer;
	result[num_of_line] = 0;
	*buffer = str_tmp;
	return (result);
}

// Read data from the file and append it to partial content
// size_t -> count of bytes, sizeof() operator, range [0, SIZE_MAX]
// ssize_t -> count of bytes an error indication, range [-1, SSIZE_MAX];
// SSIZE_MAX = LONG_MAX, SIZE_MAX = UINTPTR_MAX

// Read a line of text from a File Descriptor into a buffer
// flides -> File Descriptor
// **buffer -> Store the dynamically allocated to buffer
// *read_return -> A temporary buffer, store the charactes 
// read from the flides in each iteration
static char	*read_from_file(int flides, char **buffer, char *read_buffer)
{
	ssize_t	count_bytes;
	char	*str_tmp;
	char	*new_line;

	new_line = ft_strchr(*buffer, '\n');
	str_tmp = NULL;
	count_bytes = 0;
	while (new_line == NULL)
	{
		count_bytes = read(flides, read_buffer, BUFFER_SIZE);
		if (count_bytes <= 0)
			return (get_next_line_process(count_bytes, buffer));
		read_buffer[count_bytes] = 0;
		str_tmp = ft_strjoin(*buffer, read_buffer);
		buf_free(buffer);
		*buffer = str_tmp;
		new_line = ft_strchr(*buffer, '\n');
	}
	return (get_next_line_process(new_line - *buffer + 1, buffer));
}

// Get the next line from the file descriptor
// basin = たらい
// If
// fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FILE_DESCRIPTOR
// not exist, the Segmentation Error could be occured
char	*get_next_line(int fd)
{
	static char	*basin_buffer[MAX_FILE_DESCRIPTOR + 1];
	char		*read_line;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FILE_DESCRIPTOR)
		return (NULL);
	read_line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (read_line == NULL)
		return (NULL);
	if (!basin_buffer[fd])
		basin_buffer[fd] = ft_strdup("");
	result = read_from_file(fd, &basin_buffer[fd], read_line);
	buf_free(&read_line);
	return (result);
}
