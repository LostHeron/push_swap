/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_rra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:26:12 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 11:00:45 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists_double_circular.h"
#include "ft_io.h"
#include "instruction.h"
#include "push_swap.h"
#include <stdlib.h>

int	inst_rra(t_stack **stacks, int display)
{
	if (stacks[STACK_A]->head == NULL)
		return (0);
	stacks[STACK_A]->head = stacks[STACK_A]->head->prev;
	if (display == DISPLAY)
		if (ft_printf_fd(1, "rra\n") < 0)
			return (WRITE_ERROR);
	return (0);
}
