/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:16:19 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 13:41:03 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTING_H
# define PRINTING_H

# include "ft_lists_double_circular.h"

void	print_stacks(t_stack a, t_stack b);
void	print_stacks_horizontal(t_stack a, t_stack b);
void	print_stacks_index(t_stack a, t_stack b);
void	print_error(void);

#endif
