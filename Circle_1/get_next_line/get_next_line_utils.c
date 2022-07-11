/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:00:42 by ejachoi           #+#    #+#             */
/*   Updated: 2022/07/11 12:06:06 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
		s++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	size_t	i;
	char	*total_s;

	if (!s1 || !s2)
		return (0);
	i = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	total_s = malloc (total_len + 1);
	if (!total_s)
		return (0);
	while (i < ft_strlen(s1))
	{
		total_s[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		total_s[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	total_s[total_len] = '\0';
	return (total_s);
}

