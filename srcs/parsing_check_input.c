/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:35:24 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/06 16:57:00 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_num(char *str, int size)
{
	int	j;

	j = 0;
	while (str[j] && j < size)
	{
		if (str[j] == '-' || str[j] == '+' || str[j] == ' ')
			j++;
		else if (ft_isdigit(str[j]))
			j++;
		else
			return (0);
	}
	return (1);
}

int	check_dup(long *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size - 1)
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_intmax(long *tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (tab[i] > 2147483647)
			return (0);
		i++;
	}
	return (1);
}