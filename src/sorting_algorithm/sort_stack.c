/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:48:24 by jweber            #+#    #+#             */
/*   Updated: 2025/02/07 15:59:51 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "sorting.h"
#include "string.h"
#include "io.h"

int	sort_stack(t_stack *a, t_stack *b, char *option)
{
	t_stack	*stack_arr[2];

	ft_printf_fd(1, "DANS SORT_STACK\n");
	ft_printf_fd(1, "option = '%s'\n", option);
	if (ft_strcmp(option, "selection_sort") == 0)
	{
		ft_printf_fd(1, "dans selection sort\n");
		selection_sort(a, b);
	}
	else if (ft_strcmp(option, "merge_sort") == 0)
	{
		ft_printf_fd(1, "dans merge sort\n");
		stack_arr[0] = a;
		stack_arr[1] = b;
		merge_sort(stack_arr);
	}
	else if (ft_strcmp(option, "insertion_sort") == 0)
	{
		ft_printf_fd(1, "dans insertion_sort");
		selection_sort(a, b);
	}
	else if (ft_strcmp(option, "bubble_sort") == 0)
	{
		ft_printf_fd(1, "dans bubble_sort");
		bubble_sort(a);
	}
	else
	{
		return (1);
	}
	return (0);
}
