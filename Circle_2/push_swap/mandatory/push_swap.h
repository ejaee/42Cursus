/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:07:35 by ejachoi           #+#    #+#             */
/*   Updated: 2022/09/05 20:15:05 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define TRUE	1
# define FALSE	0
# define SUCCESS	0
# define FAILURE	1

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list
{
	t_node	*top;
	t_node	*bottom;
	t_node	*cur;
	int		num_of_data;
}	t_list;

/*=== push swap ===*/
void		stack_init(t_list *stack);
void		generate_stack(char **av, t_list *stack);
void		stack_indexing(t_list *stack);
void		stack_indexing2(t_list *stack, int min);

/*=== doubly linked list ===*/
t_node		*ft_init_new_node(int data);
t_node		*ft_pop_top(t_list *stack);
t_node		*ft_pop_bottom(t_list *stack);
void		ft_push_top(t_list *stack, t_node *push_node);
void		ft_push_bottom(t_list *stack, t_node *push_node);

/*=== validate_param ===*/
int			is_nbr(char *nbr);
int			is_integer(long long nbr);
int			is_duplicate(int nbr, t_list *stack);
void		ft_validate_param(char *av, t_list *stack);

/*=== sort ===*/
int			already_sorted(t_list *stack);
void		sort_three(t_list *stack_a, int flag);
void		sort_four(t_list *stack_a, t_list *stack_b);
void		sort_five(t_list *stack_a, t_list *stack_b);
void		ft_sort(t_list *stack_a, t_list *stack_b);

/*=== sort_sandglass ===*/
void		efficient_ra(t_list *stack_a, int idx, int chunk);
void		ft_stack_atob(t_list *stack_a, t_list *stack_b, int chunk);
void		put_to_the_top(t_list *stack);
void		ft_stack_btoa(t_list *stack_a, t_list *stack_b);
void		ft_sort_etc(t_list *stack_a, t_list *stack_b);

/*=== operations_1 ===*/
void		sa(t_list *stack_a);
void		sb(t_list *stack_b);
void		ss(t_list *stack_a, t_list *stack_b);
void		pa(t_list *stack_a, t_list *stack_b);
void		pb(t_list *stack_a, t_list *stack_b);

/*=== operations_2 ===*/
void		ra(t_list *stack_a);
void		rb(t_list *stack_b);
void		rr(t_list *stack_a, t_list *stack_b);
void		ft_putstr(char *str);
long long	ft_atoi(const char *str);

/*=== operations_3 ===*/
void		rra(t_list *stack_a);
void		rrb(t_list *stack_b);
void		rrr(t_list *stack_a, t_list *stack_b);
void		ft_error(void);
void		ft_free_stack(t_list *stack);

char		**ft_split(char const *s, char c);

#endif
