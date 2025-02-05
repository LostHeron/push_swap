/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:45:19 by jweber            #+#    #+#             */
/*   Updated: 2025/02/05 14:35:13 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# include "lists_double_circular.h"

void	s(t_stack *a);
int		pb(t_stack *pa, t_stack *pb);
int		pa(t_stack *pa, t_stack *pb);
void	r(t_stack *a);
void	rr(t_stack *a);

#endif
