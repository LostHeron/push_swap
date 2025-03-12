/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:36:13 by jweber            #+#    #+#             */
/*   Updated: 2025/02/24 11:51:38 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "ft_lists_double_circular.h"

int	check_sorted(t_stack a);
int	indexing(t_stack a);
int	sort_three(t_stack **stacks);
int	selection_sort(t_stack **stacks);
int	bubble_sort(t_stack **stacks);
int	insertion_sort(t_stack **stacks);
int	merge_sort(t_stack **stacks);
int	radix_sort(t_stack **stacks);
int	radix_sort_ternary(t_stack **stacks);
int	cost_sort(t_stack **stacks);

#endif
