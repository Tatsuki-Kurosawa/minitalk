/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:21:36 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/12/07 09:28:30 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	check;
	char	*str;

	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	check = ft_strlcpy(str, s1, len + 1);
	if (check != ft_strlen(str))
	{
		free(str);
		return (NULL);
	}
	return (str);
}

// int	main(void)
// {
// 	char	str[10] = "abcdef";
// 	char	*str_ptr;

// 	// str_ptr = strdup(str);
// 	str_ptr = ft_strdup(str);
// 	printf("%p\n", str);
// 	printf("%s\n", str_ptr);
// 	return (0);
// }
// gcc -Wall -Wextra -Werror ft_strdup.c ft_strlen.c　ft_strlcpy.c