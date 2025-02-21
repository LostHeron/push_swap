/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_sort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:58:02 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 11:24:22 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COST_SORT_H
# define COST_SORT_H

# include "lists_double_circular.h"

typedef struct s_inst
{
	int	type;
	int	nb_ra;
	int	nb_rb;
	int	nb_rr;
	int	nb_rra;
	int	nb_rrb;
	int	nb_rrr;
	int	nb_inst;
}				t_inst;

void	calculate_rr_and_rrr(t_inst *inst);
int		get_ra(t_stack a, int val_b);
int		rotate_to_min(t_stack **stacks);
int		push_using_ra_rb(t_stack **stacks, t_inst inst);
int		push_using_rra_rrb(t_stack **stacks, t_inst inst);
int		push_using_rra_rb(t_stack **stacks, t_inst inst);
int		push_using_ra_rrb(t_stack **stacks, t_inst inst);
int		push_all_to_b(t_stack **stacks);

#endif 
