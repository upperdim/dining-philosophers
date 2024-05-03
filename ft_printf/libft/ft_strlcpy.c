/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:38:38 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/13 16:47:22 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Prevent underflow! */
#define SIZE_T_MIN 0

/*
  Both `src` and `dest` should be null-terminated strings.

  * Copies upto `dstsize` - 1 characters or until end of `src` 
  from `src` to `dest`, then null-terminates the result.

  Returns how many characters are in `src` initially. (Length, excludes '\0')
  
  * If `dstsize` is 0, it can't null-terminate, just returns `src` length.

  Unlike strncpy(),
    * This accepts full size of the buffer as `dstsize`, including '\0'. 
	Not just length (excluding '\0') of the array to be copied.
	* Null-terminates `dest`, but does not pad its ending with '\0' 
	like strncpy().
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && dstsize != SIZE_T_MIN && i < (dstsize - 1))
	{
		dest[i] = src[i];
		++i;
	}
	if (dstsize > 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}

// #include <stdio.h>
// void test(int size)
// {
//     char string[] = "Hello there, Venus";
//     char buffer[19];
//     int r;

//     r = strlcpy(buffer,string,size);

//     printf("Copied '%s' into '%s', length %d\n",
//             string,
//             buffer,
//             r
//           );
// }

// int main() {
// 	char d[3];
// 	char s[] = "hi";
// 	size_t ret = ft_strlcpy(d, s, 3);
// 	printf("%zu\n", ret);
// 	// test(19);
//     // test(10);
//     // test(1);
//     // test(0);

// 	// char s1[15] = "small sentence";
// 	// char s2[15] = "big sentence";

// 	// size_t ret = ft_strlcpy(s1, s2, 0);
// 	// printf("%zu\n", ret);
// }