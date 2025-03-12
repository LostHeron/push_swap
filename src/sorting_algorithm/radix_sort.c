/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:06:45 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 11:39:04 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists_double_circular.h"
#include "push_swap.h"
#include "instruction.h"
#include "sorting.h"

static int	get_nb_digits(t_stack a);
static int	push_zeros(t_stack **stacks, int i);

int	radix_sort(t_stack **stacks)
{
	int	i;
	int	nb_digits;

	if (indexing(*stacks[STACK_A]) < 0)
		return (MALLOC_FAIL);
	nb_digits = get_nb_digits(*stacks[STACK_A]);
	i = 0;
	while (i < nb_digits)
	{
		if (push_zeros(stacks, i) < 0)
			return (WRITE_ERROR);
		i++;
	}
	return (0);
}

static int	push_zeros(t_stack **stacks, int i)
{
	int	j;
	int	nb_pushed;
	int	nb_elems;

	j = 0;
	nb_pushed = 0;
	nb_elems = stacks[STACK_A]->size;
	while (j < nb_elems)
	{
		if ((((t_pair *)stacks[STACK_A]->head->content)->index & (1 << i)) == 0)
		{
			if (inst_pb(stacks, DISPLAY) < 0)
				return (WRITE_ERROR);
			nb_pushed++;
		}
		else
			if (inst_ra(stacks, DISPLAY) < 0)
				return (WRITE_ERROR);
		j++;
	}
	j = -1;
	while (++j < nb_pushed)
		if (inst_pa(stacks, DISPLAY) < 0)
			return (WRITE_ERROR);
	return (0);
}

static int	get_nb_digits(t_stack a)
{
	int	nb_digits;
	int	nb_elems;

	nb_elems = a.size;
	nb_digits = 0;
	while (nb_elems > 1)
	{
		nb_elems = nb_elems / 2;
		nb_digits++;
	}
	nb_digits++;
	return (nb_digits);
}
