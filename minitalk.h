/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:14:21 by kurosawaits       #+#    #+#             */
/*   Updated: 2023/04/02 21:14:40 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define LIBFT_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <libc.h>

void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *);
int		ft_atoi(const char *str);

#endif