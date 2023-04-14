/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurosaw <tkurosaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:03:59 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/12/10 20:15:33 by tkurosaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}

// int main(void)
// {
//     for (int i = 0; i <= 128; i++)
// 	{
//         printf("isascii:	i:%d '%c' _ %d\n", i, i, isascii(i));
//         printf("ft_isascii:	i:%d '%c' _ %d\n", i, i, ft_isascii(i));
// 	}
// }
// gcc -Wall -Wextra -Werror ft_isascii.c