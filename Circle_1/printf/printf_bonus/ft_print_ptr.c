/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:49:57 by ejachoi           #+#    #+#             */
/*   Updated: 2022/08/24 14:54:07 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptrlen_base(unsigned long long ptr)
{
	int	cnt;

	cnt = 0;
	if (ptr == 0)
		return (1);
	while (ptr)
	{
		cnt++;
		ptr /= 16;
	}
	return (cnt);
}

int	putptr_base(unsigned long long nbr, char *base, t_info *info)
{
	char	stack[20];
	int		idx;

	idx = 0;
	if (nbr == 0)
	{
		if (ft_print_prec(1, info) == -1)
			return (-1);
		if (write (1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	if (nbr < 0)
		nbr *= -1;
	while (nbr)
	{
		stack[idx++] = base[nbr % 16];
		nbr /= 16;
	}
	if (ft_print_prec(idx, info) == -1)
		return (-1);
	while (--idx >= 0)
		if (write (1, &stack[idx], 1) == -1)
			return (-1);
	return (0);
}

int	print_ptr(unsigned long long ptr, char *hex, t_info *info)
{
	if (info->left || (!info->left && info->zero))
	{
		if (write (1, "0x", 2) == -1)
			return (-1);
		if (!(!info->prec && !ptr))
		{
			if (putptr_base(ptr, hex, info) == -1)
				return (-1);
		}
		if (ft_print_width(info) == -1)
			return (-1);
	}
	else if (!info->left)
	{
		if (ft_print_width(info) == -1)
			return (-1);
		if (write (1, "0x", 2) == -1)
			return (-1);
		if (!(!info->prec && !ptr))
		{
			if (putptr_base(ptr, hex, info) == -1)
				return (-1);
		}
	}
	return (0);
}

int	ft_check_ptr(unsigned long long ptr, char *hex, t_info *info)
{
	info->print_len = ptrlen_base(ptr);
	if (info->prec > info->print_len)
		info->print_len = info->prec;
	if (!info->prec && !ptr)
		info->print_len = 0;
	info->padding_len = info->width - info->print_len - 2;
	print_ptr(ptr, hex, info);
	if (info->padding_len > 0)
		return (info->width);
	return (info->print_len + 2);
}
