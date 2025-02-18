/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_pb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:40:51 by jweber            #+#    #+#             */
/*   Updated: 2025/02/18 17:46:50 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "lists_double_circular.h"
#include <stdlib.h>

int	inst_pb(t_stack *pa, t_stack *pb)
{
	t_node	*tmp;

	tmp = ft_dc_stack_rem(pa);
	if (tmp == NULL)
		return (-2);
	ft_dc_stack_add(pb, tmp);
	if (ft_printf_fd(1, "pb\n") < 0)
		return (-1);
	return (0);
}
