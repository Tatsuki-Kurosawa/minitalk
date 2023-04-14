/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:46:29 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/12/04 21:54:49 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c += ('a' - 'A');
	return (c);
}

// int	main(void)
// {
// 	int	i;

// 	i = 64;
// 	while (i <= 91)
// 	{
// 		printf("tolower: %c, ft_tolower: %c\n", tolower(i), ft_tolower(i));
// 		i++;
// 	}
// 	return (0);
// }
// gcc -Wall -Wextra -Werror ft_tolower.c