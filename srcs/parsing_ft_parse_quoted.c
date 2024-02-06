/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ft_parse_quoted.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:58:33 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/06 18:32:36 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// This func counts the # of ints in the string.
int	count_int(char *str)
{
	int	j;
	int	nums;

	j = 0;
	nums = 0;
	while (str[j])
	{
		if (str[j] >= '0' && str[j] <= '9' && (str[j + 1] == ' ' 
			|| str[j + 1] == '\0'))
			nums++;
		j++;
	}
	return (nums);
}

// This func does 3 things:
// 1. It checks if the input is a number.
// 2. It checks if the input has duplicates.
// 3. It creates a list of ints from the input.
t_stack	*ft_parse_quoted(char **av)
{
	int		j;
	long	*tab;
	t_stack	*stack_a;
	int		nums;
	char	**av1;

	tab = NULL;
	stack_a = NULL;
	// check nums + check count ints in av[1]
	if (check_num(av[1], ft_strlen(av[1])) == 0 
		|| count_int(av[1]) <= 1)
	{
		ft_error();
		return (0);
	}
	nums = count_int(av[1]);
	av1 = ft_split(av[1], ' ');
	tab = (long *)malloc(count_int(av[1]) * sizeof(long));
	if (!tab)
	{
		free_split_result(av1);
		return(stack_a);
	}
	j = 0;
	while (j < nums && av1[j])
	{
		tab[j] = ft_atol(av1[j]);
		j++;
	}
	free_split_result(av1);
	if (check_dup(tab, nums) == 0 
		|| check_intmax(tab, nums) == 0) // checking dups
	{
		ft_error_free(tab);
		return (0);
	}
	list_args(tab, &stack_a, nums);
	free(tab);
	return (stack_a);
}
