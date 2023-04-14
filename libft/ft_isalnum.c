/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurosaw <tkurosaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:45:49 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/12/10 20:45:26 by tkurosaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

// int main(void)
// {
//     for (int i = 0; i <= 127; i++)
// 	{
//         printf("isalnum: 	i:%d, '%c' _ %d\n", i, i, isalnum(i));
//         printf("ft_isalnum: 	i:%d '%c' _ %d\n", i, i, ft_isalnum(i));
// 	}
// }
// gcc -Wall -Wextra -Werror ft_isalnum.c