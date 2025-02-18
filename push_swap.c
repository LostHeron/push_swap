/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:49:25 by jweber            #+#    #+#             */
/*   Updated: 2025/02/11 16:42:32 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "lists_double_circular.h"
#include "io.h"
#include "parsing.h"
#include "printing.h"
#include "sorting.h"
#include <stdlib.h>

static void	*my_free(void *content);
static int	check_sorted(t_stack a);

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	a.head = NULL;
	a.name = "a";
	a.size = 0;
	b.head = NULL;
	b.name = "b";
	b.size = 0;
	if (argc <= 1)
	{
		return (0);
	}
	if (parse_input(&a, argc - 1, argv + 1) != 0)
	{
		ft_dc_stack_clear(&a, &my_free);
		ft_printf_fd(2, "Error\n");
		return (1);
	}
	if (check_sorted(a) == 0)
	{
		return (0);
	}
	ft_printf_fd(1, "stack avant sort : \n");
	print_stacks(a, b);
	sort_stack(&a, &b);
	ft_printf_fd(1, "stack apres sort : \n");
	print_stacks(a, b);
	ft_printf_fd(1, "nb_elems = %i\n", a.size);
	ft_dc_stack_clear(&a, &my_free);
	ft_dc_stack_clear(&b, &my_free);
}

static int	check_sorted(t_stack a)
{
	int	i;

	if (a.size == 1)
		return (0);
	i = 0;
	while (i < a.size - 1)
	{
		if (((t_pair *)a.head->content)->value
			> ((t_pair *)a.head->next->content)->value)
			return (1);
		a.head = a.head->next;
		i++;
	}
	return (0);
}

static void	*my_free(void *content)
{
	if (content != NULL)
		free(content);
	return (NULL);
}
