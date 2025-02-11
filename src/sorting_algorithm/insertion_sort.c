/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:45:41 by jweber            #+#    #+#             */
/*   Updated: 2025/02/11 16:54:28 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "push_swap.h"
#include "lists_double_circular.h"

static void	rr_and_s(t_stack *a);

void	insertion_sort(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (i != 0)
		{
			if (((t_pair *)a->head->content)->value
				< ((t_pair *)a->head->prev->content)->value)
			{
				rr_and_s(a);
				i--;
			}
			else
			{
				inst_r(a);
				i++;
			}
		}
		else
		{
			inst_r(a);
			i++;
		}
	}
}

static void	rr_and_s(t_stack *a)
{
	inst_rr(a);
	inst_s(a);
	return ;
}
