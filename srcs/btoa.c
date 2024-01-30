/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:49:28 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/30 23:49:22 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	btoa(t_stack **a, t_stack **b)
{
	t_stack	*currentB;
	t_stack	*Btarget;

	currentB = *b;
	printf(RED "[BtoA: ...]\n" RESET);
	while (currentB != NULL)
	{
		currentB = *b;
		init_cheapest(*a);
		init_cheapest(*b);
		indexing(a);
		indexing(b);

		find_target_nodeb(a, b);

		total_cost(a, stack_len(*a), stack_len(*b));
		total_cost(b, stack_len(*b), stack_len(*a));

		cheapest(a);
		cheapest(b);
		currentB = *b;
		while(currentB != NULL)
		{
			if (currentB->cheapest == 1)
			{
				Btarget = currentB->target_node;
				printf("Btarget: %d\n", Btarget->value);
				bring_b2top(currentB, b);
				bring_a2top(Btarget, a);
				printf("stack a top: %d\n", (*a)->value);
				ft_pa(a, b);
				printf(GREEN ">>>>>>>>>> pushing node [%d] to A\n" RESET, currentB->value);
				printf("stack a:\n");
				printstack(a);
				printf("stack b:\n");
				printstack(b);
				printf("value of b: %d\n", (*a)->value);
				printf("value of currentB: %d\n\n", currentB->value);
				break ;
			}
		currentB = currentB->next;
		}
	}
	printf("_______________________________________________________________\n");
	printf("stack a:\n");
	printstack(a);
	printf("stack b:\n");
	printstack(b);
}
