/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:29:01 by jweber            #+#    #+#             */
/*   Updated: 2025/02/05 14:32:31 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "io.h"

void	s(t_stack *a)
{
	int		tmp;
	t_node	*head;
	t_node	*next;

	head = a->head;
	next = head->next;
	tmp = *((int *)head->content);
	*((int *)head->content) = *((int *)next->content);
	*((int *)next->content) = tmp;
	ft_printf_fd(1, "s%s\n", a->name);
}
