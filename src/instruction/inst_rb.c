/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_rb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:23:01 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 10:55:19 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "io.h"
#include "instruction.h"
#include "push_swap.h"
#include <stdlib.h>

int	inst_rb(t_stack **stacks, int display)
{
	if (stacks[STACK_B]->head == NULL)
		return (0);
	stacks[STACK_B]->head = stacks[STACK_B]->head->next;
	if (display == DISPLAY)
		if (ft_printf_fd(1, "rb\n") < 0)
			return (WRITE_ERROR);
	return (0);
}
