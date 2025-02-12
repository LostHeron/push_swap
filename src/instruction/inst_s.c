/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:29:01 by jweber            #+#    #+#             */
/*   Updated: 2025/02/11 17:05:19 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "io.h"

void	inst_s(t_stack *a)
{
	t_node	*tmp_prev;
	t_node	*tmp_next_next;
	t_node	*old_head;
	t_node	*old_next;

	tmp_prev = a->head->prev;
	tmp_next_next = a->head->next->next;
	old_head = a->head;
	old_next = a->head->next;
	tmp_prev->next = old_next;
	tmp_next_next->prev = old_head;
	a->head = old_next;
	old_next->next = old_head;
	old_next->prev = tmp_prev;
	old_head->prev = old_next;
	old_head->next = tmp_next_next;
	ft_printf_fd(1, "s%s\n", a->name);
}
