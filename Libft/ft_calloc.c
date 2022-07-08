/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:55:14 by ejachoi           #+#    #+#             */
/*   Updated: 2022/07/08 12:25:28 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if ((count == SIZE_MAX && size > 1) || (count > 1 && size == SIZE_MAX))
		return (NULL);
	p = malloc(size * count);
	if (!p)
		return (0);
	ft_memset(p, 0, size * count);
	return (p);
}
