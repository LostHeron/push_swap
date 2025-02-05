/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:12:38 by jweber            #+#    #+#             */
/*   Updated: 2025/02/05 15:16:07 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "io.h"

static void	in_if(t_stack a, t_stack b);
static void	in_else(t_stack a, t_stack b);

void	print_stacks(t_stack a, t_stack b)
{
	int	diff;
	int	a_size;
	int	b_size;

	a_size = a.size;
	ft_printf_fd(1, "stack a size = %i\n", a_size);
	b_size = b.size;
	ft_printf_fd(1, "stack b size = %i\n", b_size);
	diff = a_size - b_size;
	ft_printf_fd(1, "\n");
	if (diff >= 0)
	{
		in_if(a, b);
	}
	else
	{
		in_else(a, b);
	}
	ft_printf_fd(1, "_ \t\t_ \t\n");
	ft_printf_fd(1, "a \t\tb \t\n");
}

static void	in_if(t_stack a, t_stack b)
{
	int	i;

	i = 0;
	while (i < a.size)
	{
		if (i + b.size < a.size)
		{
			ft_printf_fd(1, "%i \t\t  \t\n", *((int *)a.head->content));
			a.head = a.head->next;
		}
		else
		{
			ft_printf_fd(1, "%i \t\t%i \t\n", *((int *)a.head->content),
				*((int *)b.head->content));
			a.head = a.head->next;
			b.head = b.head->next;
		}
		i++;
	}
}

static void	in_else(t_stack a, t_stack b)
{
	int	i;

	i = 0;
	while (i < b.size)
	{
		if (i + a.size < b.size)
		{
			ft_printf_fd(1, "  \t\t%i \t\n", *((int *)(b.head->content)));
			b.head = b.head->next;
		}
		else
		{
			ft_printf_fd(1, "%i \t\t%i \t\n", *((int *)a.head->content),
				*((int *)b.head->content));
			a.head = a.head->next;
			b.head = b.head->next;
		}
		i++;
	}
}
