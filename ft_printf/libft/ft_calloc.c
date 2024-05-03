/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:36:46 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/20 14:59:03 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
   Allocate a memory with malloc and fill it with zeros.
   If requested size will be 0, a size of 1 will be allocated.
   Return NULL if malloc fails or overflow occurs.
*/
void	*ft_calloc(size_t elems_count, size_t elem_size)
{
	size_t	alloc_size;
	void	*ptr;

	alloc_size = elems_count * elem_size;
	if (elem_size != 0 && alloc_size / elem_size != elems_count)
		return (NULL);
	ptr = malloc(alloc_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, alloc_size);
	return (ptr);
}
