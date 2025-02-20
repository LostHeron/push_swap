/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:31:33 by jweber            #+#    #+#             */
/*   Updated: 2025/02/20 18:56:19 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "string.h"
#include "instruction.h"

static int	exec_inst_s_p(t_stack *a, t_stack *b, char *inst_i);
static int	exec_inst_r(t_stack *a, t_stack *b, char *inst_i);

int	exec_inst(t_stack *a, t_stack *b, t_stack inst)
{
	int		i;
	char	*inst_i;

	i = 0;
	while (i < inst.size)
	{
		inst_i = (char *)inst.head->content;
		if (exec_inst_s_p(a, b, inst_i) == 0)
			inst.head = inst.head->next;
		else if (exec_inst_r(a, b, inst_i) == 0)
			inst.head = inst.head->next;
		else
			return (-1);
		i++;
	}
	return (0);
}

static int	exec_inst_s_p(t_stack *a, t_stack *b, char *inst_i)
{
	if (ft_strcmp(inst_i, "sa\n") == 0)
		return (inst_s(a, NO_DISPLAY));
	else if (ft_strcmp(inst_i, "sb\n") == 0)
		return (inst_s(b, NO_DISPLAY));
	else if (ft_strcmp(inst_i, "ss\n") == 0)
		return (inst_s_both(a, b, NO_DISPLAY));
	else if (ft_strcmp(inst_i, "pa\n") == 0)
		return (inst_pa(a, b, NO_DISPLAY));
	else if (ft_strcmp(inst_i, "pb\n") == 0)
		return (inst_pb(a, b, NO_DISPLAY));
	else
		return (-1);
}

static int	exec_inst_r(t_stack *a, t_stack *b, char *inst_i)
{
	if (ft_strcmp(inst_i, "ra") == 0)
		return (inst_r(a, NO_DISPLAY));
	else if (ft_strcmp(inst_i, "rb") == 0)
		return (inst_r(b, NO_DISPLAY));
	else if (ft_strcmp(inst_i, "rr") == 0)
		return (inst_r_both(a, b, NO_DISPLAY));
	else if (ft_strcmp(inst_i, "rra") == 0)
		return (inst_rr(a, NO_DISPLAY));
	else if (ft_strcmp(inst_i, "rrb") == 0)
		return (inst_rr(b, NO_DISPLAY));
	else if (ft_strcmp(inst_i, "rrr") == 0)
		return (inst_rr_both(a, b, NO_DISPLAY));
	else
		return (-1);
}
