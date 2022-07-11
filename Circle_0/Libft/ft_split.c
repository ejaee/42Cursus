/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:09:07 by ejachoi           #+#    #+#             */
/*   Updated: 2022/07/09 20:21:51 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *str, char c)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		while (*str && *str == c)
			++str;
		if (*str && *str != c)
		{
			++cnt;
			while (*str && *str != c)
				++str;
		}
	}
	return (cnt);
}

static char	*ft_strlen_dup(char const **str, char c)
{
	int		word_len;
	int		cnt;
	char	*copy;

	word_len = 0;
	while (*(*str) && *(*str) != c)
	{
		++word_len;
		++*str;
	}
	*str -= word_len;
	copy = malloc(sizeof(char) * (word_len + 1));
	if (!copy)
		return (0);
	cnt = 0;
	while (*(*str) && ++cnt <= word_len)
		*copy++ = *(*str)++;
	*copy = '\0';
	copy -= word_len;
	return (copy);
}

static char	**free_copy(char **str, int size)
{
	int	index;

	index = -1;
	while (++index < size)
		free(str[index]);
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**copy;
	int		words;
	int		index;

	if (!s)
		return (0);
	words = count_word(s, c);
	copy = malloc(sizeof(char *) * (words + 1));
	if (!copy)
		return (0);
	index = -1;
	while (++index < words)
	{
		while (*s && *s == c)
			++s;
		copy[index] = ft_strlen_dup(&s, c);
		if (!copy[index])
			return (free_copy(copy, index));
	}
	copy[index] = 0;
	return (copy);
}
