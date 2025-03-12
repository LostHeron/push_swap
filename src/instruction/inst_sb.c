/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_sb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:29:01 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 11:04:13 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists_double_circular.h"
#include "ft_io.h"
#include "instruction.h"
#include "push_swap.h"

static void	case_size_greater_three(t_stack **stacks);

int	inst_sb(t_stack **stacks, int display)
{
	if (stacks[STACK_B]->size <= 1)
		return (0);
	else if (stacks[STACK_B]->size == 2)
		inst_rb(stacks, NO_DISPLAY);
	else
	{
		case_size_greater_three(stacks);
	}
	if (display == DISPLAY)
		if (ft_printf_fd(1, "sb\n") < 0)
			return (WRITE_ERROR);
	return (0);
}

static void	case_size_greater_three(t_stack **stacks)
{
	t_node	*tmp_prev;
	t_node	*tmp_next_next;
	t_node	*old_head;
	t_node	*old_next;

	tmp_prev = stacks[STACK_B]->head->prev;
	tmp_next_next = stacks[STACK_B]->head->next->next;
	old_head = stacks[STACK_B]->head;
	old_next = stacks[STACK_B]->head->next;
	tmp_prev->next = old_next;
	tmp_next_next->prev = old_head;
	stacks[STACK_B]->head = old_next;
	old_next->next = old_head;
	old_next->prev = tmp_prev;
	old_head->prev = old_next;
	old_head->next = tmp_next_next;
}
