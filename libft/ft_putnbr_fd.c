/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurosaw <tkurosaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:05:19 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/12/05 21:43:56 by tkurosaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	chara;

	if (n >= 0)
		n *= -1;
	else
		ft_putchar_fd('-', fd);
	if (-9 <= n && n <= 0)
	{
		chara = (n % 10) * (-1) + '0';
		ft_putchar_fd(chara, fd);
		return ;
	}
	chara = (n % 10) * (-1) + '0';
	ft_putnbr_fd(n / 10 * (-1), fd);
	ft_putchar_fd(chara, fd);
	return ;
}

// int	main(void)
// {
// 	// ft_putnbr_fd(9, 1);
// 	// printf("\n");
// 	ft_putnbr_fd(2147483647, 1);
// 	printf("\n");
// 	return (0);
// }
// gcc -Wall -Wextra -Werror ft_putnbr_fd.c ft_putchar_fd.c