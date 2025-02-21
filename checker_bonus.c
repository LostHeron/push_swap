/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:40:54 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 14:45:52 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "printing.h"
#include "lists_double_circular.h"
#include "parsing.h"
#include "string.h"
#include "sorting.h"
#include "checker_bonus.h"
#include "instruction.h"
#include <stdlib.h>
#include <unistd.h>

static void		*my_free(void *content);
static int		free_stacks(t_stack *ptr_a, t_stack *ptr_b, t_stack *ptr_inst);
static void		init_stacks(t_stack **stacks);
static int		check_push_swap(t_stack **stacks);

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_stack	*stacks[2];

	stacks[STACK_A] = &a;
	stacks[STACK_B] = &b;
	init_stacks(stacks);
	if (argc <= 1)
		return (0);
	if (parse_input(&a, argc - 1, argv + 1) != 0)
	{
		print_error();
		return (free_stacks(&a, &b, NULL));
	}
	return (check_push_swap(stacks));
}

static int	check_push_swap(t_stack **stacks)
{
	t_stack	inst_stack;
	int		err_code;

	inst_stack = read_instruction(&err_code);
	if (err_code < 0)
	{
		print_error();
		return (free_stacks(stacks[STACK_A], stacks[STACK_B], &inst_stack));
	}
	if (exec_inst(stacks, inst_stack) < 0)
	{
		print_error();
		return (free_stacks(stacks[STACK_A], stacks[STACK_B], &inst_stack));
	}
	if (stacks[STACK_B]->size == 0)
	{
		if (check_sorted(*stacks[STACK_A]) == 0)
			ft_printf_fd(1, "OK\n");
		else
			ft_printf_fd(1, "KO\n");
	}
	else
		ft_printf_fd(1, "KO\n");
	free_stacks(stacks[STACK_A], stacks[STACK_B], &inst_stack);
	return (0);
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

static int	free_stacks(t_stack *ptr_a, t_stack *ptr_b, t_stack *ptr_inst)
{
	if (ptr_a != NULL)
		ft_dc_stack_clear(ptr_a, &my_free);
	if (ptr_b != NULL)
		ft_dc_stack_clear(ptr_b, &my_free);
	if (ptr_inst != NULL)
		ft_dc_stack_clear(ptr_inst, &my_free);
	return (1);
}

static void	*my_free(void *content)
{
	if (content != NULL)
		free(content);
	return (NULL);
}
