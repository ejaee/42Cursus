/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:56:58 by ejachoi           #+#    #+#             */
/*   Updated: 2022/07/07 15:15:11 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c,
					size_t n)
{
	const void	*p;
    
    p = ft_memchr(src, c, n);
	if (!p)
	{
		n = p - src + 1;
		return (ft_memcpy(dst, src, n) + n);
	}
	ft_memcpy(dst, src, n);
	return (NULL);
}
