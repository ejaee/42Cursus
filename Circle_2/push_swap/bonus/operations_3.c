/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:37:31 by ejachoi           #+#    #+#             */
/*   Updated: 2022/09/05 20:03:10 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_list *stack_a, int flag)
{
	ft_push_top(stack_a, (ft_pop_bottom(stack_a)));
	if (flag)
		ft_putstr("rra\n");
}

void	rrb(t_list *stack_b, int flag)
{
	ft_push_top(stack_b, (ft_pop_bottom(stack_b)));
	if (flag)
		ft_putstr("rrb\n");
}

void	rrr(t_list *stack_a, t_list *stack_b, int flag)
{
	ft_push_top(stack_a, (ft_pop_bottom(stack_a)));
	ft_push_top(stack_b, (ft_pop_bottom(stack_b)));
	if (flag)
		ft_putstr("rrr\n");
}

void	ft_free_stack(t_list *stack)
{
	int	idx;

	idx = -1;
	while (++idx < stack->num_of_data)
	{
		stack->cur = ft_pop_top(stack);
		free(stack->cur);
	}
	free(stack->top);
	free(stack->bottom);
}

void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(FAILURE);
}
