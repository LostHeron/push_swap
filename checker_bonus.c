/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:40:54 by jweber            #+#    #+#             */
/*   Updated: 2025/02/24 15:00:11 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_lists_double_circular.h"
#include "freeing.h"
#include "printing.h"
#include "parsing.h"
#include "push_swap.h"
#include "sorting.h"
#include "checker_bonus.h"
#include "instruction.h"
#include <stdlib.h>
#include <unistd.h>

static int	free_stacks(t_stack *ptr_a, t_stack *ptr_b, t_stack *ptr_inst);
static void	init_stacks(t_stack **stacks);
static int	check_push_swap(t_stack **stacks);
static int	display_result(t_stack **stacks);

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_stack	*stacks[2];
	int		ret;

	stacks[STACK_A] = &a;
	stacks[STACK_B] = &b;
	init_stacks(stacks);
	if (argc <= 1)
		return (0);
	ret = parse_input(&a, argc - 1, argv + 1);
	if (ret != 0)
	{
		print_error();
		free_stacks(&a, &b, NULL);
		return (ret);
	}
	return (check_push_swap(stacks));
}

static int	check_push_swap(t_stack **stacks)
{
	t_stack	inst_stack;
	int		err_code;
	int		ret;

	inst_stack = read_instruction(&err_code);
	if (err_code < 0)
	{
		print_error();
		free_stacks(stacks[STACK_A], stacks[STACK_B], &inst_stack);
		return (err_code);
	}
	if (exec_inst(stacks, inst_stack) != 0)
	{
		print_error();
		return (free_stacks(stacks[STACK_A], stacks[STACK_B], &inst_stack));
	}
	ret = display_result(stacks);
	free_stacks(stacks[STACK_A], stacks[STACK_B], &inst_stack);
	if (ret != 0)
	{
		print_error();
		return (ret);
	}
	else
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

static int	display_result(t_stack **stacks)
{
	if (stacks[STACK_B]->size == 0)
	{
		if (check_sorted(*stacks[STACK_A]) == 0)
		{
			if (ft_printf_fd(1, "OK\n") < 0)
				return (WRITE_ERROR);
		}
		else
			if (ft_printf_fd(1, "KO\n") < 0)
				return (WRITE_ERROR);
	}
	else
		if (ft_printf_fd(1, "KO\n") < 0)
			return (WRITE_ERROR);
	return (0);
}

static int	free_stacks(t_stack *ptr_a, t_stack *ptr_b, t_stack *ptr_inst)
{
	if (ptr_a != NULL)
		ft_dc_stack_clear(ptr_a, &stack_clear_free_func);
	if (ptr_b != NULL)
		ft_dc_stack_clear(ptr_b, &stack_clear_free_func);
	if (ptr_inst != NULL)
		ft_dc_stack_clear(ptr_inst, &stack_clear_free_func);
	return (1);
}
