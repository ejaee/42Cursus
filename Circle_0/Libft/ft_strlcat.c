/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:37:01 by ejachoi           #+#    #+#             */
/*   Updated: 2022/07/09 18:38:59 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	idx_d;
	size_t	idx_s;
	size_t	len_d;
	size_t	len_s;

	len_d = ft_strlen(dest);
	len_s = ft_strlen(src);
	idx_d = len_d;
	idx_s = 0;
	if (size <= len_d)
		return (len_s + size);
	while (src[idx_s] && idx_d < size - 1)
		dest[idx_d++] = src[idx_s++];
	dest[idx_d] = '\0';
	return (len_d + len_s);
}
