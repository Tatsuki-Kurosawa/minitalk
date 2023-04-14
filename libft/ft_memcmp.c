/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:30:08 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/12/03 01:02:02 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*con_s1;
	unsigned char	*con_s2;
	int				diff;

	con_s1 = (unsigned char *)s1;
	con_s2 = (unsigned char *)s2;
	while (n--)
	{
		diff = *con_s1 - *con_s2;
		if (diff)
			return (diff);
		con_s1++;
		con_s2++;
	}
	return (0);
}

// int main(void)
// {
//     char *buf_1 = "ABCD5EFGH";
//     char *buf_2 = "ABC123456";

//     if (memcmp(buf_1, buf_2, 5) == 0)
// 		printf("memcmp:	*buf_1 = *buf_2\n");
// 	else
// 		printf("memcmp: *buf_1 != *buf_2\n");
// 	if (ft_memcmp(buf_1, buf_2, 5) == 0)
// 		printf("ft_memcmp: *buf_1 = *buf_2\n");
// 	else
// 		printf("ftmemcmp: *buf_1 != *buf_2\n");
// 	return (0);
// }
// gcc -Wall -Wextra -Werror ft_memcmp.c