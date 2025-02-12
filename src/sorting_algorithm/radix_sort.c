/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:06:45 by jweber            #+#    #+#             */
/*   Updated: 2025/02/11 17:22:43 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "push_swap.h"
#include "printing.h"
#include "instruction.h"
#include "io.h"
#include "sorting.h"
#include <stdlib.h>

static int	indexing(t_stack a);
static void	sort_array(t_node **node_array, int nb_elems);
static void	fill_index(t_node **node_array, int nb_elems);
static int	get_nb_digits(t_stack a);

int	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	nb_digits;
	int	nb_elems;
	int	nb_pushed;

	if (indexing(*a) < 0)
		return (-1);
	nb_digits = get_nb_digits(*a);
	nb_elems = a->size;
	i = 0;
	while (i < nb_digits)
	{
		j = 0;
		nb_pushed = 0;
		while (j < nb_elems)
		{
			if ((((t_pair *)a->head->content)->index & (1 << i)) == 0)
			{
				inst_pb(a, b);
				nb_pushed++;
			}
			else
			{
				inst_r(a);
			}
			j++;
		}
		j = 0;
		while (j < nb_pushed)
		{
			inst_pa(a, b);
			j++;
		}
		i++;
	}
	return (0);
}

static int	indexing(t_stack a)
{
	int		i;
	t_node	**node_array;

	node_array = malloc(a.size * sizeof(t_node *));
	if (node_array == NULL)
		return (-1);
	i = 0;
	while (i < a.size)
	{
		node_array[i] = a.head;
		a.head = a.head->next;
		i++;
	}
	sort_array(node_array, a.size);
	fill_index(node_array, a.size);
	return (0);
}

static void	sort_array(t_node **node_array, int nb_elems)
{
	int		i;
	int		j;
	t_node	*tmp;

	i = 0;
	while (i < nb_elems)
	{
		j = 0;
		while (j < nb_elems - 1 - i)
		{
			if (((t_pair *)node_array[j]->content)->value
				> ((t_pair *)node_array[j + 1]->content)->value)
			{
				tmp = node_array[j];
				node_array[j] = node_array[j + 1];
				node_array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	fill_index(t_node **node_array, int nb_elems)
{
	int	i;

	i = 0;
	while (i < nb_elems)
	{
		((t_pair *)node_array[i]->content)->index = i;
		i++;
	}
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
