/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:42:58 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 13:49:09 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "ft_lists_double_circular.h"

t_stack	read_instruction(int *p_err_code);
int		check_inst(char *inst_i);
int		exec_inst(t_stack **stacks, t_stack inst);

#endif
