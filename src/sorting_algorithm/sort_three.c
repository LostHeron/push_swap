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
#include <stdlib.h>

static void	case_nb1_greater_nb3(t_stack *a, int nb1, int nb2, int nb3);
static void	case_nb1_lower_nb3(t_stack *a, int nb1, int nb2, int nb3);

void	sort_three(t_stack *a)
{
	int	nb1;
	int	nb2;
	int	nb3;

	nb1 = ((t_pair *)a->head->content)->value;
	nb2 = ((t_pair *)a->head->next->content)->value;
	nb3 = ((t_pair *)a->head->next->next->content)->value;
	if (nb1 > nb3)
		case_nb1_greater_nb3(a, nb1, nb2, nb3);
	else
		case_nb1_lower_nb3(a, nb1, nb2, nb3);
	return ;
}

static void	case_nb1_greater_nb3(t_stack *a, int nb1, int nb2, int nb3)
{
	if (nb1 > nb2)
	{
		if (nb2 > nb3)
		{
			inst_s(a);
			inst_rr(a);
		}
		else
			inst_r(a);
	}
	else
		inst_rr(a);
}

static void	case_nb1_lower_nb3(t_stack *a, int nb1, int nb2, int nb3)
{
	if (nb1 < nb2)
	{
		if (nb2 > nb3)
		{
			inst_rr(a);
			inst_s(a);
		}
	}
	else
		inst_s(a);
}
