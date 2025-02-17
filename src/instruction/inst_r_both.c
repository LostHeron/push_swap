/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_r_both.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:24:59 by jweber            #+#    #+#             */
/*   Updated: 2025/02/17 14:26:34 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "io.h"
#include <stdlib.h>

void	inst_r_both(t_stack *a, t_stack *b)
{
	if (a->head == NULL)
		return ;
	a->head = a->head->next;
	b->head = b->head->next;
	ft_printf_fd(1, "rr\n");
}
