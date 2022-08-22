/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:48:51 by choiejae          #+#    #+#             */
/*   Updated: 2022/08/22 20:32:21 by ejachoi          ###   ########.fr       */
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

int	ft_print_str2(char *str, t_info *info)
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

int	ft_print_str(char *str, t_info *info)
{
	if (str == NULL)
		str = "(null)";
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
	if (!info->left && !info->zero)
	{
		if (ft_print_width(info) == -1	|| ft_print_sign(nbr, info) == -1 || ft_print_flag(nbr, type, info) == -1)
			return (-1);
		if (!(!info->prec && !nbr))
			if (ft_putnbr_base(nbr, ft_baseset(type), info) == -1)
				return (-1);
		return (0);
	}
	else if (info->left || (!info->left && info->zero))
		if (ft_print_sign(nbr, info) == -1 || ft_print_flag(nbr, type, info) == -1)
			return (-1);
		if (info->zero)
		{
			if (ft_print_width(info) == -1)
				return (-1);
			if (!(!info->prec && !nbr))
				if (ft_putnbr_base(nbr, ft_baseset(type), info) == -1)
					return (-1);
		}
		else
		{
			if (!(!info->prec && !nbr))
				if (ft_putnbr_base(nbr, ft_baseset(type), info) == -1)
					return (-1);
			if (ft_print_width(info) == -1)
				return (-1);
		}
	return (0);
}

int	ft_print_nbr(long long nbr, const char type, t_info *info)
{
	if (type == 'd' || type == 'i' || type == 'u')
		info->print_len = ft_strlen_base(nbr, 10, info);
	else
		info->print_len = ft_strlen_base(nbr, 16, info);
	if (info->prec > info->print_len)
		info->print_len = info->prec;
	if (info->flag_minus)
		info->print_len++;
	if (!info->prec && !nbr)
		info->print_len = 0;
	info->padding_len = info->width - info->print_len;
// printf("\n==width : %d==\n", info->width);
// printf("\n==print : %d==\n", info->print_len);
// printf("\n==padding : %d==\n\n", info->padding_len);
	if (ft_print_nbr2(nbr, type, info) == -1)
		return (-1);
	if (info->width > info->print_len)
		return (info->width);
	else
		return (info->print_len);
}

int	ft_printlen_ptr(unsigned long long ptr)
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

int	ft_print_ptr2(unsigned long long ptr, char *hex, t_info *info)
{
	if (info->left || (!info->left && info->zero))
	{
		if (write (1, "0x", 2) == -1)
			return (-1);
		if (!(!info->prec && !ptr))
		{
			if (ft_putnbr_base(ptr, hex, info) == -1)
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
			if (ft_putnbr_base(ptr, hex, info) == -1)
				return (-1);
		}
	}
	return (0);
}

int	ft_print_ptr(unsigned long long ptr, char *hex, t_info *info)
{
	int		idx;

	idx = 0;
	// cnt only nbr len (not cnt '0x')
	info->print_len = ft_printlen_ptr(ptr);
	if (info->prec > info->print_len)
		info->print_len = info->prec;
	if (!info->prec && !ptr)
		info->print_len = 0;
	info->padding_len = info->width - info->print_len - 2;

	ft_print_ptr2(ptr, hex, info);
	if (info->padding_len > 0)
		return (info->width);
	return (info->print_len + 2);
}
