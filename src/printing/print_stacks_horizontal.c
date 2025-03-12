/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:12:38 by jweber            #+#    #+#             */
/*   Updated: 2025/02/11 16:47:53 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists_double_circular.h"
#include "push_swap.h"
#include "ft_io.h"

void	print_stacks_horizontal(t_stack a, t_stack b)
{
	int	i;
	int	a_size;
	int	b_size;

	a_size = a.size;
	ft_printf_fd(1, "stack a size = %i\n", a_size);
	b_size = b.size;
	ft_printf_fd(1, "stack b size = %i\n", b_size);
	ft_printf_fd(1, "\n");
	i = 0;
	while (i < a.size)
	{
		ft_printf_fd(1, "%i, ", ((t_pair *)a.head->content)->value);
		a.head = a.head->next;
		i++;
	}
	ft_printf_fd(1, " |a\n");
	i = 0;
	while (i < b.size)
	{
		ft_printf_fd(1, "%i, ", ((t_pair *)b.head->content)->value);
		b.head = b.head->next;
		i++;
	}
	ft_printf_fd(1, " |b\n");
}
