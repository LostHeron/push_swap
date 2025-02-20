/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:32:49 by jweber            #+#    #+#             */
/*   Updated: 2025/02/18 17:57:23 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "instruction.h"
#include "push_swap.h"

static int	chose_swap(t_stack *a, int *rotation);

int	bubble_sort(t_stack *a)
{
	int		i;
	int		j;
	int		rotation;

	i = 0;
	rotation = 0;
	while (i < a->size)
	{
		j = 0;
		while (++j < a->size - 1)
		{
			if (chose_swap(a, &rotation) < 0)
				return (-1);
			j++;
		}
		if (inst_r(a, DISPLAY) < 0)
			return (-1);
		if (rotation == 0)
			break ;
		i++;
	}
	return (0);
}

static int	chose_swap(t_stack *a, int *rotation)
{
	if (((t_pair *)a->head->content)->value
		> ((t_pair *)a->head->next->content)->value)
	{
		*rotation = 1;
		if (inst_s(a, DISPLAY) < 0)
			return (-1);
	}
	if (inst_r(a, DISPLAY) < 0)
		return (-1);
	return (0);
}
