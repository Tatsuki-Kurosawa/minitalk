/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurosaw <tkurosaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:37:45 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/12/10 22:18:04 by tkurosaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c -= ('a' - 'A');
	return (c);
}

// int	main(void)
// {
// 	int	i;

// 	i = 96;
// 	while (i <= 123)
// 	{
// 		printf("toupper: %c, ft_toupper: %c\n", toupper(i), ft_toupper(i));
// 		i++;
// 	}
// 	return (0);
// }
// gcc -Wall -Wextra -Werror ft_toupper.c