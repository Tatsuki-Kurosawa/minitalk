/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 23:39:48 by kurosawaits       #+#    #+#             */
/*   Updated: 2023/04/02 23:54:59 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	value;

void	output(void)
{
	while (true)
	{
		pause();
		if (count == 0)
		{
			binary = (int *)malloc(sizeof(int) * 8);
			if (!binary)
			{
				write(2, "error", ft_strlen("error"));
				exit(1);
			}
		}
		binary[count] = value;
		count++;
		if (count == 7)
		{
			write(1, &value, ft_strlen(&value));
			count = 0;
			value = 0;
			free(binary);
		}
	}
}

void	setbit(int signum)
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
	sa.sa_handler = setbit;
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
