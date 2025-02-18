/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:23:01 by jweber            #+#    #+#             */
/*   Updated: 2025/02/18 17:45:46 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "io.h"
#include <stdlib.h>

int	inst_rr(t_stack *a)
{
	if (a->head == NULL)
		return (-2);
	a->head = a->head->prev;
	if (ft_printf_fd(1, "rr%s\n", a->name) < 0)
		return (-1);
	return (0);
}
