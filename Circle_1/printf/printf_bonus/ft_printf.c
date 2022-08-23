/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:48:34 by ejachoi           #+#    #+#             */
/*   Updated: 2022/08/23 12:20:25 by choiejae         ###   ########.fr       */
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
		return (ft_print_ptr(va_arg(*ap, unsigned long long), ft_baseset(c), info));
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
		info->zero = 0;
	}
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
	info->flag_sep_zero = 0; // nbr flag
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



	// // p - width
	// a = printf("%5p", 12);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%5p", 12);
	// printf("\n--%d--\n\n", a);

	// // s - width || prec

	// a = printf("%.3s", NULL);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%.3s", NULL);
	// printf("\n--%d--\n\n", a);

	// a = printf("%012.0d", -12345);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%012.0d", -12345);
	// printf("\n--%d--\n\n", a);

	// a = printf("%012.2d", -12345);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%012.2d", -12345);
	// printf("\n--%d--\n\n", a);

	// a = printf("%12.0s", "-12345");
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%12.0s", "-12345");
	// printf("\n--%d--\n\n", a);

	// a = printf("%012.2d", -12345);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%012.2d", -12345);
	// printf("\n--%d--\n\n", a);

	// a = printf("%012.8d", -12345);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%012.8d", -12345);
	// printf("\n--%d--\n\n", a);

	// a = printf("%03.8d", -12345);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%03.8d", -12345);
	// printf("\n--%d--\n\n", a);

	// a = printf("%-012.2d", -12345);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%-012.2d", -12345);
	// printf("\n--%d--\n\n", a);

	// a = printf("%-012.8d", -12345);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%-012.8d", -12345);
	// printf("\n--%d--\n\n", a);

	// a = printf("%-03.8d", -12345);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%-03.8d", -12345);
	// printf("\n--%d--\n\n", a);

	// printf("\n==========================\n");
	// p - check flag ' ' '0'


	// a = printf("%5p", 0); // '-' + '0' -> not left
	// printf("\n--%d--\n\n", a); // '  0x0'
	// a = ft_printf("%5p", 0);
	// printf("\n--%d--\n\n", a);

	// a = printf("% 5p", 0); // '-' + '0' -> not left
	// printf("\n--%d--\n\n", a); // '  0x0'
	// a = ft_printf("% 5p", 0);
	// printf("\n--%d--\n\n", a);

	// a = printf("%+5p", 0); // sign
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%+5p", 0);
	// printf("\n--%d--\n\n", a);

	// a = printf("%5p", 0); // '-' + '0' -> not left
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%5p", 0);
	// printf("\n--%d--\n\n", a);

	// a = printf("%-5p", 0); // '-' + '0' -> not left
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%-5p", 0);
	// printf("\n--%d--\n\n", a);

	// a = printf("%05p", 0); // applied 0 -> left
	// printf("\n--%d--\n\n", a); // and width zero "0x000"
	// a = ft_printf("%05p", 0);
	// printf("\n--%d--\n\n", a);

	// a = printf("%-05p", 0); // not applied ' '
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%-05p", 0);
	// printf("\n--%d--\n\n", a);

	// a = printf("% 05p", 0); // not applied ' '
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("% 05p", 0);
	// printf("\n--%d--\n\n", a);


	// a = printf("%0.0p", 2);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%0.0p", 2); // not print '0' -> '0x'
	// printf("\n--%d--\n\n", a);

	// a = printf("%0.0p", 0);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%0.0p", 0); // not print '0' -> '0x'
	// printf("\n--%d--\n\n", a);

	// a = printf("%0.0p", NULL);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%0.0p", NULL); // not print '0' -> '0x'
	// printf("\n--%d--\n\n", a);

	// a = printf("%0.2p", 0);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%0.2p", 0); // add print '0' -> 0x00 by prec
	// printf("\n--%d--\n\n", a); // prec is not included '0x'

	// a = printf("%0p", 12345);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%0p", 12345);
	// printf("\n--%d--\n\n", a);

	// a = printf("%0.2p", 12345);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%0.2p", 12345);
	// printf("\n--%d--\n\n", a);

	// a = printf("%0.8p", 12345);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%0.8p", 12345); // if prec > , add '0' like 0x00003039
	// printf("\n--%d--\n\n", a);

	// printf("\n==========================\n");
		// p - width || prec

	// a = printf("%5p", 0);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%5p", 0); // not count width
	// printf("\n--%d--\n\n", a);

	// a = printf("%.0p", 0);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%.0p", 0); // not print '0' -> '0x'
	// printf("\n--%d--\n\n", a);

	// a = printf("%.2p", 0);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%.2p", 0); // add print '0' -> 0x00 by prec
	// printf("\n--%d--\n\n", a); // prec is not included '0x'

	// a = printf("%p", 12345);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%p", 12345);
	// printf("\n--%d--\n\n", a);

	// a = printf("%.2p", 12345);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%.2p", 12345);
	// printf("\n--%d--\n\n", a);

	// a = printf("%.8p", 12345);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%.8p", 12345); // if prec > , add '0' like 0x00003039
	// printf("\n--%d--\n\n", a);

	//	p - width && prec

	// printf("\n==========================\n");

	// a = printf("%p", 12345);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%p", 12345);
	// printf("\n--%d--\n\n", a);

	// a = printf("%12.2p", 12345);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%12.2p", 12345);
	// printf("\n--%d--\n\n", a);

	// a = printf("%12.8p", 12345);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%12.8p", 12345);
	// printf("\n--%d--\n\n", a);

	// a = printf("%3.8p", 12345);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%3.8p", 12345);
	// printf("\n--%d--\n\n", a);

	// a = printf("%012.2d", -12345);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%012.2d", -12345);
	// printf("\n--%d--\n\n", a);

	// a = printf("%012.7d", 12345);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%012.7d", 12345);
	// printf("\n--%d--\n\n", a);

	// a = printf("%-012.2d", -12345);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%-012.2d", -12345);
	// printf("\n--%d--\n\n", a);

	// a = printf("%+12.2d", 12345);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%+12.2d", 12345);
	// printf("\n--%d--\n\n", a);

	// a = printf("%7d", -54);
	// printf("\n--%d--\n", a);
	// a = ft_printf("%7d", -54);
	// printf("\n--%d--\n\n", a);

	// a = printf("%07d", -54);
	// printf("\n--%d--\n", a);
	// a = ft_printf("%07d", -54);
	// printf("\n--%d--\n\n", a);

	// a = printf("%+07d", 54);
	// printf("\n--%d--\n", a);
	// a = ft_printf("%+07d", 54);
	// printf("\n--%d--\n\n", a);

	// a = printf("%07p", -54);
	// printf("\n--%d--\n", a);
	// a = ft_printf("%07p", -54);
	// printf("\n--%d--\n\n", a);

	// printf("\n==========================\n");

	// a = printf("%.0d", 0);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%.0d", 0);
	// printf("\n--%d--\n\n", a);

	// a = printf("%.d", 0);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%.d", 0);
	// printf("\n--%d--\n\n", a);

	// a = printf("%5.0d", 0);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%5.0d", 0);
	// printf("\n--%d--\n\n", a);

	// a = printf("%5.d", 0);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%5.d", 0);
	// printf("\n--%d--\n\n", a);

	// a = printf("%-5.0d", 0);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%-5.0d", 0);
	// printf("\n--%d--\n\n", a);

	// a = printf("%-5.d", 0);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%-5.d", 0);
	// printf("\n--%d--\n\n", a);

	// printf("\n==========================\n");


	// a = printf("this %d number", 173);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("this %d number", 173);
	// printf("\n--%d--\n\n", a);


