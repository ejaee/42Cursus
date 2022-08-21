/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:48:34 by ejachoi           #+#    #+#             */
/*   Updated: 2022/08/21 22:34:10 by choiejae         ###   ########.fr       */
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
		return (ft_print_str(va_arg(*ap, unsigned char *), info));
	else if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(*ap, int), c, info));
	else if (c == 'u' || c == 'X' || c == 'x')
		return (ft_print_nbr(va_arg(*ap, unsigned int), c, info));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(*ap, unsigned long long)));
	else
		return (-1);
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
	else if (c == '0' && !info->flag)
		info->zero = 1;
	else if (ft_isdigit((int)c) && info->prec == -1)
	{
		info->width = info->width * 10 + c - '0';
		info->flag = 1;
	}
	else if (c == '.')
		info->prec = 0;
	else if (ft_isdigit((int)c) && info->prec != -1)
		info->prec = info->prec * 10 + c - '0';
}

void init_info(t_info *info)
{
	info->hash = 0; // #
    info->space = 0; // ' '
    info->sign = 0; // +
    info->left = 0; // -
	info->zero = 0; // 0
    info->width = 0; // [max]
    info->prec = -1; // [min]
	info->flag = 0; // nbr flag
	info->print_len = 0;
	info->padding_len = 0;
	info->flag_minus = 0;
}

int	ft_printf(const char *format, ...)
{
	int		printed_len;
	int		check_fail;
	t_info	info;
	va_list	ap;

	printed_len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			init_info(&info);
			while (*++format && !ft_strchr(TYPE, *format))
				check_info(*format, &info);
			check_fail = check_type(*format, &ap, &info);
			if (check_fail == -1)
				return (-1);
			printed_len += check_fail;
		}
		else
		{
			init_info(&info);
			check_fail = ft_print_chr((int)*format, &info);
			if (check_fail == -1)
				return (-1);
			printed_len++;
		}
		format++;
	}
	return (printed_len);
}

// int	main()
// {
// 	int a;

// 	a = printf(" %04d ", -14);
// 	printf("\n--%d--\n", a);
// 	a = ft_printf(" %04d ", -14);
// 	printf("\n--%d--\n", a);

// }
