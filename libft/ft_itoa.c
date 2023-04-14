/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 05:18:55 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/12/07 09:31:12 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*convert(int a, int b, size_t c);

char	*ft_itoa(int n)
{
	int		sign;
	size_t	digit;

	digit = 0;
	sign = 1;
	if (n == 0)
		return (ft_strdup("0"));
	else if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	else if (n < 0 && n != INT_MIN)
	{
		sign = -1;
		n *= -1;
		digit++;
	}
	return (convert(n, sign, digit));
}

static char	*convert(int n, int sign, size_t digit)
{
	int		quotient;
	char	*re_ptr;

	quotient = n;
	while (quotient > 0)
	{
		quotient /= 10;
		digit++;
	}
	re_ptr = (char *)malloc(sizeof(char) * (digit + 1));
	if (!re_ptr)
		return (NULL);
	re_ptr[digit] = '\0';
	digit--;
	while (n > 0)
	{
		re_ptr[digit] = n % 10 + '0';
		n /= 10;
		digit--;
	}
	if (sign == -1)
		re_ptr[digit] = '-';
	return (re_ptr);
}

// int	main(void)
// {
// 	int		number;
// 	char	*re_ptr;

// 	number = INT_MIN;
// 	re_ptr = ft_itoa(number);
// 	printf("ft_itoa: %s\n", re_ptr);
// 	return (0);
// }
// gcc -Wall -Wextra -Werror ft_itoa.c ft_substr.c
// ft_strlen.c ft_strdup.c ft_strlcpy.c