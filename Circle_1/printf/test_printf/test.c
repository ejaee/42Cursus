#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_print_char(int c)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_print_string(char *str)
{
	int	len;

	len = strlen(str);
	while (*str)
	{
		if (write (1, str++, 1) == -1)
			return (-1);
	}
	return (len);
}

int	ft_putnbr_base(unsigned int num, char *base, int *len)
{
	// check base는 할 필요 없음?!
	// check sign -> 그냥 -2147483648 담아야 하니까 longlong 으로 해결
	int	type;

	type = strlen(base);
printf("\n\nlen : %d\n\n", *len);

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
		(*len)++;
	}
	else
	{
		ft_putnbr_base(num / type, base, len);
		ft_putnbr_base(num % type, base, len);
	}
	return (0);
}

// type : %d, %i, %u
int	ft_print_int(unsigned int num)
{
	int len;
	int rst;

	len = 0;
	rst = ft_putnbr_base(num, "0123456789", &len);
	if (rst == -1)
		return (-1);
	return (len);
}

int	check_type(const char c, va_list *ap)
{
	if (c == 'c')
		return (ft_print_char(va_arg(*ap, int)));
	else if (c == 's')
		return (ft_print_string(va_arg(*ap, char *)));
	else if (c == 'd' || c == 'i' || c == 'u')
		return (ft_print_int(va_arg(*ap, unsigned int)));
		// u는 음수에 대한 underflow 구현
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
	int	len = 0;

	len = ft_printf("%d", -2147483647);
	printf("\noutput len : %d\n\n", len);
	len = printf("%d", -2147483647);
	printf("\noutput len : %d\n\n", len);

}

