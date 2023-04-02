/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 23:39:43 by kurosawaits       #+#    #+#             */
/*   Updated: 2023/04/03 01:29:27 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_stop(void)
{
	write(2, "error", ft_strlen("error"));
	exit(1);
}

void	forwarding(int p_id, char *string)
{
	int		i;
	int		j;
	int		error_check;
	char	chara;

	i = 0;
	j = 0;
	while (i < ft_strlen(string))
	{
		chara = *(string + i);
		while (j < 8)
		{
			if (chara % 2 == 0)
				error_check = kill((pid_t)p_id, SIGUSR1);
			else
				error_check = kill((pid_t)p_id, SIGUSR2);
			if (error_check == -1)
				error_stop();
			chara /= 2;
			j++;
		}
		j = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	p_id;

	p_id = ft_atoi(argv[1]);
	if (argc != 3 || argc == 0)
	{
		write(2, "error\n", ft_strlen("error\n"));
		exit(1);
	}
	if (p_id <= 0 || p_id > 4194304 || kill(p_id, 0))
	{
		write(2, "PID error\n", ft_strlen("PID error\n"));
		exit(1);
	}
	forwarding((int)p_id, argv[2]);
	return (0);
}
