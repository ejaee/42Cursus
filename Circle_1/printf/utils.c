/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:35:13 by choiejae          #+#    #+#             */
/*   Updated: 2022/08/16 15:50:37 by choiejae         ###   ########.fr       */
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

int	ft_putnbr_base(long long num, char *base)
{
	int	type;

	type = ft_strlen(base);
	if (num < 0)
	{
		if (write (1, "-", 1) == -1)
			return (-1);
		num *= -1;
	}
	if (num < (long long)type)
	{
		if (write (1, &base[num], 1) == -1)
			return (-1);
	}
	else
	{
		ft_putnbr_base(num / (long long)type, base);
		ft_putnbr_base(num % (long long)type, base);
	}
	return (0);
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
