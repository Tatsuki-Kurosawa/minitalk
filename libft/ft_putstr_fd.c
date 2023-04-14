/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurosaw <tkurosaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:05:41 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/12/10 18:18:56 by tkurosaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, (s + i), 1);
		i++;
	}
}

// int	main(void)
// {
// 	char	*str = "abcdef";
// 	ft_putstr_fd(str, 1);
// 	return (0);
// }
// gcc -Wall -Wextra -Werror ft_putstr_fd.c