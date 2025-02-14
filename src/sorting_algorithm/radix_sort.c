/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:06:45 by jweber            #+#    #+#             */
/*   Updated: 2025/02/14 11:11:53 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "push_swap.h"
#include "instruction.h"
#include "sorting.h"

static int	get_nb_digits(t_stack a);
static void	push_zeros(t_stack *a, t_stack *b, int i);

int	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	nb_digits;

	if (indexing(*a) < 0)
		return (-1);
	nb_digits = get_nb_digits(*a);
	i = 0;
	while (i < nb_digits)
	{
		push_zeros(a, b, i);
		i++;
	}
	return (0);
}

static void	push_zeros(t_stack *a, t_stack *b, int i)
{
	int	j;
	int	nb_pushed;
	int	nb_elems;

	j = 0;
	nb_pushed = 0;
	nb_elems = a->size;
	while (j < nb_elems)
	{
		if ((((t_pair *)a->head->content)->index & (1 << i)) == 0)
		{
			inst_pb(a, b);
			nb_pushed++;
		}
		else
			inst_r(a);
		j++;
	}
	j = -1;
	while (++j < nb_pushed)
		inst_pa(a, b);
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
