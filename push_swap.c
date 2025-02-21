/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:49:25 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 11:49:54 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruction.h"
#include "lists_double_circular.h"
#include "io.h"
#include "printing.h"
#include "parsing.h"
#include "sorting.h"
#include <stdlib.h>

static void	*my_free(void *content);
static void	init_stacks(t_stack **stacks);

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_stack	*stacks[2];

	stacks[STACK_A] = &a;
	stacks[STACK_B] = &b;
	init_stacks(stacks);
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
		return (0);
	ft_printf_fd(1, "stack avant sort :\n");
	print_stacks(a, b);
	sort_stack(stacks);
	ft_printf_fd(1, "stack avant sort :\n");
	print_stacks(a, b);
	ft_dc_stack_clear(&a, &my_free);
	ft_dc_stack_clear(&b, &my_free);
}

static void	init_stacks(t_stack **stacks)
{
	stacks[STACK_A]->head = NULL;
	stacks[STACK_A]->name = "a";
	stacks[STACK_A]->size = 0;
	stacks[STACK_B]->head = NULL;
	stacks[STACK_B]->name = "b";
	stacks[STACK_B]->size = 0;
}

static void	*my_free(void *content)
{
	if (content != NULL)
		free(content);
	return (NULL);
}
