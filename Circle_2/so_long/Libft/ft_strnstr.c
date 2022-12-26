/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:37:16 by ejachoi           #+#    #+#             */
/*   Updated: 2022/07/07 13:33:35 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx_str;
	size_t	idx_find;

	idx_str = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[idx_str] && idx_str < len)
	{
		idx_find = 0;
		while (haystack[idx_str + idx_find] == needle[idx_find] \
			&& idx_str + idx_find < len)
		{
			idx_find++;
			if (!needle[idx_find])
				return ((char *)&haystack[idx_str]);
		}
		idx_str++;
	}
	return (0);
}
