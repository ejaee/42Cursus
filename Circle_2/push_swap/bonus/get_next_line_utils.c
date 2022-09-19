/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:20:46 by choiejae          #+#    #+#             */
/*   Updated: 2022/09/05 19:54:24 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strlen(const char *s)
{
	int	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		idx;
	int		size_s1;
	int		size_s2;
	char	*connected_s;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	connected_s = (char *)malloc(sizeof(char) * (size_s1 + size_s2) + 1);
	if (!connected_s)
		return (NULL);
	idx = 0;
	while (*s1)
		connected_s[idx++] = *s1++;
	while (*s2)
		connected_s[idx++] = *s2++;
	connected_s[idx] = '\0';
	return (connected_s);
}

char	*ft_strndup(const char *src, int start, int num)
{
	char	*temp;
	int		idx_s;
	int		idx_t;

	idx_s = 0;
	idx_t = 0;
	temp = (char *)malloc(sizeof(char) * num + 1);
	if (!temp)
		return (NULL);
	while (src[idx_s] && idx_t < num)
		temp[idx_t++] = src[start + idx_s++];
	temp[idx_t] = '\0';
	return (temp);
}

long long	ft_atoi(const char *str)
{
	int			sign;
	long long	res;

	sign = 1;
	res = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while (*str && ('0' <= *str && *str <= '9'))
	{
		res = res * 10 + (*str - '0');
		++str;
	}
	res *= sign;
	return (res);
}

void	ft_putstr(char *str)
{
	while (*str)
		write (1, str++, 1);
}
