/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:37:06 by ejachoi           #+#    #+#             */
/*   Updated: 2022/09/05 16:38:48 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_list *stack_a, int flag)
{
	ft_push_bottom(stack_a, ft_pop_top(stack_a));
	if (flag)
		ft_putstr("ra\n");
}

void	rb(t_list *stack_b, int flag)
{
	ft_push_bottom(stack_b, ft_pop_top(stack_b));
	if (flag)
		ft_putstr("rb\n");
}

void	rr(t_list *stack_a, t_list *stack_b, int flag)
{
	ft_push_bottom(stack_a, ft_pop_top(stack_a));
	ft_push_bottom(stack_b, ft_pop_top(stack_b));
	if (flag)
		ft_putstr("rr\n");
}
