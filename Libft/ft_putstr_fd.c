/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:46:36 by ejachoi           #+#    #+#             */
/*   Updated: 2022/07/07 22:10:44 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	idx;

	idx = 0;
	if (!s)
		return (NULL);
	while (s[idx])
	{
		ft_putchar_fd(s[idx], fd);
		idx++;
	}
}
