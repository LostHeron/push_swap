/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:04:21 by jweber            #+#    #+#             */
/*   Updated: 2025/02/05 16:43:47 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "instruction.h"

static int	get_min_index(t_stack a);

void	bubble_sort(t_stack *paa, t_stack *pbb)
{
	int		i;
	int		j;
	int		nb_elems;
	int		min_index;

	i = 0;
	nb_elems = paa->size;
	while (i < nb_elems)
	{
		min_index = get_min_index(*paa);
		j = 0;
		while (j < min_index)
		{
			r(paa);
			j++;
		}
		pb(paa, pbb);
		i++;
	}
	i = 0;
	while (i < nb_elems)
	{
		pa(paa, pbb);
		i++;
	}
}

static int	get_min_index(t_stack a)
{
	int	i;
	int	min;
	int	min_index;

	i = 0;
	min = *((int *)(a.head->content));
	min_index = 0;
	while (i < a.size)
	{
		if (*((int *)a.head->content) < min)
		{
			min = *((int *)a.head->content);
			min_index = i;
		}
		i++;
		a.head = a.head->next;
	}
	return (min_index);
}
