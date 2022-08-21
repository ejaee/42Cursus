/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:48:51 by choiejae          #+#    #+#             */
/*   Updated: 2022/08/21 22:33:57 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_print_hash(const char type)
{
	int	res;

	res = 0;
	if (type == 'X')
	{
		if (write (1, "0X", 2) == -1)
			return (-1);
		res = 2;
	}
	else if (type == 'x')
	{
		if (write (1, "0x", 2) == -1)
			return (-1);
		res = 2;
	}
	return (res);
}

int	ft_print_space(long long nbr)
{
	int res;

	res = 0;
	if (nbr >= 0)
	{
		res = write (1, " ", 1);
		if (res == -1)
			return (-1);
	}
	return (res);
}

int	ft_print_flag(long long nbr, const char type, t_info *info)
{
	if (info->hash)
	{
		if (ft_print_hash(type) == -1)
			return (-1);
	}
	else if (info->space && (type != 'X' || type != 'x'))
	{
		if (ft_print_space(nbr) == -1)
			return (-1);
	}
	return (0);
}

int	ft_print_chr(int c, t_info *info)
{
	if (info->left)
	{
		if (write (1, &c, 1) == -1)
			return (-1);
		info->padding_len = info->width - 1;
		if (ft_print_width(info) == -1)
			return (-1);
	}
	else
	{
		info->padding_len = info->width - 1;
		if (ft_print_width(info) == -1)
			return (-1);
		if (write (1, &c, 1) == -1)
			return (-1);
	}
	if (info->width)
		return (info->width);
	return (1);
}

int	ft_print_str2(unsigned char *str, t_info *info)
{
	int	len;

	len = info->print_len;
	if (!info->left)
	{
		if (ft_print_width(info) == -1)
			return (-1);
		while (len--)
			if (write (1, str++, 1) == -1)
				return (-1);
	}
	else
	{
		while (len--)
			if (write (1, str++, 1) == -1)
				return (-1);
		if (ft_print_width(info) == -1)
			return (-1);
	}
	return (0);
}

int	ft_print_str(unsigned char *str, t_info *info)
{
	if (str == NULL)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	info->print_len = ft_strlen((const char *)str);
	if (info->prec > -1 && info->prec < info->print_len)
		info->print_len = info->prec;
	info->padding_len = info->width - info->print_len;
	if (ft_print_str2(str, info) == -1)
		return (-1);
	if (info->width > info->print_len)
		return (info->width);
	else
		return (info->print_len);
}

int ft_print_nbr2(long long nbr, const char type, t_info *info)
{
	char	*base;

	base = ft_baseset(type);
	if (!info->left)
	{
		ft_print_sign(nbr, info);
		if (ft_print_width(info) == -1)
			return (-1);
		if (ft_print_flag(nbr, type, info) == -1)
			return (-1);
		if (ft_putnbr_base(nbr, base, info) == -1)
			return (-1);
	}
	else
	{
		ft_print_sign(nbr, info);
		if (ft_print_flag(nbr, type, info) == -1)
			return (-1);
		if (ft_putnbr_base(nbr, base, info) == -1)
			return (-1);
		if (ft_print_width(info) == -1)
			return (-1);
	}
	return (0);
}

int	ft_print_nbr(long long nbr, const char type, t_info *info)
{
	if (nbr == 0 && (type == 'X' || type == 'x'))
	{
		if (write (1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	if (type == 'd' || type == 'i' || type == 'u')
		info->print_len = ft_strlen_base(nbr, 10, info);
	else
		info->print_len = ft_strlen_base(nbr, 16, info);
	if (info->prec > info->print_len)
		info->print_len = info->prec;
	if (info->flag_minus)
		info->print_len++;
	info->padding_len = info->width - info->print_len;
	if (ft_print_nbr2(nbr, type, info) == -1)
		return (-1);
	if (info->width > info->print_len)
		return (info->width);
	else
		return (info->print_len);
}

int	ft_print_ptr(unsigned long long ptr)
{
	char	*hex;
	char	stack[17];
	int		idx;
	int		res;

	hex = "0123456789abcdef";
	idx = 0;
	if (write (1, "0x", 2) == -1)
		return (-1);
	if (ptr == 0)
	{
		if (write (1, "0", 1) == -1)
			return (-1);
		return (3);
	}
	while (ptr)
	{
		stack[idx++] = hex[ptr % 16];
		ptr /= 16;
	}
	res = idx--;
	while (idx >= 0)
		if (write (1, &stack[idx--], 1) == -1)
			return (-1);
	return (res + 2);
}
