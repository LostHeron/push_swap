/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:04:21 by jweber            #+#    #+#             */
/*   Updated: 2025/02/11 16:50:58 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "push_swap.h"
#include "instruction.h"

static int	get_min_index(t_stack a);

void	selection_sort(t_stack *a, t_stack *b)
{
	int		i;
	int		j;
	int		nb_elems;
	int		min_index;

	i = 0;
	nb_elems = a->size;
	while (i < nb_elems)
	{
		min_index = get_min_index(*a);
		j = 0;
		while (j < min_index)
		{
			inst_r(a);
			j++;
		}
		inst_pb(a, b);
		i++;
	}
	i = 0;
	while (i < nb_elems)
	{
		inst_pa(a, b);
		i++;
	}
}

static int	get_min_index(t_stack a)
{
	int	i;
	int	min;
	int	min_index;

	i = 0;
	min = ((t_pair *)a.head->content)->value;
	min_index = 0;
	while (i < a.size)
	{
		if (((t_pair *)a.head->content)->value < min)
		{
			min = ((t_pair *)a.head->content)->value;
			min_index = i;
		}
		i++;
		a.head = a.head->next;
	}
	return (min_index);
}
