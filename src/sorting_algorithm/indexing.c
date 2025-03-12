/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:09:43 by jweber            #+#    #+#             */
/*   Updated: 2025/02/24 12:34:22 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists_double_circular.h"
#include "ft_standard.h"
#include "push_swap.h"
#include <stdlib.h>

static void	sort_array(t_node **node_array, int nb_elems);

int	indexing(t_stack a)
{
	int		i;
	t_node	**node_array;

	node_array = ft_malloc(a.size * sizeof(t_node *));
	if (node_array == NULL)
		return (MALLOC_FAIL);
	i = 0;
	while (i < a.size)
	{
		node_array[i] = a.head;
		a.head = a.head->next;
		i++;
	}
	sort_array(node_array, a.size);
	i = 0;
	while (i < a.size)
	{
		((t_pair *)node_array[i]->content)->index = i;
		i++;
	}
	free(node_array);
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
