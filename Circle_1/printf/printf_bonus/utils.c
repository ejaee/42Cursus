/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:35:13 by choiejae          #+#    #+#             */
/*   Updated: 2022/08/22 21:25:27 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

int	ft_strlen_base(long long nbr, int type, t_info *info)
{
	int	cnt;

	cnt = 1;
	info->flag_minus = 0;
	if (nbr < 0)
	{
		info->flag_minus = 1;
		nbr *= -1;
	}
	while (1)
	{
		if (nbr < type)
			break ;
		nbr /= type;
		cnt++;
	}
	if (info->hash)
		cnt +=2;
	return (cnt);
}

int	ft_print_prec(int idx, t_info *info)
{
	int	remain_prec;

	remain_prec = info->prec;
	while (idx < remain_prec--)
	{
		if (write (1, "0", 1) == -1)
			return (-1);
	}
	return (0);
}

int	ft_putnbr_base(long long nbr, char *base, t_info *info)
{
	char	stack[12];
	int		idx;
	int		base_size;

	idx = 0;
	base_size = ft_strlen(base);
	if (nbr == 0)
	{
		if (ft_print_prec(1, info) == -1)
			return (-1);
		if (write (1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	if (nbr < 0)
		nbr *= -1;
	while (nbr)
	{
		stack[idx++] = base[nbr % base_size];
		nbr /= base_size;
	}
	if (ft_print_prec(idx, info) == -1)
		return (-1);
	while (--idx >= 0)
		if (write (1, &stack[idx], 1) == -1)
			return (-1);
	return (0);
}

char	*ft_baseset(char type)
{
	if (type == 'd' || type == 'i' || type == 'u')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else if (type == 'X')
		return ("0123456789ABCDEF");
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
		s++;
	}
}


int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}
