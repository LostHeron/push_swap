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

#include "lists_double_circular.h"
#include "push_swap.h"
#include "io.h"

static void	in_if(t_stack a, t_stack b);
static void	in_else(t_stack a, t_stack b);

void	print_stacks_index(t_stack a, t_stack b)
{
	int	diff;
	int	a_size;
	int	b_size;

	ft_printf_fd(1, "~~~~~~~~~~~~~~~~~~~~~~~\n");
	ft_printf_fd(1, "dans print_stacks_index\n");
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
	ft_printf_fd(1, "_ \t\t \t\t_ \t\n");
	ft_printf_fd(1, "a \t\t \t\tb \t\n");
	ft_printf_fd(1, "~~~~~~~~~~~~~~~~~~~~~~~\n");
}

static void	in_if(t_stack a, t_stack b)
{
	int	i;

	i = 0;
	while (i < a.size)
	{
		if (i + b.size < a.size)
		{
			ft_printf_fd(1, "%i \t\t%i  \t\n",
				((t_pair *)a.head->content)->value,
				((t_pair *)a.head->content)->index);
			a.head = a.head->next;
		}
		else
		{
			ft_printf_fd(1, "%i \t\t%i \t\t%i \t\t%i \t\n",
				((t_pair *)a.head->content)->value,
				((t_pair *)a.head->content)->index,
				((t_pair *)b.head->content)->value,
				((t_pair *)b.head->content)->index);
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
			ft_printf_fd(1, "  \t\t  \t\t%i \t\t%i\t\n",
				((t_pair *) b.head->content)->value,
				((t_pair *) b.head->content)->index);
			b.head = b.head->next;
		}
		else
		{
			ft_printf_fd(1, "%i \t\t%i \t\t%i \t\t%i \t\n",
				((t_pair *)a.head->content)->value,
				((t_pair *)a.head->content)->index,
				((t_pair *)b.head->content)->value,
				((t_pair *)b.head->content)->index);
			a.head = a.head->next;
			b.head = b.head->next;
		}
		i++;
	}
}
