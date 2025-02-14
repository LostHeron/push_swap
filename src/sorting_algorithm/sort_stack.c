/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:48:24 by jweber            #+#    #+#             */
/*   Updated: 2025/02/14 11:20:21 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "sorting.h"
#include "io.h"

int	sort_stack(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*stacks[2];

	i = 0;
	stacks[0] = a;
	stacks[1] = b;
	if (i == 0)
	{
		ft_printf_fd(1, "dans merge sort\n");
		merge_sort(stacks);
	}
	else if (i == 1)
	{
		ft_printf_fd(1, "dans bubble_sort\n");
		bubble_sort(a);
	}
	else if (i == 2)
	{
		ft_printf_fd(1, "dans radix_sort\n");
		if (radix_sort(a, b) < 0)
			return (-1);
	}
	else if (i == 3)
	{
		ft_printf_fd(1, "dans radix_sort_ternary\n");
		if (radix_sort_ternary(stacks) < 0)
			return (-1);
	}
	else
	{
		ft_printf_fd(1, "dans selection sort\n");
		selection_sort(a, b);
	}
	return (0);
}
