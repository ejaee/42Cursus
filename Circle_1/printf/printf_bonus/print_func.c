/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:48:51 by choiejae          #+#    #+#             */
/*   Updated: 2022/08/19 21:45:39 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_chr(int c)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_print_str(unsigned char *str, t_info *info)
{
	int		len;
	int 	str_len;
	char	c;

	if (str == NULL)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	str_len = ft_strlen((const char *)str);
	len = 0;
	c = ' ';
	if (!info->left)
	{
		if (info->zero)
			c = '0';
		while (str_len < info->width--)
		{
		if (write (1, &c, 1) == -1)
			return (-1);
		len++;
		}
	}
	else if (info->left)
		len = info->width - str_len;
	while (*str && info->prec--)
	{
		if (write (1, str++, 1) == -1)
			return (-1);
		len++;
	}
	return (len);
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

int	ft_print_sign(long long nbr)
{
	int res;

	res = 0;
	if (nbr > 0)
	{
		res = write (1, "+", 1);
		if ( res == -1)
			return (-1);
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
	int res;

	res = 0;
	if (info->hash)
	{
		res = ft_print_hash(type);
		if (res == -1)
			return (-1);
	}
	else if (info->sign)
	{
	res = ft_print_sign(nbr);
		if (res == -1)
			return (-1);
	}
	else if (info->space && (type != 'X' || type != 'X'))
	{
	res = ft_print_space(nbr);
		if (res == -1)
			return (-1);
	}
	return (res);
}

int	ft_print_pwidth(int res, t_info *info)
{
	char	c;
	int len;

	c = '0';
	len = res;
	while (++len <= info->prec)
	{
		// if (info->zero && !info->prec)
		// 	c = '0';
		if (write (1, &c, 1) == -1)
			return (-1);
		res++;
	}
	return (res);
}

int	ft_print_width(int res, t_info *info)
{
	char	c;
	int len;

	c = ' ';
	len = res;
	while (++len <= info->width)
	{
		if (info->zero && !info->left)
			c = '0';
		if (write (1, &c, 1) == -1)
			return (-1);
		res++;
	}
	return (res);
}

int ft_print_prec(long long nbr, char *base, int res, t_info *info)
{
	int	base_size;

	base_size = ft_strlen(base);
	res = ft_print_pwidth(res, info);
	if (ft_putnbr_base(nbr, base, base_size) == -1)
		return (-1);
	return (res);
}

int ft_print_left(long long nbr, char *base, int res, t_info *info)
{
	int	base_size;

	base_size = ft_strlen(base);
	if (!info->left)
	{
		res = ft_print_width(res, info);
		if (ft_putnbr_base(nbr, base, base_size) == -1)
			return (-1);
	}
	else
	{
		if (ft_putnbr_base(nbr, base, base_size) == -1)
			return (-1);
		res = ft_print_width(res, info);
	}
	return (res);
}

int	ft_print_nbr(long long nbr, const char type, t_info *info)
{
	int		res;
	int		len;
	char	*base;

	if (nbr == 0 && (type == 'X' || type == 'x'))
	{
		if (write (1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	res = ft_print_flag(nbr, type, info);
	base = ft_baseset(type);
	if (res == -1)
		return (-1);
	if (type == 'd' || type == 'i' || type == 'u')
		res += ft_strlen_base(nbr, 10);
	else
		res += ft_strlen_base(nbr, 16);
	if (info->prec != -1)
	{
		len = ft_print_prec(nbr, base, res, info);
		if (len == -1)
			return (-1);
		res = len;
	}
	else
	{
		len = ft_print_left(nbr, base, res, info);
		if (len == -1)
			return (-1);
		res = len;
	}
	return (res);
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
