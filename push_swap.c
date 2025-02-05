/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:49:25 by jweber            #+#    #+#             */
/*   Updated: 2025/02/05 14:42:38 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"
#include "lists_double_circular.h"
#include "io.h"
#include "parsing.h"
#include "instruction.h"
#include <stdlib.h>

//static void	my_print(void *a);
static void	*my_free(void *content);
static void	print_stacks(t_stack a, t_stack b);

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	a.head = NULL;
	a.size = 0;
	b.head = NULL;
	b.size = 0;
	if (argc <= 1)
	{
		return (0);
	}
	if (parse_input(&a, argc - 1, argv + 1) != 0)
	{
		ft_dc_stack_clear(&a, &my_free);
		ft_printf_fd(1, "Error\n");
		return (1);
	}
	ft_printf_fd(1, "test\n");
	ft_printf_fd(1, "affichage stacks:\n");
	print_stacks(a, b);
	ft_printf_fd(1, "sa \n");
	s(&a);
	print_stacks(a, b);
	ft_printf_fd(1, "pb pb pb  \n");
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	print_stacks(a, b);
	ft_printf_fd(1, "ra rb \n");
	r(&a);
	r(&b);
	print_stacks(a, b);
	ft_printf_fd(1, "rra rrb \n");
	rr(&a);
	rr(&b);
	print_stacks(a, b);
	ft_printf_fd(1, "sa \n");
	s(&a);
	print_stacks(a, b);
	ft_printf_fd(1, "pa pa pa  \n");
	pa(&a, &b);
	pa(&a, &b);
	pa(&a, &b);
	print_stacks(a, b);
	ft_dc_stack_clear(&a, &my_free);
	ft_dc_stack_clear(&b, &my_free);
}

static void	print_stacks(t_stack a, t_stack b)
{
	int	i;
	int	diff;
	int	a_size;
	int	b_size;

	a_size = a.size;
	ft_printf_fd(1, "stack a size = %i\n", a_size);
	b_size = b.size;
	ft_printf_fd(1, "stack b size = %i\n", b_size);
	diff = a_size - b_size;
	i = 0;
	ft_printf_fd(1, "\n");
	if (diff >= 0)
	{
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
	else
	{
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
	ft_printf_fd(1, "_ \t\t_ \t\n");
	ft_printf_fd(1, "a \t\tb \t\n");
}

static void	*my_free(void *content)
{
	if (content != NULL)
		free(content);
	return (NULL);
}

/*
static void	my_print(void *a)
{
	ft_printf_fd(1, "%i \t", *(int *)a);
}
*/
