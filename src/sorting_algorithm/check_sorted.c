/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:25:12 by jweber            #+#    #+#             */
/*   Updated: 2025/02/20 18:25:27 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists_double_circular.h"
#include "push_swap.h"

int	check_sorted(t_stack a)
{
	int	i;

	if (a.size == 1)
		return (0);
	i = 0;
	while (i < a.size - 1)
	{
		if (((t_pair *)a.head->content)->value
			> ((t_pair *)a.head->next->content)->value)
			return (1);
		a.head = a.head->next;
		i++;
	}
	return (0);
}
