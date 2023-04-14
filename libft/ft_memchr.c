/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurosaw <tkurosaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:51:42 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/12/10 18:54:08 by tkurosaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return (ptr + i);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char *buf_1 = "ABCD5EFGH";
// 	char *buf_2 = "ABCD5EFGH";
// 	char *ch_1;
// 	char *ch_2;

// 	ch_1 = (char *)memchr(buf_1,'5',7);
// 	ch_2 = (char *)ft_memchr(buf_2,'5',7);
// 	printf("memchr:		%s\n", ch_1);
// 	printf("ft_memchr:	%s\n", ch_2);
// 	return (0);
// }
// gcc -Wall -Wextra -Werror ft_memchr.c