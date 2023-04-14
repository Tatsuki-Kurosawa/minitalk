/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurosaw <tkurosaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:38:34 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/12/10 18:17:13 by tkurosaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*mem_dest;
	const unsigned char	*mem_src;

	mem_dest = (unsigned char *)dest;
	mem_src = (const unsigned char *)src;
	if (mem_dest == mem_src)
		return (dest);
	while (n--)
		*mem_dest++ = *mem_src++;
	return (dest);
}

// int	main(void)
// {
// 	char	src[20] = "12345";
// 	char	dst_1[20] = "abcdjefk";
// 	char	dst_2[20] = "abcdjefk";
// 	size_t	len;

// 	len = strlen(dst_1);
// 	printf("dst_1: %s\n", dst_1);
// 	memcpy(dst_1, src, 0);
// 	printf("memcpy: %s\n",dst_1);
// 	len = strlen(dst_2);
// 	printf("dst_2: %s\n", dst_2);
// 	ft_memcpy(dst_2, src, len);
// 	printf("ft_memcpy: %s\n",dst_2);
// 	return (0);
// }
// gcc -Wall -Wextra -Werror ft_memcpy.c