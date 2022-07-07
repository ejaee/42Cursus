/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:37:12 by ejachoi           #+#    #+#             */
/*   Updated: 2022/07/07 13:35:08 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	while (n--)
	{
		if (s1[idx] != s2[idx])
			return ((const unsigned char)s1[idx] \
				- (const unsigned char)s2[idx]);
		idx++;
	}
	return (0);
}
