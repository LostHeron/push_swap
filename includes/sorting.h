/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:36:13 by jweber            #+#    #+#             */
/*   Updated: 2025/02/05 16:40:47 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

#include "lists_double_circular.h"

void	quick_sort(t_stack *pa, t_stack *pb);
int	sort_stack(t_stack *a, t_stack *b);

#endif
