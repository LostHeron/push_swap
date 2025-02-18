/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_ternary.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:06:45 by jweber            #+#    #+#             */
/*   Updated: 2025/02/18 18:24:03 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "push_swap.h"
#include "instruction.h"
#include "sorting.h"
#include "math.h"

static int	chose_case(t_stack **stacks, int i,
				int *nb_push_up, int *nb_push_down);
static int	get_nb_digits(t_stack a);
static int	push_zeros_ones(t_stack **stacks, int i);

int	radix_sort_ternary(t_stack **stacks)
{
	int	i;
	int	nb_digits;

	if (indexing(*stacks[0]) < 0)
		return (-3);
	nb_digits = get_nb_digits(*stacks[0]);
	i = 0;
	while (i < nb_digits)
	{
		push_zeros_ones(stacks, i);
		i++;
	}
	return (0);
}

static int	push_zeros_ones(t_stack **stacks, int i)
{
	int	j;
	int	nb_pushed_up;
	int	nb_pushed_down;
	int	nb_elems;

	j = -1;
	nb_pushed_up = 0;
	nb_pushed_down = 0;
	nb_elems = stacks[0]->size;
	while (++j < nb_elems)
		chose_case(stacks, i, &nb_pushed_up, &nb_pushed_down);
	j = -1;
	while (++j < nb_pushed_down)
	{
		if (inst_rr(stacks[1]) < 0)
			return (-1);
		if (inst_pa(stacks[0], stacks[1]) < 0)
			return (-1);
	}
	j = -1;
	while (++j < nb_pushed_up)
		if (inst_pa(stacks[0], stacks[1]) < 0)
			return (-1);
	return (0);
}

static int	chose_case(t_stack **stacks, int i,
					int *nb_push_up, int *nb_push_down)
{
	int	tmp_index;

	tmp_index = ((t_pair *)stacks[0]->head->content)->index;
	tmp_index = tmp_index / ft_power(3, i);
	if (tmp_index % 3 == 0)
	{
		if (inst_pb(stacks[0], stacks[1]) < 0)
			return (-1);
		(*nb_push_up)++;
	}
	else if (tmp_index % 3 == 1)
	{
		if (inst_pb(stacks[0], stacks[1]) < 0)
			return (-1);
		if (inst_r(stacks[1]) < 0)
			return (-1);
		(*nb_push_down)++;
	}
	else if (tmp_index % 3 == 2)
		if (inst_r(stacks[0]) < 0)
			return (-1);
	return (0);
}

static int	get_nb_digits(t_stack a)
{
	int	nb_digits;
	int	nb_elems;

	nb_elems = a.size - 1;
	nb_digits = 0;
	while (nb_elems > 2)
	{
		nb_elems = nb_elems / 3;
		nb_digits++;
	}
	nb_digits++;
	return (nb_digits);
}
