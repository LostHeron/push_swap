/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:43:26 by jweber            #+#    #+#             */
/*   Updated: 2025/01/30 15:52:10 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	*clear_list(t_stack *a)
{
	int		i;
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = a.head;
	i = 0;
	while (i < (*a).size)
	{
		tmp2 = tmp1.next;
		free(tmp1);
		tmp1 = tmp2;	
		i++;
	}
	(*a).head = NULL;
	(*a).size = 0;
	return (NULL);
}
