/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:40:23 by ejachoi           #+#    #+#             */
/*   Updated: 2022/08/24 14:41:41 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_prec(int idx, t_info *info)
{
	int	remain_prec;

	remain_prec = info->prec;
	while (idx < remain_prec--)
	{
		if (write (1, "0", 1) == -1)
			return (-1);
	}
	return (0);
}

int	ft_print_width(t_info *info)
{
	char	c;
	int		len;

	c = ' ';
	if (info->zero && !info->left)
		c = '0';
	len = info->padding_len;
	while (len-- > 0)
	{
		if (write (1, &c, 1) == -1)
			return (-1);
	}
	return (0);
}

int	ft_print_sign(long long nbr, t_info *info)
{
	if (nbr < 0)
	{
		if (write (1, "-", 1) == -1)
			return (-1);
		return (0);
	}
	if (info->sign)
	{
		if (write (1, "+", 1) == -1)
			return (-1);
		return (0);
	}
	return (0);
}

int	ft_print_hash(long long nbr, const char type)
{
	if (nbr)
	{
		if (type == 'X')
		{
			if (write (1, "0X", 2) == -1)
				return (-1);
		}
		else if (type == 'x')
		{
			if (write (1, "0x", 2) == -1)
				return (-1);
		}
	}
	return (1);
}

int	ft_print_space(long long nbr, t_info *info)
{
	int	res;

	res = 0;
	if (nbr >= 0 && !info->sign)
	{
		res = write (1, " ", 1);
		if (res == -1)
			return (-1);
	}
	return (res);
}
