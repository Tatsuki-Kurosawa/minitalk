/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:17:30 by kurosawaits       #+#    #+#             */
/*   Updated: 2023/04/07 23:17:31 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}

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

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

static int	check_overflow(int sign, unsigned long sum, char c)
{
	unsigned long	tmp;

	tmp = LONG_MAX / 10;
	if (sign == 1)
	{
		if (tmp < sum || (sum == tmp && LONG_MAX % 10 < c - '0'))
			return (1);
	}
	else if (sign == -1)
	{
		if (tmp < sum || (sum == tmp && (LONG_MIN % 10) * (-1) < c - '0'))
			return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	char			*rp_str;
	int				sign;
	unsigned long	sum;

	rp_str = (char *)str;
	sign = 1;
	sum = 0;
	while (('\t' <= *rp_str && *rp_str <= '\r') || *rp_str == ' ')
		rp_str++;
	if (*rp_str == '+' || *rp_str == '-')
	{
		if (*rp_str == '-')
			sign = -1;
		rp_str++;
	}
	while (ft_isdigit(*rp_str))
	{
		if (sign == 1 && check_overflow(sign, sum, *rp_str))
			return ((int) LONG_MAX);
		if (sign == -1 && check_overflow(sign, sum, *rp_str))
			return ((int) LONG_MIN);
		sum = (*rp_str - '0') + sum * 10;
		rp_str++;
	}
	return (sum * sign);
}
