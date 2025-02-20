/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:29:01 by jweber            #+#    #+#             */
/*   Updated: 2025/02/18 17:45:26 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "io.h"
#include "instruction.h"

int	inst_s_both(t_stack *a, t_stack *b, int display)
{
	inst_s(a, NO_DISPLAY);
	inst_s(b, NO_DISPLAY);
	if (display == DISPLAY)
		if (ft_printf_fd(1, "ss%s\n", a->name) < 0)
			return (-1);
	return (0);
}
