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
#include "push_swap.h"
#include "io.h"

void	inst_s(t_stack *a)
{
	int		tmp;
	t_node	*head;
	t_node	*next;

	head = a->head;
	next = head->next;
	tmp = ((t_pair *)head->content)->value;
	((t_pair *)head->content)->value = ((t_pair *)next->content)->value;
	((t_pair *)next->content)->value = tmp;
	ft_printf_fd(1, "s%s\n", a->name);
}
