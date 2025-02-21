/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_pa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:40:51 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 10:53:53 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "io.h"
#include "instruction.h"
#include <stdlib.h>

int	inst_pa(t_stack **stacks, int display)
{
	t_node	*tmp;

	tmp = ft_dc_stack_rem(stacks[STACK_B]);
	if (tmp == NULL)
		return (0);
	ft_dc_stack_add(stacks[STACK_A], tmp);
	if (display == DISPLAY)
		if (ft_printf_fd(1, "pa\n") < 0)
			return (-1);
	return (0);
}
