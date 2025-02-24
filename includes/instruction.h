/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:45:19 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 12:53:41 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# define DISPLAY 1
# define NO_DISPLAY 2

# include "lists_double_circular.h"

typedef enum e_stack_name
{
	STACK_A = 0,
	STACK_B,
}	t_stack_name;

typedef enum e_inst_type
{
	INST_SA = 0,
	INST_SB,
	INST_SS,
	INST_PA,
	INST_PB,
	INST_RA,
	INST_RB,
	INST_RR,
	INST_RRA,
	INST_RRB,
	INST_RRR
}	t_inst_type;

int	inst_pb(t_stack **stacks, int display);
int	inst_pa(t_stack **stacks, int display);
int	inst_sa(t_stack **stacks, int display);
int	inst_sb(t_stack **stacks, int display);
int	inst_ss(t_stack **stacks, int display);
int	inst_ra(t_stack **stacks, int display);
int	inst_rb(t_stack **stacks, int display);
int	inst_rr(t_stack **stacks, int display);
int	inst_rra(t_stack **stacks, int display);
int	inst_rrb(t_stack **stacks, int display);
int	inst_rrr(t_stack **stacks, int display);

#endif
