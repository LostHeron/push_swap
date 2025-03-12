/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:26:12 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 11:04:57 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists_double_circular.h"
#include "ft_io.h"
#include "instruction.h"
#include "push_swap.h"

int	inst_rrr(t_stack **stacks, int display)
{
	inst_rra(stacks, NO_DISPLAY);
	inst_rrb(stacks, NO_DISPLAY);
	if (display == DISPLAY)
		if (ft_printf_fd(1, "rrr\n") < 0)
			return (WRITE_ERROR);
	return (0);
}
