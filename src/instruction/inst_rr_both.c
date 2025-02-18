/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_rr_both.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:26:12 by jweber            #+#    #+#             */
/*   Updated: 2025/02/18 17:44:54 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "io.h"
#include <stdlib.h>

int	inst_rr_both(t_stack *a, t_stack *b)
{
	if (a->head == NULL)
		return (-2);
	a->head = a->head->prev;
	b->head = b->head->prev;
	if (ft_printf_fd(1, "rrr\n") < 0)
		return (-1);
	return (0);
}
