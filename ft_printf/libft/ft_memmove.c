/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:02:14 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/20 14:55:01 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Prevent underflow! */
#define SIZE_T_MIN 0

/* Copy `len` bytes from `psrc` to `pdest` starting from the beginning. */
static void	copy_forward(char *pdest, const char *psrc, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		pdest[i] = psrc[i];
		++i;
	}
}

/* Copy `len` bytes from `psrc` to `pdest` starting from the end. */
static void	copy_backwards(char *pdest, const char *psrc, size_t len)
{
	size_t	i;

	if (len > SIZE_T_MIN)
	{
		i = len - 1;
		while (1)
		{
			pdest[i] = psrc[i];
			if (i == 0)
				break ;
			--i;
		}
	}
}

/*
   Copy `len` bytes from string `src` to string `dest`.
   If dest > src, start copying from end to beginning for avoiding data loss.
   Return `dest`.
   Return NULL if `dest` and `src` is NULL.
*/
void	*ft_memmove(void *dest, const void *src, size_t len)
{
	const char	*psrc;
	char		*pdest;

	if (dest == NULL && src == NULL)
		return (NULL);
	pdest = (char *) dest;
	psrc = (const char *) src;
	if (dest > src)
		copy_backwards(pdest, psrc, len);
	else
		copy_forward(pdest, psrc, len);
	return (dest);
}
