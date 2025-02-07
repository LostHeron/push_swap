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
#include <stdio.h>

int	sort_stack(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	if (i == 0)
	{
		printf("dans selection sort\n");
		//insertion_sort(a);
		merge_sort(a, b);
	}
	else
	{
		printf("dans insertion sort\n");
		selection_sort(a, b);
	}
	return (0);
}
