/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:45:41 by jweber            #+#    #+#             */
/*   Updated: 2025/02/06 18:16:36 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "lists_double_circular.h"

void	insertion_sort(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (i != 0)
		{
			if (*((int *)a->head->content) < *((int *)a->head->prev->content))
			{
				inst_rr(a);
				inst_s(a);
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