// 	a = printf("%3x", 0);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("%3x", 0);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("%-3x", 0);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("%-3x", 0);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("%.3x", 0);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("%.3x", 0);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("%8.5x", 0);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("%8.5x", 0);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("%-8.5x", 0);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("%-8.5x", 0);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("%08.5x", 0);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("%08.5x", 0);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("%0-8.5x", 0);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("%0-8.5x", 0);
// 	printf("\n--%d--\n\n", a);


// 	a = printf("%.0x", 0);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("%.0x", 0);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("%.x", 0);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("%.x", 0);
// 	printf("\n--%d--\n\n", a);


// 	a = printf("%5.0x", 0);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("%5.0x", 0);
// 	printf("\n--%d--\n\n", a);

	// a = printf("%5.x", 0);
	// printf("\n--%d--\n\n", a);
	// a = ft_printf("%5.x", 0);
	// printf("\n--%d--\n\n", a);

	// printf("\n==========================\n");

// 	a = printf("% +8.5d", 34);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("%+8.5d", 34);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("% +8.5d", -34);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("%+8.5d", -34);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("% 0+8.3d", -8473);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("% 0+8.3d", -8473);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("% +5.0d", 0);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("% +5.0d", 0);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("% -7d", -14);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("% -7d", -14);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("% 07d", -54);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("% 07d", -54);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("% 8.5d", 0);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("% 8.5d", 0);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("% .0d", 0);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("% .0d", 0);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("% .5d", 0);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("% .5d", 0);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("% -8.0d", 34);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("% -8.0d", 34);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("% -8.5d", 34);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("% -8.5d", 34);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("% 8.3d", -8473);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("% 8.3d", -8473);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("% -8.5d", 34);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("% -8.5d", 34);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("this % d number", 17);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("this % d number", 17);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("% +.3i", 3723);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("% +.3i", 3723);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("% -+.3i", 3723);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("% -+.3i", 3723);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("% .3i", -3723);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("% .3i", -3723);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("%#x", 0);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("%#x", 0);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("%#3x", 0);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("%#3x", 0);
// 	printf("\n--%d--\n\n", a);

// 	a = printf("%#8.5X", 34);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf("%#8.5X", 34);
// 	printf("\n--%d--\n\n", a);

// 	a = printf(" %p %p ", 0xffffffff, -0xffffffff);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf(" %p %p ", 0xffffffff, -0xffffffff);
// 	printf("\n--%d--\n\n", a);

// 	a = printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
// 	printf("\n--%d--\n\n", a);


	a = printf(" %010.10d ", 9223372036854775806);
	printf("\n--%d--\n\n", a);
	a = ft_printf(" %010.10d ", 9223372036854775806);
	printf("\n--%d--\n\n", a);

	a = printf(" %.10d ", 9223372036854775806);
	printf("\n--%d--\n\n", a);
	a = ft_printf(" %.10d ", 9223372036854775806);
	printf("\n--%d--\n\n", a);


	a = printf(" %.10d ", LONG_MAX);
	printf("\n--%d--\n\n", a);
	a = ft_printf(" %.10d ", LONG_MAX);
	printf("\n--%d--\n\n", a);


// 	a = printf(" %-11x ", LONG_MAX);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf(" %-11x ", LONG_MAX);
// 	printf("\n--%d--\n\n", a);

// 	a = printf(" %-1x ", 0);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf(" %-1x ", 0);
// 	printf("\n--%d--\n\n", a);

// 	a = printf(" %-11X ", LONG_MAX);
// 	printf("\n--%d--\n\n", a);
// 	a = ft_printf(" %-11X ", LONG_MAX);
// 	printf("\n--%d--\n\n", a);


// }

