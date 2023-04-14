/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:28:19 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/12/02 19:25:48 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (len--)
	{
		*str = (unsigned char)c;
		str++;
	}
	return (s);
}

// int main(void)
// {
//     char buf[] = "ABCDEFGHIJK";
//     memset(buf, '1', 5);
//     // ft_memset(buf, '1', 5);
//     printf("%s\n",buf);
//     return (0);
// }
// gcc -Wall -Wextra -Werror ft_memset.c