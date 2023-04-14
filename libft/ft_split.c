/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 00:20:05 by kurosawaits       #+#    #+#             */
/*   Updated: 2023/02/20 16:42:04 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*check(char const *a, char b);
static char			*set_word(char *a, char b);
static void			*free_memory(char **a, size_t i);
static size_t		counter(char const *a, char b);

char	**ft_split(char const *s, char c)
{
	char	**return_value;
	size_t	count;
	size_t	num_word;

	if (!s)
		return (NULL);
	num_word = counter(s, c);
	return_value = (char **)malloc(sizeof(char *) * (num_word + 1));
	if (!return_value)
		return (NULL);
	count = 0;
	while (*s == c)
		s++;
	while (count < num_word)
	{
		return_value[count] = set_word((char *)s, c);
		if (!return_value[count])
			return (free_memory(return_value, count));
		s = check(s, c);
		count++;
	}
	return_value[count] = NULL;
	return (return_value);
}

static char	*set_word(char *s, char c)
{
	char	*str;
	char	*word_front;
	size_t	size;

	size = 0;
	word_front = s;
	while (*s != c && *s != '\0')
	{
		s++;
		size++;
	}
	str = ft_substr(word_front, 0, size);
	return (str);
}

static const char	*check(char const *s, char c)
{
	while (*s != c && *s)
		s++;
	while (*s == c && *s)
		s++;
	return (s);
}

static size_t	counter(char const *s, char c)
{
	size_t	word_count;
	int		position_s;
	int		in_word;

	in_word = 0;
	position_s = 0;
	word_count = 0;
	while (*(s + position_s))
	{
		if (s[position_s] == c)
			in_word = 0;
		else if (s[position_s] != c && in_word == 0)
		{
			word_count++;
			in_word = 1;
		}
		position_s++;
	}
	return (word_count);
}

static void	*free_memory(char **return_value, size_t i)
{
	while (i--)
		free(return_value[i]);
	free(return_value);
	return (NULL);
}

// int	main(void)
// {
// 	// char	*ptr = "aaabbcccbbd";
// 	char	**str;
// 	size_t	i;
// 	size_t	j;
// 	char * splitme = strdup("Tripouille");

// 	printf("splitme: %s\n", splitme);
// 	str = ft_split(splitme, 'u');
// 	i = counter(splitme, 'u');
// 	j = 0;
// 	while (j < i)
// 	{
// 		printf("%s\n", str[j]);
// 		j++;
// 	}
// 	return (0);
// }
// gcc -Wall -Wextra -Werror ft_split.c ft_strlen.c 
// ft_strlcpy.c ft_substr.c ft_strdup.c