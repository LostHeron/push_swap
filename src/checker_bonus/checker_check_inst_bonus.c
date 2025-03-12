/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_check_inst_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:31:33 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 12:56:55 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_string.h"
#include "instruction.h"

int	check_inst(char *inst_i)
{
	if (ft_strcmp(inst_i, "sa\n") == 0)
		return (INST_SA);
	else if (ft_strcmp(inst_i, "sb\n") == 0)
		return (INST_SB);
	else if (ft_strcmp(inst_i, "ss\n") == 0)
		return (INST_SS);
	else if (ft_strcmp(inst_i, "pa\n") == 0)
		return (INST_PA);
	else if (ft_strcmp(inst_i, "pb\n") == 0)
		return (INST_PB);
	else if (ft_strcmp(inst_i, "ra\n") == 0)
		return (INST_RA);
	else if (ft_strcmp(inst_i, "rb\n") == 0)
		return (INST_RB);
	else if (ft_strcmp(inst_i, "rr\n") == 0)
		return (INST_RR);
	else if (ft_strcmp(inst_i, "rra\n") == 0)
		return (INST_RRA);
	else if (ft_strcmp(inst_i, "rrb\n") == 0)
		return (INST_RRB);
	else if (ft_strcmp(inst_i, "rrr\n") == 0)
		return (INST_RRR);
	else
		return (INVALID_INST);
}
