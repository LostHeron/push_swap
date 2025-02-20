/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:36:13 by jweber            #+#    #+#             */
/*   Updated: 2025/02/20 18:25:58 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "lists_double_circular.h"

int	selection_sort(t_stack *a, t_stack *b);
int	insertion_sort(t_stack *a);
int	bubble_sort(t_stack *a);
int	sort_stack(t_stack *a, t_stack *b);
int	merge_sort(t_stack **stack_array);
int	indexing(t_stack a);
int	radix_sort(t_stack *a, t_stack *b);
int	radix_sort_ternary(t_stack **stacks);
int	sort_three(t_stack *a);
int	cost_sort(t_stack *a, t_stack *b);
int	check_sorted(t_stack a);

#endif
