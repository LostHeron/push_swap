/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_pa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:40:51 by jweber            #+#    #+#             */
/*   Updated: 2025/02/18 17:47:05 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "io.h"
#include <stdlib.h>

int	inst_pa(t_stack *pa, t_stack *pb)
{
	t_node	*tmp;

	tmp = ft_dc_stack_rem(pb);
	if (tmp == NULL)
		return (-2);
	ft_dc_stack_add(pa, tmp);
	if (ft_printf_fd(1, "pa\n") < 0)
		return (-1);
	return (0);
}
