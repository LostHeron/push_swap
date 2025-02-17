/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:45:19 by jweber            #+#    #+#             */
/*   Updated: 2025/02/17 14:27:19 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# include "lists_double_circular.h"

void	inst_s(t_stack *a);
int		inst_pb(t_stack *pa, t_stack *pb);
int		inst_pa(t_stack *pa, t_stack *pb);
void	inst_r(t_stack *a);
void	inst_r_both(t_stack *a, t_stack *b);
void	inst_rr(t_stack *a);
void	inst_rr_both(t_stack *a, t_stack *b);

#endif
