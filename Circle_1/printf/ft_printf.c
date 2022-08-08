/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:48:34 by ejachoi           #+#    #+#             */
/*   Updated: 2022/08/08 16:35:03 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
// type : %c
int	ft_print_char(int c)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	return (1);
}

// type : %s
int	ft_print_string(unsigned char *str)
{
	int	len;
	
	if (str == NULL)
	{
		write (1, "(null)", 6);
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

// type : %d, %i, %u -> u일때는 가변인자 메모리 크기가 다른가? int를 unsigned int로 밀어도 되는가?
int	ft_putnbr_base(long long num, char *base)
{
	// check base는 할 필요 없음?!
	// check sign -> 그냥 -2147483648 담아야 하니까 longlong 으로 해결
	int	type;

	type = ft_strlen(base);
	if (num < 0)
	{
		if (write (1, "-", 1) == -1)
			return (-1);
		num *= -1;
	}
	if (num < (long long)type)
	{
		if (write (1, &base[num], 1) == -1)
			return (-1);
	}
	else
	{
		ft_putnbr_base(num / (long long)type, base);
		ft_putnbr_base(num % (long long)type, base);
	}
	return (0);
}

int	ft_print_int(int num)
{
	int len;
	char *str;

	str = ft_itoa(num);
	len = ft_strlen(str);
	if (ft_putnbr_base(num, "0123456789") == -1)
		return (-1);
	return (len);
}

int	ft_strlen_base(unsigned int num, int type)
{
	int cnt;

	cnt = 1;
	if (!num)
		return (0);
	while (1)
	{
		if (num < type)
			break;
		num /= type;
		cnt++;
	}
	return (cnt);
}

int ft_print_base(unsigned int num, const char type)
{
	char *str;

	if (type == 'u')
	{
		str = ft_itoa(num);
		ft_putnbr_base(num, "0123456789");
		return (ft_strlen(str));
	}
	else if(type == 'X')
		ft_putnbr_base(num, "0123456789ABCDEF");
	else
		ft_putnbr_base(num, "0123456789abcdef");
	return (ft_strlen_base(num, 16));
}

int	ft_print_ptr(unsigned long ptr)
{
	char	*hex;
	char	stack[17];
	int idx;
	int res;

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

int	check_type(const char c, va_list *ap)
{
	if (c == 'c')
		return (ft_print_char(va_arg(*ap, int)));
	else if (c == 's')
		// str = NULL 예외처리
		return (ft_print_string(va_arg(*ap, unsigned char *)));
	// int
	else if (c == 'd' || c == 'i')
		return (ft_print_int(va_arg(*ap, int)));
	// unsigned int
	else if (c == 'u' || c == 'x' || c == 'X')
		// u는 음수에 대한 underflow 구현
		return (ft_print_base(va_arg(*ap, unsigned int), c));
	 	// int_max 값에 대해 컴파일 되지 않으므로 int?!
	else if (c == 'p')
		return (ft_print_ptr(va_arg(*ap, unsigned long)));
	else if (c == '%')
		return (ft_print_char('%'));
	else
	// % 뒤에 잘못된 서식 지정자가 들어온 경우
		return (-1);
}

int ft_printf(const char *format, ...)
{
	int	printed_len;
	int	check_fail;
	va_list ap;

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


int	main()
{
	printf("\n\n========== %%s ==========\n\n");

	printf("printf : %s %s %d\n", "\0", NULL, 42);
	ft_printf("ft_printf : %s %s %d\n", "\0", NULL, 42);

	printf("\n\n========== %%u %%X %%x ==========\n\n");

	int a = printf("%u %X %x : \n", 2147483647, 2147483647, 2147483647);
	int b = ft_printf("%u %X %x : \n", 2147483647, 2147483647, 2147483647);

	printf("p = %d\nft = %d\n", a, b);

	printf("\n\n========== %%p ==========\n\n");

	char *p;
	char *pp;
	char *ppp;

	int c = printf("%p\n", NULL);
	int d = ft_printf("%p\n", NULL);
	
	printf("p = %d\nft = %d\n\n", c, d);

	c = printf("%p\n", pp);
	d = ft_printf("%p\n", pp);

	printf("p = %d\nft = %d\n\n", c, d);

	c = printf("%p\n", ppp);
	d = ft_printf("%p\n", ppp);

	printf("p = %d\nft = %d\n\n", c, d);
}