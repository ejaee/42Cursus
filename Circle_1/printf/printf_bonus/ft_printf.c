/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <choiejae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:48:34 by ejachoi           #+#    #+#             */
/*   Updated: 2022/08/19 21:45:55 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(const char c, va_list *ap, t_info *info)
{
	if (c == 'c')
		return (ft_print_chr(va_arg(*ap, int)));
	else if (c == '%')
		return (ft_print_chr('%'));
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
			check_fail = ft_print_chr((int)*format);
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

// 	a = printf("%s", NULL);
// 	printf("\n--%d--\n", a);
// 	a = ft_printf("%s", NULL);
// 	printf("\n--%d--\n", a);


// 	a = printf(" NULL %s NULL ", NULL);
// 	printf("\n--%d--\n", a);
// 	a = ft_printf(" NULL %s NULL ", NULL);
// 	printf("\n--%d--\n", a);

// 	a =  printf("%.4s", "2147483651");
// 	printf("\n--%d--\n", a);
// 	a = ft_printf("%.4s", "2147483651");
// 	printf("\n--%d--\n", a);
	

// 	a =  printf("%20s", "2147483651");
// 	printf("\n--%d--\n", a);
// 	a = ft_printf("%20s", "2147483651");
// 	printf("\n--%d--\n", a);

// 	a =  printf("%020s", "2147483651");
// 	printf("\n--%d--\n", a);
// 	a = ft_printf("%020s", "2147483651");
// 	printf("\n--%d--\n", a);


// 	a =  printf("%-020s", "2147483651");
// 	printf("\n--%d--\n", a);
// 	a = ft_printf("%-020s", "2147483651");
// 	printf("\n--%d--\n", a);

	// a =  printf("%21u", 2147483651);
	// printf("\n--%d--\n", a);
	// a = ft_printf("%21u", 2147483651);
	// printf("\n--%d--\n", a);
	
	// a =  printf("%021u", 2147483651);
	// printf("\n--%d--\n", a);
	// a = ft_printf("%021u", 2147483651);
	// printf("\n--%d--\n", a);

	// a =  printf("%.21u", 2147483651);
	// printf("\n--%d--\n", a);
	// a = ft_printf("%.21u", 2147483651);
	// printf("\n--%d--\n", a);

	// a =  printf("%21.21u", 2147483651);
	// printf("\n--%d--\n", a);
	// a = ft_printf("%21.21u", 2147483651);
	// printf("\n--%d--\n", a);
	


	// a =  printf("%4d", 21474);
	// printf("\n--%d--\n", a);
	// a = ft_printf("%4d", 21474);
	// printf("\n--%d--\n", a);
	

	// a =  printf("%07d", 21474);
	// printf("\n--%d--\n", a);
	// a = ft_printf("%07d", 21474);
	// printf("\n--%d--\n", a);
	

	// a =  printf("% d\n", 0);
	// printf("::%d::\n", a);
	// a = ft_printf("% d\n", 0);
	// printf("::%d::\n", a);
	
	// a =  printf("% d\n", 1);
	// printf("::%d::\n", a);
	// a = ft_printf("% d\n", 1);
	// printf("::%d::\n", a);
	

	// a =  printf("%+d\n", 1);
	// printf("::%d::\n", a);
	// a = ft_printf("%+d\n", 1);
	// printf("::%d::\n", a);
	


	// a =  printf("% +d\n", 1);
	// printf("::%d::\n", a);
	// a = ft_printf("% +d\n", 1);
	// printf("::%d::\n", a);
	

	// a =  printf("% #X\n", 1);
	// printf("::%d::\n", a);
	// a = ft_printf("% #X\n", 1);
	// printf("::%d::\n", a);

	// a =  printf("% x\n", 0);
	// printf("::%d::\n", a);
	// a = ft_printf("% x\n", 0);
	// printf("::%d::\n", a);


	// a =  printf("%  +x\n", 0);
	// printf("::%d::\n", a);
	// a = ft_printf("% +x\n", 0);
	// printf("::%d::\n", a);


	// a =  printf("% d\n", 0);
	// printf("::%d::\n", a);
	// a = ft_printf("% d\n", 0);
	// printf("::%d::\n", a);

	// a =  printf("% d\n", 1);
	// printf("::%d::\n", a);
	// a = ft_printf("% d\n", 1);
	// printf("::%d::\n", a);

// }
