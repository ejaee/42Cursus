/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:48:34 by ejachoi           #+#    #+#             */
/*   Updated: 2022/08/23 22:39:34 by ejachoi          ###   ########.fr       */
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
		return (ft_print_str(va_arg(*ap, char *), info));
	else if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(*ap, int), c, info));
	else if (c == 'u' || c == 'X' || c == 'x')
		return (ft_print_nbr(va_arg(*ap, unsigned int), c, info));
	else if (c == 'p')
		return \
		(ft_print_ptr(va_arg(*ap, unsigned long long), ft_baseset(c), info));
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
	info->flag_sep_zero = 0;
	info->print_len = 0;
	info->padding_len = 0;
	info->flag_minus = 0;
	info->impos_flag = 0;
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
	else if (c == '0' && !info->flag_sep_zero)
		info->zero = 1;
	else if (ft_isdigit((int)c) && info->prec == -1)
	{
		info->width = info->width * 10 + c - '0';
		info->flag_sep_zero = 1;
	}
	else if (c == '.')
	{
		info->prec = 0;
		info->flag_sep_zero = 1;
		info->zero = 0;
	}
	else if (ft_isdigit((int)c) && info->prec != -1)
		info->prec = info->prec * 10 + c - '0';
	else
		info->impos_flag = 1;
}

int	parse_percent(const char **format, va_list *ap, t_info *info)
{
	init_info(info);
	while (*++*format && !ft_strchr(TYPE, **format))
	{
		check_info(**format, info);
		if (info->impos_flag)
			break;
	}
	if (info->impos_flag)
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
		if (!info.impos_flag)
			++format;
		else
			init_info(&info);
	}
	return (info.total_print_len);
}

// int	main()
// {
// 	int a;

// 	a = printf("%2.6#13.2d", 345);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("%2.6#13.2d", 345);
// 	printf("\n--%d--\n\n", a);




// 	a = printf("%010.5d", -216);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("%010.5d", -216);
// 	printf("\n--%d--\n\n", a);

// 	// a = ft_printf("%2147483647d", 1);
// 	// printf("\n--%d--\n\n", a);
// }
