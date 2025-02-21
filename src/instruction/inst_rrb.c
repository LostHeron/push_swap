/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_rrb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:26:12 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 11:01:41 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "io.h"
#include "instruction.h"
#include <stdlib.h>

int	inst_rrb(t_stack **stacks, int display)
{
	if (stacks[STACK_B]->head == NULL)
		return (0);
	stacks[STACK_B]->head = stacks[STACK_B]->head->prev;
	if (display == DISPLAY)
		if (ft_printf_fd(1, "rrb\n") < 0)
			return (-1);
	return (0);
}
