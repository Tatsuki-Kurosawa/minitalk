/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:20:11 by kurosawaits       #+#    #+#             */
/*   Updated: 2023/02/16 08:11:15 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*return_ptr;
	size_t		str_size;
	size_t		check;

	if (!s1 || !s2)
		return (NULL);
	str_size = ft_strlen(s1) + ft_strlen(s2);
	return_ptr = (char *)malloc(sizeof(char) * (str_size + 1));
	if (!return_ptr)
		return (NULL);
	check = ft_strlcpy(return_ptr, s1, ft_strlen(s1) + 1);
	if (check != ft_strlen(return_ptr))
	{
		free(return_ptr);
		return (NULL);
	}
	check = ft_strlcpy(return_ptr + check, s2, ft_strlen(s2) + 1);
	if (check != ft_strlen(s2))
	{
		free(return_ptr);
		return (NULL);
	}
	return (return_ptr);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char		*return_ptr;
// 	size_t		str_size;
// 	size_t		check;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	str_size = ft_strlen(s1) + ft_strlen(s2);
// 	return_ptr = (char *)malloc(sizeof(char) * (str_size + 1));
// 	if (!return_ptr)
// 		return (NULL);
// 	check = ft_strlcpy(return_ptr, s1, ft_strlen(s1) + 1);
// 	if (check != ft_strlen(return_ptr))
// 	{
// 		free(return_ptr);
// 		return (NULL);
// 	}
// 	check = ft_strlcat(return_ptr, s2, str_size + 1);
// 	if (check != str_size)
// 	{
// 		free(return_ptr);
// 		return (NULL);
// 	}
// 	return (return_ptr);
// }

// int	main(void)
// {
// 	char	*s1 = "my favorite animal is";
// 	// char	*s2 = " ";
// 	char	*s3 = "the nyancat";
// 	size_t	number;

// 	char	*res = ft_strjoin(s1, s3);
// 	// char	*res = ft_strjoin(ft_strjoin(s1, s2), s3);
// 	printf("%s\n", res);
// 	number = strlen(res);
// 	printf("%zu\n", number);
// 	return (0);
// }
// gcc -Wall -Wextra -Werror ft_strjoin.c ft_strlen.c ft_strlcpy.c ft_strlcat.c