/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:01:17 by ejachoi           #+#    #+#             */
/*   Updated: 2022/08/24 15:02:05 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str, t_info *info)
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

int	ft_check_str(char *str, t_info *info)
{
	if (str == NULL)
		str = "(null)";
	info->print_len = ft_strlen((const char *)str);
	if (info->prec > -1 && info->prec < info->print_len)
		info->print_len = info->prec;
	info->padding_len = info->width - info->print_len;
	if (print_str(str, info) == -1)
		return (-1);
	if (info->width > info->print_len)
		return (info->width);
	else
		return (info->print_len);
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
