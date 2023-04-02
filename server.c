/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 23:39:48 by kurosawaits       #+#    #+#             */
/*   Updated: 2023/04/03 01:30:34 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	value;

int	change_radix(int *binary)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < 8)
	{
		sum = sum * 2 + binary[i];
		i++;
	}
	return (sum);
}

void	output(void)
{
	int	count;
	int	num;
	int	*binary;

	count = 7;
	while (1)
	{
		pause();
		printf("動いたよ");
		if (count == 7)
		{
			binary = (int *)malloc(sizeof(int) * 8);
			if (!binary)
			{
				write(2, "malloc_error", ft_strlen("malloc_error"));
				exit(1);
			}
		}
		binary[count] = value;
		if (count == 0)
		{
			num = change_radix(binary);
			write(1, &num, 1);
			count = 7;
			free(binary);
		}
		else
			count--;
	}
}

void	set_bit(int signum)
{
	if (signum == SIGUSR1)
		value = 0;
	else if (signum == SIGUSR2)
		value = 1;
}

void	acceptance(void)
{
	struct sigaction	sa;
	int					count;
	int					*binary;

	count = 0;
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = set_bit;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	output();
}

int	main(void)
{
	pid_t	p_id;

	p_id = getpid();
	ft_putnbr_fd((int)p_id, 0);
	write(1, "\n", ft_strlen("\n"));
	acceptance();
	return (0);
}
