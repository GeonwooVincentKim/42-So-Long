/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:07:12 by geonwkim          #+#    #+#             */
/*   Updated: 2024/07/03 20:23:56 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_calloc(size_t n_items, size_t size)
{
	void	*p;
	size_t	size_bytes;

	if (n_items == 0 || size == 0)
	{
		n_items = 1;
		size = 1;
	}
	if (n_items > SIZE_MAX / size)
		return (NULL);
	size_bytes = n_items * size;
	p = malloc(size_bytes);
	if (p != NULL)
		ft_memset(p, 0, size_bytes);
	if (p == NULL)
		return (NULL);
	return (p);
}

// int main()
// {
//     int *temp;
// 	// Check if memory allocation was successful
// 	// int *array = (int*)ft_calloc(0, 0);
// 	// free(array);
// 	int* array = (int*)calloc(0, 0);
// 	free(array);
// 	// int* array = (int*)ft_calloc(5, 0);
//     int	i;
// 	temp = array;
// 	i = 0;
// 	// if (array)
// 	// {
// 	// 	while (i < 5)
// 	// 	{
// 	// 		// This should print "0 0 0 0 0 "
// 	// 		printf("%d ", array[i]);
// 	// 		i++;
// 	// 	}
// 	// 	printf("\n");
//     //     free(array);
//     // }
// 	// else
//         // printf("Memory allocation failed\n");
// 	return (0);
// }
