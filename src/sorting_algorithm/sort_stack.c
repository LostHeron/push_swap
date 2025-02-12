/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:48:24 by jweber            #+#    #+#             */
/*   Updated: 2025/02/11 17:03:32 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "sorting.h"
#include "io.h"

int	sort_stack(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*stack_arr[2];

	i = 2;
	if (i == 0)
	{
		ft_printf_fd(1, "dans merge sort\n");
		stack_arr[0] = a;
		stack_arr[1] = b;
		merge_sort(stack_arr);
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
	else
	{
		ft_printf_fd(1, "dans selection sort\n");
		selection_sort(a, b);
	}
	return (0);
}
