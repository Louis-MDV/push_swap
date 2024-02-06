/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking_sortings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:15:42 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/06 18:22:09 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*cheapest(t_stack **stack)
{
	t_stack	*current1;
	t_stack	*current2;
	t_stack	*ptr_cheapest;

	current1 = (*stack);
	ptr_cheapest = current1;
	while (current1 != NULL)
	{
		current2 = current1->next;
		while (current2 != NULL)
		{
			if (current2->push_cost < ptr_cheapest->push_cost)
				ptr_cheapest = current2;
			current2 = current2->next;
		}
		current1 = current1->next;
	}
	if (ptr_cheapest != NULL)
		ptr_cheapest->cheapest = 1;
	current1 = (*stack);
	while (current1 != NULL)
		current1 = current1->next;
	return (ptr_cheapest);
}

void	init_cheap_target(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		stack->target_node = 0;
		stack->cheapest = 0;
		stack = stack->next;
	}
}

void	init_b(t_stack **a, t_stack **b)
{
	if (stack_len(*a) > 3 && !check_sort(*a))
		ft_pb(a, b);
	if (stack_len(*a) > 3 && !check_sort(*a))
		ft_pb(a, b);
}

void	bringToTop1(t_stack **stack, t_stack *top_node, char name)
{
	while (top_node != *stack)
	{
		if (name == 'a')
		{
			if (!top_node->under_median)
				ft_ra(stack);
			else
				ft_rra(stack);
		}
		else if (name == 'b')
		{
			if (!top_node->under_median)
				ft_rb(stack);
			else
				ft_rrb(stack);
		}
	}
}

void	bringToTop2(t_stack **a, t_stack *top_nodeA, t_stack **b,
		t_stack *top_nodeB)
{
	while (*a != top_nodeA && *b != top_nodeB)
	{
		if (!top_nodeA->under_median && !top_nodeB->under_median)
			ft_rr(a, b);
		else if (top_nodeA->under_median && top_nodeB->under_median)
			ft_rrr(a, b);
		else if (!top_nodeA->under_median && top_nodeB->under_median && top_nodeA->index < top_nodeB->index)
		{
			if (top_nodeA->index + (stack_len(*b) - top_nodeB->index) > top_nodeB->index)
				ft_rr(a, b);
			else if (top_nodeA->index + (stack_len(*b)-top_nodeB->index) > stack_len(*a)-top_nodeA->index)
				ft_rrr(a,b);
			else
			{
				ft_ra(a);
				ft_rrb(b);
			}
		}
		else if (top_nodeA->under_median && !top_nodeB->under_median && top_nodeB->index < top_nodeA->index)
		{
			if (top_nodeB->index + (stack_len(*a) - top_nodeA->index) > top_nodeA->index)
				ft_rr(a, b);
			else if (top_nodeB->index + (stack_len(*a)-top_nodeA->index) > stack_len(*b)-top_nodeB->index)
				ft_rrr(a,b);
			else
			{
				ft_rra(a);
				ft_rb(b);
			}
		}
		else if (!top_nodeA->under_median && top_nodeB->under_median)
		{
			ft_ra(a);
			ft_rrb(b);
		}
		else if (top_nodeA->under_median && !top_nodeB->under_median)
		{
			ft_rra(a);
			ft_rb(b);
		}
	}
}

