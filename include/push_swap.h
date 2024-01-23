/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:52:27 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/22 22:57:51 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdbool.h> //to use booleans
# include <stdlib.h>

typedef struct s_stack
{
	struct s_stack	*next;
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*prev;
}					t_stack;

// parsing
int					check_num(char *str, int size);
int					check_dup(int *tab, int size);
long				ft_atol(const char *nptr);
t_stack				*init_stack(int ac, char **av);
t_stack				*ft_parse_int(int ac, char **av);
t_stack				*ft_parse_quoted(char **av);
void				list_args(int *tab, t_stack **stack_a, int size);

// node manipulation
t_stack				*ft_new_node(int content);
t_stack				*ft_lst_last(t_stack *node);
int					stack_len(t_stack *stack_a);
void				add_node_back(t_stack **lst, t_stack *new);
bool				ft_sort(t_stack *a);
void				ft_free_stack(t_stack **a);

// operations
void				ft_sa(t_stack **stack_a);
void				ft_sb(t_stack **b);
void				ft_ss(t_stack **a, t_stack **b);
void				ft_pa(t_stack **a, t_stack **b);
void				ft_pb(t_stack **a, t_stack **b);
void				ft_ra(t_stack **a);
void				ft_rb(t_stack **b);
void				ft_rr(t_stack **a, t_stack **b);
void				ft_rra(t_stack **a);
void				ft_rrb(t_stack **b);
void				ft_rrr(t_stack **a, t_stack **b);

// algorithm
void				ft_sort3(t_stack **a);
bool				check_sort(t_stack **a);



#endif