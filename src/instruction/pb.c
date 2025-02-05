/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:40:51 by jweber            #+#    #+#             */
/*   Updated: 2025/02/05 14:07:58 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include <stdlib.h>
#include <stdio.h>

int	pb(t_stack *pa, t_stack *pb)
{
	t_node	*tmp;

	tmp = ft_dc_stack_rem(pa);
	if (tmp == NULL)
		return (1);
	ft_dc_stack_add(pb, tmp);
	return (0);
}
