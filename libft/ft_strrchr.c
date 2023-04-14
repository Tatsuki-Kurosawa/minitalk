/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:17:52 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/12/07 09:48:43 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)(s + s_len));
	while (s_len--)
	{
		if (s[s_len] == (char)c)
			return ((char *)(s + s_len));
	}
	return (NULL);
}

// int main(void)
// {
//     char test[20] = "yuyguy";

//     printf("strrchr:	%s\n", strrchr(test, 'u'));
//     printf("ft_strrchr:	%s\n", ft_strrchr(test, 'u'));
//     printf("strrchr_ad:	%p\n", strrchr(test, 'u'));
//     printf("ft_strrchr_ad:	%p\n", ft_strrchr(test, 'u'));
//     return (0);
// }
// gcc -Wall -Wextra -Werror ft_strrchr.c ft_strlen.c