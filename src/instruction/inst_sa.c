/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_sa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:29:01 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 11:03:17 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "io.h"
#include "instruction.h"
#include "push_swap.h"

int	inst_sa(t_stack **stacks, int display)
{
	t_node	*tmp_prev;
	t_node	*tmp_next_next;
	t_node	*old_head;
	t_node	*old_next;

	if (stacks[STACK_A]->size == 0)
		return (0);
	tmp_prev = stacks[STACK_A]->head->prev;
	tmp_next_next = stacks[STACK_A]->head->next->next;
	old_head = stacks[STACK_A]->head;
	old_next = stacks[STACK_A]->head->next;
	tmp_prev->next = old_next;
	tmp_next_next->prev = old_head;
	stacks[STACK_A]->head = old_next;
	old_next->next = old_head;
	old_next->prev = tmp_prev;
	old_head->prev = old_next;
	old_head->next = tmp_next_next;
	if (display == DISPLAY)
		if (ft_printf_fd(1, "sa\n") < 0)
			return (WRITE_ERROR);
	return (0);
}
