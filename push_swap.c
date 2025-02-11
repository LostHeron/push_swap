/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:49:25 by jweber            #+#    #+#             */
/*   Updated: 2025/02/06 18:13:35 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"
#include "lists_double_circular.h"
#include "io.h"
#include "parsing.h"
#include "printing.h"
#include "sorting.h"
#include <stdlib.h>

static void	*my_free(void *content);

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*option;
	char	*tmp_s;

	a.head = NULL;
	a.name = "a";
	a.size = 0;
	b.head = NULL;
	b.name = "b";
	b.size = 0;
	option = "selection_sort";
	if (argc <= 1)
	{
		return (0);
	}
	ft_printf_fd(1, "avant parse\n");
	if (parse_input(&a, argc - 1, argv + 1, &option) != 0)
	{
		ft_dc_stack_clear(&a, &my_free);
		ft_printf_fd(1, "Error\n");
		return (1);
	}
	ft_printf_fd(1, "apres parse\n");
	ft_printf_fd(1, "stack avant sort : \n");
	print_stacks(a, b);
	if (sort_stack(&a, &b, option) == 1)
	{
		tmp_s = "value1 value2 ... valueN";
		ft_printf_fd(1, "usage : ./push_swap [-t sort_algorithm] %s\n", tmp_s);
		return (1);
	}
	print_stacks(a, b);
	ft_dc_stack_clear(&a, &my_free);
	ft_dc_stack_clear(&b, &my_free);
	return (0);
}

static void	*my_free(void *content)
{
	if (content != NULL)
		free(content);
	return (NULL);
}
