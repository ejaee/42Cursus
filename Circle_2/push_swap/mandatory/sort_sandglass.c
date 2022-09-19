/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sandglass.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:32:17 by ejachoi           #+#    #+#             */
/*   Updated: 2022/09/04 19:32:50 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	efficient_ra(t_list *stack_a, int idx, int chunk)
{
	int	push_idx;

	push_idx = 0;
	stack_a->cur = stack_a->top->next;
	while (stack_a->cur->next)
	{
		if (stack_a->cur->index <= idx + chunk)
			break ;
		++push_idx;
		stack_a->cur = stack_a->cur->next;
	}
	if (push_idx < stack_a->num_of_data / 2)
		ra(stack_a);
	else
		rra(stack_a);
}

void	ft_stack_atob(t_list *stack_a, t_list *stack_b, int chunk)
{
	t_node	*top_a;
	t_node	*top_b;
	int		idx;

	idx = 0;
	while (stack_a->num_of_data)
	{
		top_a = stack_a->top->next;
		top_b = stack_b->top->next;
		if (top_a->index <= idx)
		{
			pb(stack_a, stack_b);
			++idx;
		}
		else if (idx < top_a->index && top_a->index <= idx + chunk)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			++idx;
		}
		else
			efficient_ra(stack_a, idx, chunk);
	}
}

void	put_to_the_top(t_list *stack)
{
	int	max_idx;

	max_idx = 0;
	stack->cur = stack->top->next;
	while (stack->cur->index != stack->num_of_data - 1)
	{
		max_idx++;
		stack->cur = stack->cur->next;
	}
	while (stack->top->next->index < stack->num_of_data - 1)
	{
		if (max_idx < stack->num_of_data / 2)
			rb(stack);
		else
			rrb(stack);
	}
}

void	ft_stack_btoa(t_list *stack_a, t_list *stack_b)
{
	while (stack_b->num_of_data > 0)
	{
		put_to_the_top(stack_b);
		pa(stack_a, stack_b);
	}
}

void	ft_sort_etc(t_list *stack_a, t_list *stack_b)
{
	int	chunk;
	int	x;

	x = stack_a->num_of_data;
	chunk = 0.000000053 * x * x + 0.03 * x + 14.5;
	ft_stack_atob(stack_a, stack_b, chunk);
	ft_stack_btoa(stack_a, stack_b);
}
