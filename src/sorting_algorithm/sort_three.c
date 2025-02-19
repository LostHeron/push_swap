/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:02:19 by jweber            #+#    #+#             */
/*   Updated: 2025/02/17 14:27:41 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "push_swap.h"
#include "instruction.h"

static int	case_nb1_greater_nb3(t_stack *a, int nb1, int nb2, int nb3);
static int	case_nb1_lower_nb3(t_stack *a, int nb1, int nb2, int nb3);

int	sort_three(t_stack *a)
{
	int	nb1;
	int	nb2;
	int	nb3;

	nb1 = ((t_pair *)a->head->content)->value;
	nb2 = ((t_pair *)a->head->next->content)->value;
	nb3 = ((t_pair *)a->head->next->next->content)->value;
	if (nb1 > nb3)
	{
		if (case_nb1_greater_nb3(a, nb1, nb2, nb3) < 0)
			return (-1);
	}
	else
		if (case_nb1_lower_nb3(a, nb1, nb2, nb3) < 0)
			return (-1);
	return (0);
}

static int	case_nb1_greater_nb3(t_stack *a, int nb1, int nb2, int nb3)
{
	if (nb1 > nb2)
	{
		if (nb2 > nb3)
		{
			if (inst_s(a) < 0)
				return (-1);
			if (inst_rr(a) < 0)
				return (-1);
		}
		else
			if (inst_r(a) < 0)
				return (-1);
	}
	else
		if (inst_rr(a) < 0)
			return (-1);
	return (0);
}

static int	case_nb1_lower_nb3(t_stack *a, int nb1, int nb2, int nb3)
{
	if (nb1 < nb2)
	{
		if (nb2 > nb3)
		{
			if (inst_rr(a) < 0)
				return (-1);
			if (inst_s(a) < 0)
				return (-1);
		}
	}
	else
		if (inst_s(a) < 0)
			return (-1);
	return (0);
}
