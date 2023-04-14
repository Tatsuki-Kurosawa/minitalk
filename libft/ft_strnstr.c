/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:03:12 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/12/07 09:44:46 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	count;
	size_t	len_needle;

	if (!haystack && needle && !len)
		return (NULL);
	len_needle = ft_strlen(needle);
	if (ft_strlen(haystack) < len_needle || len < len_needle)
		return (NULL);
	i = 0;
	count = len - len_needle;
	while (i <= count)
	{
		if (!ft_strncmp(haystack, needle, len_needle))
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}

// if (ft_memcmp(haystack, needle, len_needle) == 0)
// int	main(void)
// {
// 	char	haystack[20] = "abcdef";
// 	char	needle[20] = "cd";
// 	size_t	len;

// 	len = 0;
// 	printf("strnstr:	%s\n", strnstr(NULL, needle, len));
// 	printf("ft_strnstr:	%s\n", ft_strnstr(haystack, needle, len));
// 	return (0);
// }
// gcc -Wall -Wextra -Werror ft_strnstr.c ft_strlen.c ft_memcmp.c