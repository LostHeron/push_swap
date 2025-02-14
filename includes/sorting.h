/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:36:13 by jweber            #+#    #+#             */
/*   Updated: 2025/02/14 11:20:56 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "lists_double_circular.h"

void	selection_sort(t_stack *a, t_stack *b);
void	insertion_sort(t_stack *a);
void	bubble_sort(t_stack *a);
int		sort_stack(t_stack *a, t_stack *b);
void	merge_sort(t_stack **stack_array);
int		indexing(t_stack a);
int		radix_sort(t_stack *a, t_stack *b);
int		radix_sort_ternary(t_stack **stacks);

#endif
