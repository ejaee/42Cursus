/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejachoi <ejachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:07:35 by ejachoi           #+#    #+#             */
/*   Updated: 2022/09/05 20:12:11 by ejachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>

# define TRUE	1
# define FALSE	0
# define SUCCESS	0
# define FAILURE	1
# define BUFFER_SIZE	1024

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

/*=== get_next_line ===*/
char		*get_next_line(int fd);

/*=== check_op ===*/
void		ft_check_op(t_list *stack_a, t_list *stack_b);
void		operation(char *op, t_list *stack_a, t_list *stack_b);
int			already_sorted(t_list *stack);
int			ft_strcmp(const char *s1, const char *s2);

/*=== get_next_line_utils ===*/
int			ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strndup(const char *src, int start, int num);
void		ft_putstr(char *str);

/*=== operations_1 ===*/
void		sa(t_list *stack_a, int flag);
void		sb(t_list *stack_b, int flag);
void		ss(t_list *stack_a, t_list *stack_b, int flag);
void		pa(t_list *stack_a, t_list *stack_b, int flag);
void		pb(t_list *stack_a, t_list *stack_b, int flag);

/*=== operations_2 ===*/
void		ra(t_list *stack_a, int flag);
void		rb(t_list *stack_b, int flag);
void		rr(t_list *stack_a, t_list *stack_b, int flag);

/*=== operations_3 ===*/
void		rra(t_list *stack_a, int flag);
void		rrb(t_list *stack_b, int flag);
void		rrr(t_list *stack_a, t_list *stack_b, int flag);
void		ft_error(void);
void		ft_free_stack(t_list *stack);
char		**ft_split(char const *s, char c);

long long	ft_atoi(const char *str);

#endif
