/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:32:49 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 12:29:12 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "instruction.h"
#include "push_swap.h"

static int	chose_swap(t_stack **stacks, int *rotation);

int	bubble_sort(t_stack **stacks)
{
	int		i;
	int		j;
	int		rotation;

	i = 0;
	rotation = 0;
	while (i < stacks[STACK_A]->size)
	{
		j = 0;
		while (j < stacks[STACK_A]->size - 1)
		{
			if (chose_swap(stacks, &rotation) < 0)
				return (-1);
			j++;
		}
		if (inst_ra(stacks, DISPLAY) < 0)
			return (-1);
		if (rotation == 0)
			break ;
		i++;
	}
	return (0);
}

static int	chose_swap(t_stack **stacks, int *rotation)
{
	t_stack	*a;

	a = stacks[STACK_A];
	if (((t_pair *)a->head->content)->value
		> ((t_pair *)a->head->next->content)->value)
	{
		*rotation = 1;
		if (inst_sa(stacks, DISPLAY) < 0)
			return (-1);
	}
	if (inst_ra(stacks, DISPLAY) < 0)
		return (-1);
	return (0);
}
