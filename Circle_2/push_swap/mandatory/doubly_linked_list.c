/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:08:43 by ejachoi           #+#    #+#             */
/*   Updated: 2022/09/05 19:37:39 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_init_new_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		ft_error();
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_node	*ft_pop_top(t_list *stack)
{
	t_node	*tmp;

	tmp = stack->top->next;
	if (tmp)
	{
		stack->top->next = tmp->next;
		tmp->next->prev = stack->top;
		(stack->num_of_data)--;
		return (tmp);
	}
	else
		return (NULL);
}

t_node	*ft_pop_bottom(t_list *stack)
{
	t_node	*tmp;

	tmp = stack->bottom->prev;
	if (tmp)
	{
		stack->bottom->prev = tmp->prev;
		tmp->prev->next = stack->bottom;
		(stack->num_of_data)--;
		return (tmp);
	}
	else
		return (NULL);
}

void	ft_push_top(t_list *stack, t_node *push_node)
{
	push_node->next = stack->top->next;
	stack->top->next->prev = push_node;
	push_node->prev = stack->top;
	stack->top->next = push_node;
	(stack->num_of_data)++;
}

void	ft_push_bottom(t_list *stack, t_node *push_node)
{
	push_node->prev = stack->bottom->prev;
	stack->bottom->prev->next = push_node;
	push_node->next = stack->bottom;
	stack->bottom->prev = push_node;
	(stack->num_of_data)++;
}
