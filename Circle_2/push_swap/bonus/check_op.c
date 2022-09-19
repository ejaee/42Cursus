/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:07:20 by ejachoi           #+#    #+#             */
/*   Updated: 2022/09/05 19:55:17 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

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

void	operation(char *op, t_list *stack_a, t_list *stack_b)
{
	if (!ft_strcmp(op, "sa\n"))
		sa(stack_a, 0);
	else if (!ft_strcmp(op, "sb\n"))
		sb(stack_b, 0);
	else if (!ft_strcmp(op, "ss\n"))
		ss(stack_a, stack_a, 0);
	else if (!ft_strcmp(op, "pa\n"))
		pa(stack_a, stack_b, 0);
	else if (!ft_strcmp(op, "pb\n"))
		pb(stack_a, stack_b, 0);
	else if (!ft_strcmp(op, "ra\n"))
		ra(stack_a, 0);
	else if (!ft_strcmp(op, "rb\n"))
		rb(stack_b, 0);
	else if (!ft_strcmp(op, "rr\n"))
		rr(stack_a, stack_b, 0);
	else if (!ft_strcmp(op, "rra\n"))
		rra(stack_a, 0);
	else if (!ft_strcmp(op, "rrb\n"))
		rrb(stack_b, 0);
	else if (!ft_strcmp(op, "rrr\n"))
		rrr(stack_a, stack_b, 0);
	else
		ft_error();
}

void	ft_check_op(t_list *stack_a, t_list *stack_b)
{
	char	*op;

	while (1)
	{
		op = get_next_line(STDIN_FILENO);
		if (!op)
			break ;
		operation(op, stack_a, stack_b);
		free(op);
	}
	if (already_sorted(stack_a) && !(stack_b->num_of_data))
		write(1, "OK\n", 3);
	else if (!already_sorted(stack_a) || stack_b->num_of_data)
		write(1, "KO\n", 3);
	else
		write(1, "Error\n", 6);
}
