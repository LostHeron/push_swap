/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instruction_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:47:39 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 16:00:56 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "standard.h"
#include "io.h"
#include "checker_bonus.h"

#define MALLOC_FAIL	-3
#define INVALID_INST -2

static t_node	*create_node(char *line, int *p_err_code);
static void		free_line_p_inst_code(char *line, int *p_inst_code);

t_stack	read_instruction(int *p_err_code)
{
	char	*line;
	t_stack	inst;
	t_node	*node_tmp;

	inst.head = NULL;
	inst.size = 0;
	inst.name = "inst";
	line = get_next_line(0, p_err_code);
	if (*p_err_code < 0)
		return (inst);
	while (line != NULL)
	{
		node_tmp = create_node(line, p_err_code);
		if (node_tmp == NULL)
			return (inst);
		ft_dc_stack_add_back(&inst, node_tmp);
		free(line);
		line = get_next_line(0, p_err_code);
		if (p_err_code < 0)
			return (inst);
	}
	return (inst);
}

static t_node	*create_node(char *line, int *p_err_code)
{
	int		*p_inst_code;
	t_node	*node_tmp;

	p_inst_code = ft_malloc(1 * sizeof(int));
	if (p_inst_code == NULL)
	{
		free(line);
		*p_err_code = MALLOC_FAIL;
		return (NULL);
	}
	*p_inst_code = check_inst(line);
	if (*p_inst_code < 0)
	{
		free_line_p_inst_code(line, p_inst_code);
		*p_err_code = INVALID_INST;
		return (NULL);
	}
	node_tmp = ft_dc_node_new(p_inst_code);
	if (node_tmp == NULL)
	{
		free_line_p_inst_code(line, p_inst_code);
		*p_err_code = MALLOC_FAIL;
		return (NULL);
	}
	return (node_tmp);
}

static void	free_line_p_inst_code(char *line, int *p_inst_code)
{
	if (line != NULL)
		free(line);
	if (p_inst_code != NULL)
		free(p_inst_code);
	return ;
}
