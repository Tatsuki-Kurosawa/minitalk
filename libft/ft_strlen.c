/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:03:12 by kurosawaits       #+#    #+#             */
/*   Updated: 2023/02/16 07:53:08 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

// int main(void)
// {
//     // char *chara;
//     int num;
//     // chara = "ABCDE";
//     num = ft_strlen("");
//     // num = strlen("");
//     printf("%d", num);
// 	return (0);
// }
// gcc -Wall -Wextra -Werror ft_strlen.c