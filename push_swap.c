/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:49:25 by jweber            #+#    #+#             */
/*   Updated: 2025/02/24 15:01:13 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "freeing.h"
#include "instruction.h"
#include "parsing.h"
#include "printing.h"
#include "sorting.h"
#include <stdlib.h>

static void	init_stacks(t_stack **stacks);
static int	case_stack_sorted(t_stack **stacks);

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_stack	*stacks[2];
	int		ret;

	if (argc <= 1)
		return (0);
	stacks[STACK_A] = &a;
	stacks[STACK_B] = &b;
	init_stacks(stacks);
	ret = parse_input(&a, argc - 1, argv + 1);
	if (ret != 0)
	{
		ft_dc_stack_clear(&a, &stack_clear_free_func);
		print_error();
		return (ret);
	}
	if (check_sorted(a) == 0)
		return (case_stack_sorted(stacks));
	ret = cost_sort(stacks);
	if (ret != 0)
		print_error();
	ft_dc_stack_clear(&a, &stack_clear_free_func);
	ft_dc_stack_clear(&b, &stack_clear_free_func);
	return (ret);
}

static int	case_stack_sorted(t_stack **stacks)
{
	ft_dc_stack_clear(stacks[STACK_A], &stack_clear_free_func);
	ft_dc_stack_clear(stacks[STACK_B], &stack_clear_free_func);
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
