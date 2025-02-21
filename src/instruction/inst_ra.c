/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_ra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:23:01 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 10:55:12 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "io.h"
#include "instruction.h"
#include <stdlib.h>

int	inst_ra(t_stack **stacks, int display)
{
	if (stacks[STACK_A]->head == NULL)
		return (0);
	stacks[STACK_A]->head = stacks[STACK_A]->head->next;
	if (display == DISPLAY)
		if (ft_printf_fd(1, "ra\n") < 0)
			return (-1);
	return (0);
}
