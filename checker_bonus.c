/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:40:54 by jweber            #+#    #+#             */
/*   Updated: 2025/02/20 18:45:52 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "lists_double_circular.h"
#include "parsing.h"
#include "string.h"
#include "sorting.h"
#include "checker_bonus.h"
#include <stdlib.h>
#include <unistd.h>

static void		*my_free(void *content);
static t_stack	read_instruction(void);
static int		free_stacks(t_stack *ptr_a, t_stack *ptr_b, t_stack *ptr_inst);

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_stack	inst_stack;

	a.head = NULL;
	a.name = "a";
	a.size = 0;
	b.head = NULL;
	b.name = "b";
	b.size = 0;
	if (argc <= 1)
		return (0);
	if (parse_input(&a, argc - 1, argv + 1) != 0)
	{
		ft_printf_fd(2, "Error\n");
		return (free_stacks(&a, &b, &inst_stack));
	}
	inst_stack = read_instruction();
	if (inst_stack.size < 0)
	{
		ft_printf_fd(2, "Error\n");
		return (free_stacks(&a, &b, &inst_stack));
	}
	if (exec_inst(&a, &b, inst_stack) < 0)
	{
		ft_printf_fd(2, "Error\n");
		return (free_stacks(&a, &b, &inst_stack));
	}
	if (b.size == 0)
	{
		if (check_sorted(a) == 0)
			ft_printf_fd(1, "OK\n");
		else
			ft_printf_fd(1, "KO\n");
	}
	else
		ft_printf_fd(1, "KO\n");
	free_stacks(&a, &b, &inst_stack);
	return (0);
}

static t_stack	read_instruction(void)
{
	int		err_code;
	char	*line;
	t_node	*node_tmp;
	t_stack	inst;

	inst.head = NULL;
	inst.size = 0;
	inst.name = "inst";
	line = get_next_line(0, &err_code);
	if (err_code < 0)
	{
		inst.size = -1;
		return (inst);
	}
	while (line != NULL)
	{
		node_tmp = ft_dc_node_new(line);
		if (node_tmp == NULL)
		{
			free(line);
			inst.size = -1;
			return (inst);
		}
		ft_dc_stack_add_back(&inst, node_tmp);
		line = get_next_line(0, &err_code);
		if (err_code < 0)
		{
			inst.size = -1;
			return (inst);
		}
	}
	return (inst);
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
