/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:20:56 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/12/07 01:40:48 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	if (size == 0 || count == 0)
	{
		size = 1;
		count = 1;
	}
	if (SIZE_MAX / size < count)
		return (NULL);
	temp = malloc(sizeof(char) * size * count);
	if (!temp)
		return (NULL);
	ft_bzero(temp, count * size);
	return (temp);
}

// int	main(void)
// {
// 	char 	*ch;
// 	// int		i;

//     ch = (char*)calloc(1, 1);
// 	// ch = (char*)ft_calloc(1, 1);
// 	scanf("%s\n", ch);
//     printf("%s\n",ch);
//     free(ch);
//     return 0;
// }
// gcc -Wall -Wextra -Werror ft_calloc.c ft_bzero.c