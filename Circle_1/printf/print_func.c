/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:48:51 by choiejae          #+#    #+#             */
/*   Updated: 2022/08/16 20:59:14 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_print_string(unsigned char *str)
{
	int	len;

	if (str == NULL)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	len = ft_strlen((char *)str);
	while (*str)
	{
		if (write (1, str++, 1) == -1)
			return (-1);
	}
	return (len);
}

int	ft_print_nbr(long long nbr, const char type)
{
	int		res;
	char	*base;
	int		base_size;

	if (nbr == 0)
	{
		if (write (1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	base = ft_baseset(type);
	base_size = ft_strlen(base);
	if (ft_putnbr_base(nbr, base, base_size) == -1)
		return (-1);
	if (type == 'd' || type == 'i' || type == 'u')
		res = ft_strlen_base(nbr, 10);
	else
		res = ft_strlen_base(nbr, 16);
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
