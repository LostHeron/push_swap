/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:48:24 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 12:30:46 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "lists_double_circular.h"
#include "sorting.h"
#include "io.h"

int	sort_stack(t_stack **stacks)
{
	int		i;

	i = 7;
	if (i == 0)
	{
		ft_printf_fd(1, "dans merge sort\n");
		merge_sort(stacks);
	}
	else if (i == 1)
	{
		ft_printf_fd(1, "dans bubble_sort\n");
		bubble_sort(stacks);
	}
	else if (i == 2)
	{
		ft_printf_fd(1, "ici dans radix_sort\n");
		if (radix_sort(stacks) < 0)
			return (-1);
	}
	else if (i == 3)
	{
		ft_printf_fd(1, "dans radix_sort_ternary\n");
		if (radix_sort_ternary(stacks) < 0)
			return (-1);
	}
	else if (i == 4)
	{
		ft_printf_fd(1, "dans cost_sort\n");
		if (cost_sort(stacks) < 0)
			return (-1);
	}
	else if (i == 5)
	{
		ft_printf_fd(1, "dans selection sort\n");
		selection_sort(stacks);
	}
	else if (i == 6)
	{
		ft_printf_fd(1, "dans insertion sort\n");
		insertion_sort(stacks);
	}
	return (0);
}
