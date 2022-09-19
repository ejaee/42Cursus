/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:24:21 by ejachoi           #+#    #+#             */
/*   Updated: 2022/09/05 19:38:12 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_nbr(char *nbr)
{
	while ((9 <= *nbr && *nbr <= 13) || *nbr == ' ')
		nbr++;
	if (*nbr == '-' || *nbr == '+')
		nbr++;
	if (*nbr == '\0')
		return (FALSE);
	while (*nbr)
	{
		if (*nbr < '0' || '9' < *nbr)
			return (FALSE);
		if (*nbr == '\"')
			return (FALSE);
		nbr++;
	}
	return (TRUE);
}

int	is_integer(long long nbr)
{
	if (nbr < -2147483648 || 2147483647 < nbr)
		return (FALSE);
	return (TRUE);
}

int	is_duplicate(int nbr, t_list *stack)
{
	stack->cur = stack->top->next;
	while (stack->cur->next)
	{
		if (stack->cur->data == nbr)
			return (FALSE);
		stack->cur = stack->cur->next;
	}
	return (TRUE);
}

void	ft_validate_param(char *av, t_list *stack)
{
	char	**split_av;

	split_av = ft_split(av, ' ');
	if (!split_av)
		ft_error();
	while (*split_av)
	{
		if (!is_nbr(*split_av))
			ft_error();
		if (!is_integer(ft_atoi(*split_av)))
			ft_error();
		if (!is_duplicate(ft_atoi(*split_av), stack))
			ft_error();
		ft_push_bottom(stack, ft_init_new_node(ft_atoi(*split_av)));
		split_av++;
	}
}
