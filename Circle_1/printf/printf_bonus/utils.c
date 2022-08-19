/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:35:13 by choiejae          #+#    #+#             */
/*   Updated: 2022/08/19 21:33:42 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

int	ft_strlen_base(long long num, int type)
{
	int	cnt;

	cnt = 1;
	if (num < 0)
	{
		cnt++;
		num *= -1;
	}
	while (1)
	{
		if (num < type)
			break ;
		num /= type;
		cnt++;
	}
	return (cnt);
}

int	ft_putnbr_base(long long nbr, char *base, int base_size)
{
	char	stack[12];
	int		idx;
	int		res;

	idx = 0;
	if (nbr < 0)
	{
		if (write (1, "-", 1) == -1)
			return (-1);
		nbr *= -1;
	}
	if (nbr == 0)
	{
		if (write (1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	while (nbr)
	{
		stack[idx++] = base[nbr % base_size];
		nbr /= base_size;
	}
	res = idx--;
	while (idx >= 0)
		if (write (1, &stack[idx--], 1) == -1)
			return (-1);
	return (res);
}

char	*ft_baseset(char type)
{
	if (type == 'd' || type == 'i' || type == 'u')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else if (type == 'X')
		return ("0123456789ABCDEF");
	return (0);
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


int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}
