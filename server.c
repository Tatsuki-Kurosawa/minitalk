/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 23:39:48 by kurosawaits       #+#    #+#             */
/*   Updated: 2023/04/08 02:25:25 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_num;

char	output(char *byte)
{
	int		i;
	char	sum;

	i = 0;
	sum = 0;
	while (i < 8)
	{
		sum = sum * 2 + (byte[i] - '0');
		i++;
	}
	return (sum);
}

void	acceptance(void)
{
	int		i;
	char	*byte;
	char	chara;

	g_num = 0;
	i = 0;
	byte = (char *)malloc(sizeof(char) * (8 + 1));
	if (!byte)
		exit(1);
	while (1)
	{
		pause();
		byte[7 - i] = g_num;
		i++;
		if (i == 8)
		{
			byte[8] = '\0';
			i = 0;
			chara = output(byte);
			write(1, &chara, 1);
		}
	}
	free(byte);
}

void	tell(int signum)
{
	if (signum == SIGUSR1)
		g_num = '0';
	else if (signum == SIGUSR2)
		g_num = '1';
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = tell;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	acceptance();
	exit(0);
}
