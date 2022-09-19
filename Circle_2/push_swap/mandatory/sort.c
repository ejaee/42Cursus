/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:24:40 by choiejae          #+#    #+#             */
/*   Updated: 2022/09/04 19:32:31 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_sorted(t_list *stack)
{
	stack->cur = stack->top->next;
	while (stack->cur->next->next)
	{
		if (stack->cur->data < stack->cur->next->data)
			stack->cur = stack->cur->next;
		else
			return (FALSE);
	}
	return (TRUE);
}

void	sort_three(t_list *stack_a, int flag)
{
	while (!already_sorted(stack_a))
	{
		stack_a->cur = stack_a->top->next;
		if (stack_a->cur->index == 0 + flag)
		{
			sa(stack_a);
			ra(stack_a);
		}
		else if (stack_a->cur->index == stack_a->num_of_data - 1)
		{
			if (stack_a->bottom->prev->index == 0 + flag)
			{
				sa(stack_a);
				rra(stack_a);
			}
			else
				ra(stack_a);
		}
		else
			ra(stack_a);
	}
}

void	sort_four(t_list *stack_a, t_list *stack_b)
{
	int	flag;

	flag = 0;
	while (!stack_b->num_of_data)
	{
		stack_a->cur = stack_a->top->next;
		if (stack_a->cur->index == 0 || stack_a->cur->index == 3)
		{
			if (stack_a->cur->index == 0)
				flag = 1;
			pb(stack_a, stack_b);
		}
		else
			ra(stack_a);
	}
	if (!already_sorted(stack_a))
		sort_three(stack_a, flag);
	pa(stack_a, stack_b);
	if (stack_a->top->next->index == 2)
		ra(stack_a);
}

void	sort_five(t_list *stack_a, t_list *stack_b)
{
	while (stack_b->num_of_data != 2)
	{
		stack_a->cur = stack_a->top->next;
		if (stack_a->cur->index == 0 || stack_a->cur->index == 4)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	if (!already_sorted(stack_a))
		sort_three(stack_a, 1);
	while (stack_b->num_of_data)
	{
		pa(stack_a, stack_b);
		if (stack_a->top->next->index == 4)
			ra(stack_a);
	}
}

void	ft_sort(t_list *stack_a, t_list *stack_b)
{
	if (stack_a->num_of_data == 1 || already_sorted(stack_a))
		return ;
	else if (stack_a->num_of_data == 2)
	{
		if (stack_a->top->next->data > stack_a->bottom->prev->data)
			sa(stack_a);
	}
	else if (stack_a->num_of_data == 3)
		sort_three(stack_a, 0);
	else if (stack_a->num_of_data == 4)
		sort_four(stack_a, stack_b);
	else if (stack_a->num_of_data == 5)
		sort_five(stack_a, stack_b);
	else
		ft_sort_etc(stack_a, stack_b);
}
