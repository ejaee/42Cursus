/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:15:45 by ejachoi           #+#    #+#             */
/*   Updated: 2022/07/07 22:15:50 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int			size;
	long long	num;

	size = 1;
	num = n;
	if (num < 0)
	{
		num *= -1;
		size++;
	}
	while (num > 9)
	{
		size++;
		num /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long long	num;
	int			len;
	char		*arr;

	num = n;
	len = ft_len(n);
	arr = (char *) malloc (sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	if (num == 0)
		arr[0] = '0';
	if (num < 0)
	{
		arr[0] = '-';
		num *= -1;
	}
	arr[len] = '\0';
	while (num)
	{
		arr[--len] = num % 10 + '0';
		num /= 10;
	}
	return (arr);
}
