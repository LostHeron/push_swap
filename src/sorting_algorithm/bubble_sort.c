/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:32:49 by jweber            #+#    #+#             */
/*   Updated: 2025/02/06 17:05:15 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "instruction.h"

void	bubble_sort(t_stack *a)
{
	int		i;
	int		j;
	int		rotation;

	i = 0;
	rotation = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size - 1)
		{
			if (*((int *)a->head->content) > *((int *)a->head->next->content))
			{
				rotation = 1;
				s(a);
			}
			r(a);
			j++;
		}
		r(a);
		if (rotation == 0)
			break ;
		i++;
	}
}
