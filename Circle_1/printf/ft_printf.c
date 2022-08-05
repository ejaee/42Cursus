/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:48:34 by ejachoi           #+#    #+#             */
/*   Updated: 2022/08/05 23:16:28 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// type : %c
int	ft_print_char(int c)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	return (1);
}

// type : %s
int	ft_print_string(char *str)
{
	int	len;

	len = ft_strlen(str);

	if (!*str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		if (write (1, str++, 1) == -1)
			return (-1);
	}
	return (len);
}

// type : %d, %i, %u -> u일때는 가변인자 메모리 크기가 다른가? int를 unsigned int로 밀어도 되는가?
int	ft_putnbr_base(unsigned int num, char *base)
{
	// check base는 할 필요 없음?!
	// check sign -> 그냥 -2147483648 담아야 하니까 longlong 으로 해결
	int	type;
	int len;

	len = 0;
	type = ft_strlen(base);
	if (num < 0)
	{
		if (write (1, "-", 1) == -1)
			return (-1);
		len++;
		num *= -1;
	}
	if (num < type)
	{
		if (write (1, &base[num], 1) == -1)
			return (-1);
		len++;
	}
	else
	{
		ft_putnbr_base(num / type, base);
		ft_putnbr_base(num % type, base);
	}
	return (len);
}

int	ft_print_int(int num)
{
	int len;

	len = ft_putnbr_base(num, "0123456789");

	return (len);
}

int	check_type(const char c, va_list *ap)
{
	if (c == 'c')
		return (ft_print_char(va_arg(*ap, int)));
	else if (c == 's')
		return (ft_print_string(va_arg(*ap, char *)));
		// str = NULL 예외처리
	else if (c == 'd' || c == 'i' || c == 'u')
		return (ft_print_int(va_arg(*ap, int)));
		// u는 음수에 대한 underflow 구현
	else if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(*ap, int)));
		// int_max 값에 대해 컴파일 되지 않으므로 int?!
	else if (c == 'p')
		return (ft_print_ptr());
	else if (c == '%')
		return (ft_print_char('%'));
	else
	// % 뒤에 잘못된 서식 지정자가 들어온 경우
		return (-1);
}

int ft_printf(const char *format, ...)
{
	int	len;
	int	tmp;
	va_list ap;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			tmp = check_type(*++format, &ap);
			if (tmp == -1)
				return (-1);
			len += tmp;
		}
		else
		{
			tmp = ft_print_char((int)*format);
			if (tmp == -1)
				return (-1);
			len++;
		}
		format++;
	}
	return (len);
}

int	main()
{
	printf("text %c %d %d", 'a', 123, 456);
}
