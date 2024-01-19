/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:18:30 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/19 20:18:50 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_size(t_stack *node)
{
	int i;

	i = 0;
	while(node)
	{
		node = node->next;
		i++;
	}
	return(i);
}