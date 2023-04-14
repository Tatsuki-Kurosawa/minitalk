/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurosaw <tkurosaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:16:54 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/12/10 20:16:22 by tkurosaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (' ' <= c && c <= '~');
}

// int main(void)
// {
//     for (int i = 0; i <= 127; i++)
// 	{
//         printf("isprint:	i:%d '%c' _ %d\n", i, i, isprint(i));
//         printf("ft_isprint:	i:%d '%c' _ %d\n", i, i, ft_isprint(i));
// 	}
// 	return (0);
// }
// gcc -Wall -Wextra -Werror ft_isprint.c