/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:02:57 by ejachoi           #+#    #+#             */
/*   Updated: 2022/09/05 19:36:04 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	stack_indexing2(t_list *stack, int min)
{
	int	next_min;
	int	idx;

	next_min = 2147483647;
	idx = 0;
	while (++idx < stack->num_of_data)
	{
		stack->cur = stack->top->next;
		while (stack->cur->next)
		{
			if (min < stack->cur->data && stack->cur->data < next_min)
				next_min = stack->cur->data;
			stack->cur = stack->cur->next;
		}
		stack->cur = stack->top->next;
		while (stack->cur->next)
		{
			if (stack->cur->data == next_min)
				stack->cur->index = idx;
			stack->cur = stack->cur->next;
		}
		min = next_min;
		next_min = 2147483647;
	}
}

void	stack_indexing(t_list *stack)
{
	int	min;

	stack->cur = stack->top->next;
	min = 2147483647;
	while (stack->cur->next)
	{
		if (min > stack->cur->data)
		{
			min = stack->cur->data;
			stack->cur->index = 0;
		}
		stack->cur = stack->cur->next;
	}
	stack_indexing2(stack, min);
}

void	generate_stack(char **av, t_list *stack)
{
	int	idx;

	idx = 0;
	while (av[++idx])
	{
		if (av[idx][0] == '\0')
			ft_error();
		else
			ft_validate_param(av[idx], stack);
	}
}

void	stack_init(t_list *stack)
{
	stack->top = (t_node *)malloc(sizeof(t_node));
	if (!stack->top)
		ft_error();
	stack->bottom = (t_node *)malloc(sizeof(t_node));
	if (!stack->bottom)
		ft_error();
	stack->top->prev = NULL;
	stack->top->next = stack->bottom;
	stack->bottom->prev = stack->top;
	stack->bottom->next = NULL;
	stack->num_of_data = 0;
}

int	main(int ac, char **av)
{
	t_list	stack_a;
	t_list	stack_b;

	if (ac < 2)
		return (FALSE);
	stack_init(&stack_a);
	if (!av[1][0])
		ft_error();
	generate_stack(av, &stack_a);
	stack_init(&stack_b);
	stack_indexing(&stack_a);
	ft_check_op(&stack_a, &stack_b);
	ft_free_stack(&stack_b);
}
