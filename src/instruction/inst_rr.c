/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:23:01 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 11:05:00 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "io.h"
#include "instruction.h"
#include "push_swap.h"

int	inst_rr(t_stack **stacks, int display)
{
	inst_ra(stacks, NO_DISPLAY);
	inst_rb(stacks, NO_DISPLAY);
	if (display == DISPLAY)
		if (ft_printf_fd(1, "rr\n") < 0)
			return (WRITE_ERROR);
	return (0);
}
