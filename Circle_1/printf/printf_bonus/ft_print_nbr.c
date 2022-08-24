/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:44:22 by ejachoi           #+#    #+#             */
/*   Updated: 2022/08/24 14:55:00 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	strlen_base(long long nbr, int type, t_info *info)
{
	int	cnt;

	cnt = 1;
	info->flag_minus = 0;
	if (nbr < 0)
	{
		info->flag_minus = 1;
		nbr *= -1;
	}
	while (1)
	{
		if (nbr < type)
			break ;
		nbr /= type;
		cnt++;
	}
	return (cnt);
}

int	putnbr_base(long long nbr, char *base, int base_size, t_info *info)
{
	char	stack[12];
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
		stack[idx++] = base[nbr % base_size];
		nbr /= base_size;
	}
	if (ft_print_prec(idx, info) == -1)
		return (-1);
	while (--idx >= 0)
		if (write (1, &stack[idx], 1) == -1)
			return (-1);
	return (0);
}

int	print_right_nbr(long long nbr, const char type, t_info *info)
{
	int	base_size;

	if (type == 'd' || type == 'i' || type == 'u')
		base_size = 10;
	else
		base_size = 16;
	if (ft_print_width(info) == -1 || ft_print_sign(nbr, info) == -1 \
		|| ft_check_flag(nbr, type, info) == -1)
		return (-1);
	if (!(!info->prec && !nbr))
		if (putnbr_base(nbr, ft_baseset(type), base_size, info) == -1)
			return (-1);
	return (0);
}

int	print_left_nbr(long long nbr, const char type, t_info *info)
{
	int	base_size;

	if (type == 'd' || type == 'i' || type == 'u')
		base_size = 10;
	else
		base_size = 16;
	if (ft_print_sign(nbr, info) == -1 || ft_check_flag(nbr, type, info) == -1)
		return (-1);
	if (info->zero)
	{
		if (ft_print_width(info) == -1)
			return (-1);
		if (!(!info->prec && !nbr))
			if (putnbr_base(nbr, ft_baseset(type), base_size, info) == -1)
				return (-1);
	}
	else
	{
		if (!(!info->prec && !nbr))
			if (putnbr_base(nbr, ft_baseset(type), base_size, info) == -1)
				return (-1);
		if (ft_print_width(info) == -1)
			return (-1);
	}
	return (0);
}

int	ft_check_nbr(long long nbr, const char type, t_info *info)
{
	if (type == 'd' || type == 'i' || type == 'u')
		info->print_len = strlen_base(nbr, 10, info);
	else
		info->print_len = strlen_base(nbr, 16, info);
	if (info->prec > info->print_len)
		info->print_len = info->prec;
	if (info->hash && nbr)
		info->print_len += 2;
	if (!info->prec && !nbr)
		info->print_len = 0;
	if (info->flag_minus || info->sign || info->space)
		info->print_len++;
	info->padding_len = info->width - info->print_len;
	if (!info->left && !info->zero)
	{
		if (print_right_nbr(nbr, type, info) == -1)
			return (-1);
	}
	else if (info->left || (!info->left && info->zero))
		if (print_left_nbr(nbr, type, info) == -1)
			return (-1);
	if (info->width > info->print_len)
		return (info->width);
	else
		return (info->print_len);
}
