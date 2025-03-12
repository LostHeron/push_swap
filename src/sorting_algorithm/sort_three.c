/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:02:19 by jweber            #+#    #+#             */
/*   Updated: 2025/02/24 12:38:09 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists_double_circular.h"
#include "push_swap.h"
#include "instruction.h"

static int	case_nb1_greater_nb3(t_stack **stacks, int nb1, int nb2, int nb3);
static int	case_nb1_lower_nb3(t_stack **stacks, int nb1, int nb2, int nb3);

int	sort_three(t_stack **stacks)
{
	int	nb1;
	int	nb2;
	int	nb3;

	nb1 = ((t_pair *)stacks[STACK_A]->head->content)->value;
	nb2 = ((t_pair *)stacks[STACK_A]->head->next->content)->value;
	nb3 = ((t_pair *)stacks[STACK_A]->head->next->next->content)->value;
	if (stacks[STACK_A]->size <= 2)
	{
		if (nb1 > nb2)
			if (inst_sa(stacks, DISPLAY) < 0)
				return (WRITE_ERROR);
	}
	else
	{
		if (nb1 > nb3)
		{
			if (case_nb1_greater_nb3(stacks, nb1, nb2, nb3) < 0)
				return (WRITE_ERROR);
		}
		else
			if (case_nb1_lower_nb3(stacks, nb1, nb2, nb3) < 0)
				return (WRITE_ERROR);
	}
	return (0);
}

static int	case_nb1_greater_nb3(t_stack **stacks, int nb1, int nb2, int nb3)
{
	if (nb1 > nb2)
	{
		if (nb2 > nb3)
		{
			if (inst_sa(stacks, DISPLAY) < 0)
				return (WRITE_ERROR);
			if (inst_rra(stacks, DISPLAY) < 0)
				return (WRITE_ERROR);
		}
		else
			if (inst_ra(stacks, DISPLAY) < 0)
				return (WRITE_ERROR);
	}
	else
		if (inst_rra(stacks, DISPLAY) < 0)
			return (WRITE_ERROR);
	return (0);
}

static int	case_nb1_lower_nb3(t_stack **stacks, int nb1, int nb2, int nb3)
{
	if (nb1 < nb2)
	{
		if (nb2 > nb3)
		{
			if (inst_rra(stacks, DISPLAY) < 0)
				return (WRITE_ERROR);
			if (inst_sa(stacks, DISPLAY) < 0)
				return (WRITE_ERROR);
		}
	}
	else
		if (inst_sa(stacks, DISPLAY) < 0)
			return (WRITE_ERROR);
	return (0);
}
