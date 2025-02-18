/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_r_both.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:24:59 by jweber            #+#    #+#             */
/*   Updated: 2025/02/18 17:46:09 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "io.h"
#include <stdlib.h>

int	inst_r_both(t_stack *a, t_stack *b)
{
	if (a->head == NULL)
		return (-2);
	a->head = a->head->next;
	b->head = b->head->next;
	if (ft_printf_fd(1, "rr\n") < 0)
		return (-1);
	return (0);
}
