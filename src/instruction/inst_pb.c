/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_pb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:40:51 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 10:54:34 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_lists_double_circular.h"
#include "instruction.h"
#include "push_swap.h"
#include <stdlib.h>

int	inst_pb(t_stack **stacks, int display)
{
	t_node	*tmp;

	tmp = ft_dc_stack_rem(stacks[STACK_A]);
	if (tmp == NULL)
		return (0);
	ft_dc_stack_add(stacks[STACK_B], tmp);
	if (display == DISPLAY)
		if (ft_printf_fd(1, "pb\n") < 0)
			return (WRITE_ERROR);
	return (0);
}
