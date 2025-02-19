/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:56:08 by jweber            #+#    #+#             */
/*   Updated: 2025/02/19 10:59:03 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGE_SORT_H
# define MERGE_SORT_H

# include "lists_double_circular.h"

typedef struct s_pos
{
	int	start;
	int	end;
}	t_pos;

int	case_size_two(t_stack **stacks, int order);
int	get_val_start(t_stack b);
int	get_val_end(t_stack b);
int	pa_at_end(t_stack **stacks);
int	get_middle(int start, int end);
int	push_case(t_stack **stacks, int *middle, t_pos pos, int order);

#endif 
