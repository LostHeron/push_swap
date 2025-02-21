/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exec_inst_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:31:33 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 13:44:06 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "instruction.h"
#include "checker_bonus.h"

int	exec_inst(t_stack **stacks, t_stack inst)
{
	int	i;
	int	(*f[11])(t_stack **stacks, int display);

	f[INST_SA] = &inst_sa;
	f[INST_SB] = &inst_sb;
	f[INST_SS] = &inst_ss;
	f[INST_PA] = &inst_pa;
	f[INST_PB] = &inst_pb;
	f[INST_RA] = &inst_ra;
	f[INST_RB] = &inst_rb;
	f[INST_RR] = &inst_rr;
	f[INST_RRA] = &inst_rra;
	f[INST_RRB] = &inst_rrb;
	f[INST_RRR] = &inst_rrr;
	i = 0;
	while (i < inst.size)
	{
		f[*((int *)inst.head->content)](stacks, NO_DISPLAY);
		i++;
		inst.head = inst.head->next;
	}
	return (0);
}

/*
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
	if (ft_strcmp(inst_i, "ra\n") == 0)
		return (inst_r(a, NO_DISPLAY));
	else if (ft_strcmp(inst_i, "rb\n") == 0)
		return (inst_r(b, NO_DISPLAY));
	else if (ft_strcmp(inst_i, "rr\n") == 0)
		return (inst_r_both(a, b, NO_DISPLAY));
	else if (ft_strcmp(inst_i, "rra\n") == 0)
		return (inst_rr(a, NO_DISPLAY));
	else if (ft_strcmp(inst_i, "rrb\n") == 0)
		return (inst_rr(b, NO_DISPLAY));
	else if (ft_strcmp(inst_i, "rrr\n") == 0)
		return (inst_rr_both(a, b, NO_DISPLAY));
	else
		return (-1);
}
*/
