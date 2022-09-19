/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:37:06 by ejachoi           #+#    #+#             */
/*   Updated: 2022/09/05 19:56:08 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list *stack_a)
{
	ft_push_bottom(stack_a, ft_pop_top(stack_a));
	ft_putstr("ra\n");
}

void	rb(t_list *stack_b)
{
	ft_push_bottom(stack_b, ft_pop_top(stack_b));
	ft_putstr("rb\n");
}

void	rr(t_list *stack_a, t_list *stack_b)
{
	ft_push_bottom(stack_a, ft_pop_top(stack_a));
	ft_push_bottom(stack_b, ft_pop_top(stack_b));
	ft_putstr("rr\n");
}

long long	ft_atoi(const char *str)
{
	int			sign;
	long long	res;

	sign = 1;
	res = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while (*str && ('0' <= *str && *str <= '9'))
	{
		res = res * 10 + (*str - '0');
		++str;
	}
	res *= sign;
	return (res);
}

void	ft_putstr(char *str)
{
	while (*str)
		write (1, str++, 1);
}
