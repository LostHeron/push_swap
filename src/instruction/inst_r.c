/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:23:01 by jweber            #+#    #+#             */
/*   Updated: 2025/02/18 17:46:39 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "io.h"
#include "instruction.h"
#include <stdlib.h>

int	inst_r(t_stack *a, int display)
{
	if (a->head == NULL)
		return (0);
	a->head = a->head->next;
	if (display == DISPLAY)
		if (ft_printf_fd(1, "r%s\n", a->name) < 0)
			return (-1);
	return (0);
}
