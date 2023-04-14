/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 23:39:43 by kurosawaits       #+#    #+#             */
/*   Updated: 2023/04/14 23:05:50 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_stop(void)
{
	write(2, "error", ft_strlen("error"));
	exit(1);
}

void	output(pid_t pid, char chara)
{
	int		i;
	int		mod;
	int		check;

	i = 0;
	while (i < 8)
	{
		mod = chara % 2;
		if (mod == 0)
			check = kill(pid, SIGUSR1);
		else
			check = kill(pid, SIGUSR2);
		usleep(900);
		if (check == -1)
			error_stop();
		chara /= 2;
		i++;
	}
}

void	setchar(pid_t pid, char *str)
{
	size_t	len;
	size_t	i;
	char	chara;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		chara = str[i];
		output(pid, chara);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	pid = (pid_t)ft_atoi(argv[1]);
	if (argc != 3 || argc == 0)
	{
		write(2, "error\n", ft_strlen("error\n"));
		exit(1);
	}
	if (pid <= 0 || pid > 4194304 || kill(pid, 0))
	{
		write(2, "PID error\n", ft_strlen("PID error\n"));
		exit(1);
	}
	setchar(pid, argv[2]);
	exit(0);
}
