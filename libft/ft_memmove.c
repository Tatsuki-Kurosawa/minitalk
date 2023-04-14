/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurosaw <tkurosaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:46:09 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/12/10 19:20:09 by tkurosaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*mem_dst;
	const unsigned char	*mem_src;

	mem_dst = (unsigned char *)dst;
	mem_src = (const unsigned char *)src;
	if (mem_dst == mem_src)
		return (dst);
	if (mem_src < mem_dst)
		while (len--)
			mem_dst[len] = mem_src[len];
	else
		dst = ft_memcpy(dst, src, len);
	return (dst);
}

// int main(void)
// {
// 	char	dst[20] = "abcdef";
// 	char	src[20] = "ghij";
// 	memmove(dst, src, 3);
//     // ft_memmove(dst, src, 3);
//     printf("%s\n",dst);
//     return (0);
// }
// gcc -Wall -Wextra -Werror ft_memmove.c