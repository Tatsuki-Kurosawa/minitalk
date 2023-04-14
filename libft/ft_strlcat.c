/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 02:47:46 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/12/03 02:07:39 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char *src, size_t dstsize)
{
	size_t		dst_len;
	size_t		src_len;

	src_len = ft_strlen(src);
	if (!dst && src && dstsize == 0)
		return (src_len);
	dst_len = ft_strlen((const char *)dst);
	if (dstsize < dst_len)
		return (dstsize + src_len);
	src_len = ft_strlcpy(dst + dst_len, src, dstsize - dst_len);
	return (dst_len + src_len);
}

// int	main(void)
// {
// 	size_t	num;
// 	char	str_1[20] = "abc";
// 	char	str_2[20] = "defe";

// 	num = strlcat(str_1, str_2, 5);
// 	// num = ft_strlcat(str_1, str_2, 3);
// 	printf("%lu\n", num);
// 	printf("%s\n", str_1);
// 	printf("%s\n", str_2);
// 	return (0);
// }

// gcc -Wall -Wextra -Werror ft_strlcat.c ft_strlen.c ft_strlcpy.c