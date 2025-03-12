/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_ss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:29:01 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 11:04:45 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists_double_circular.h"
#include "ft_io.h"
#include "instruction.h"
#include "push_swap.h"

int	inst_ss(t_stack **stacks, int display)
{
	inst_sa(stacks, NO_DISPLAY);
	inst_sb(stacks, NO_DISPLAY);
	if (display == DISPLAY)
		if (ft_printf_fd(1, "ss\n") < 0)
			return (WRITE_ERROR);
	return (0);
}
