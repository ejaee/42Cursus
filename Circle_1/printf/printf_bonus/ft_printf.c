/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:48:34 by ejachoi           #+#    #+#             */
/*   Updated: 2022/08/24 15:21:32 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(const char c, va_list *ap, t_info *info)
{
	if (c == 'c')
		return (ft_print_chr(va_arg(*ap, int), info));
	else if (c == '%')
		return (ft_print_chr('%', info));
	else if (c == 's')
		return (ft_check_str(va_arg(*ap, char *), info));
	else if (c == 'd' || c == 'i')
		return (ft_check_nbr(va_arg(*ap, int), c, info));
	else if (c == 'u' || c == 'X' || c == 'x')
		return (ft_check_nbr(va_arg(*ap, unsigned int), c, info));
	else if (c == 'p')
		return \
		(ft_check_ptr(va_arg(*ap, unsigned long long), ft_baseset(c), info));
	else
		return (-1);
}

void	init_info(t_info *info)
{
	info->hash = 0;
	info->space = 0;
	info->sign = 0;
	info->left = 0;
	info->zero = 0;
	info->width = 0;
	info->prec = -1;
	info->flag_receiving_input = 0;
	info->print_len = 0;
	info->padding_len = 0;
	info->flag_minus = 0;
	info->flag_impos = 0;
}

void	check_info(const char c, t_info *info)
{
	if (c == '#')
		info->hash = 1;
	else if (c == ' ' && info->sign == 0)
		info->space = 1;
	else if (c == '+')
		info->sign = 1;
	else if (c == '-')
		info->left = 1;
	else if (c == '0' && !info->flag_receiving_input)
		info->zero = 1;
	else if (ft_isdigit((int)c) && info->prec == -1)
	{
		info->width = info->width * 10 + c - '0';
		info->flag_receiving_input = 1;
	}
	else if (c == '.')
	{
		info->prec = 0;
		info->flag_receiving_input = 1;
		info->zero = 0;
	}
	else if (ft_isdigit((int)c) && info->prec != -1)
		info->prec = info->prec * 10 + c - '0';
	else
		info->flag_impos = 1;
}

int	parse_percent(const char **format, va_list *ap, t_info *info)
{
	init_info(info);
	while (*++*format && !ft_strchr(TYPE, **format))
	{
		check_info(**format, info);
		if (info->flag_impos)
			break ;
	}
	if (info->flag_impos)
		return (info->total_print_len);
	if (info->zero && info->left)
		info->zero = 0;
	info->total_print_fail = check_type(**format, ap, info);
	if (info->total_print_fail == -1)
		return (-1);
	return (info->total_print_fail);
}

int	ft_printf(const char *format, ...)
{
	t_info	info;
	va_list	ap;

	info.total_print_len = 0;
	info.total_print_fail = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			info.total_print_len += parse_percent(&format, &ap, &info);
		else
		{
			init_info(&info);
			info.total_print_fail = ft_print_chr((int)*format, &info);
			if (info.total_print_fail == -1)
				return (-1);
			info.total_print_len++;
		}
		if (!info.flag_impos)
			++format;
		else
			init_info(&info);
	}
	va_end(ap);
	return (info.total_print_len);
}
