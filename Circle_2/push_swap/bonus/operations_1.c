/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:36:14 by ejachoi           #+#    #+#             */
/*   Updated: 2022/09/05 16:38:29 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_list *stack_a, int flag)
{
	t_node	*node;

	node = ft_pop_top(stack_a);
	node->next = stack_a->top->next->next;
	stack_a->top->next->next->prev = node;
	node->prev = stack_a->top->next;
	stack_a->top->next->next = node;
	if (flag)
		ft_putstr("sa\n");
}

void	sb(t_list *stack_b, int flag)
{
	t_node	*node;

	node = ft_pop_top(stack_b);
	node->next = stack_b->top->next->next;
	stack_b->top->next->next->prev = node;
	node->prev = stack_b->top->next;
	stack_b->top->next->next = node;
	if (flag)
		ft_putstr("sb\n");
}

void	ss(t_list *stack_a, t_list *stack_b, int flag)
{
	t_node	*node;

	node = ft_pop_top(stack_a);
	node->next = stack_a->top->next->next;
	stack_a->top->next->next->prev = node;
	node->prev = stack_a->top->next;
	stack_a->top->next->next = node;
	node = ft_pop_top(stack_b);
	node->next = stack_b->top->next->next;
	stack_b->top->next->next->prev = node;
	node->prev = stack_b->top->next;
	stack_b->top->next->next = node;
	if (flag)
		ft_putstr("ss\n");
}

void	pa(t_list *stack_a, t_list *stack_b, int flag)
{
	ft_push_top(stack_a, ft_pop_top(stack_b));
	if (flag)
		ft_putstr("pa\n");
}

void	pb(t_list *stack_a, t_list *stack_b, int flag)
{
	ft_push_top(stack_b, ft_pop_top(stack_a));
	if (flag)
		ft_putstr("pb\n");
}
