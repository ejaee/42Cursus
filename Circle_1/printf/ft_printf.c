/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:48:34 by ejachoi           #+#    #+#             */
/*   Updated: 2022/08/16 15:48:31 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(const char c, va_list *ap)
{
	if (c == 'c')
		return (ft_print_char(va_arg(*ap, int)));
	else if (c == '%')
		return (ft_print_char('%'));
	else if (c == 's')
		return (ft_print_string(va_arg(*ap, unsigned char *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(*ap, int), c));
	else if (c == 'u' || c == 'X' || c == 'x')
		return (ft_print_nbr(va_arg(*ap, unsigned int), c));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(*ap, unsigned long long)));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		printed_len;
	int		check_fail;
	va_list	ap;

	printed_len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			check_fail = check_type(*++format, &ap);
			if (check_fail == -1)
				return (-1);
			printed_len += check_fail;
		}
		else
		{
			check_fail = ft_print_char((int)*format);
			if (check_fail == -1)
				return (-1);
			printed_len++;
		}
		format++;
	}
	return (printed_len);
}
