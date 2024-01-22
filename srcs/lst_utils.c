/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:53:53 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/22 15:00:48 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// makes node pointer point to last node of stack
t_stack	*ft_lst_last(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

int	stack_len(t_stack *stack_a)
{
	int i;

	i = 0;
	if (!stack_a)
		return (i);
	while (stack_a)
	{
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}