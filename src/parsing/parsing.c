/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:22:16 by jweber            #+#    #+#             */
/*   Updated: 2025/02/24 12:30:41 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists_double_circular.h"
#include "parsing.h"
#include "ft_standard.h"
#include "push_swap.h"
#define WHITE_SPACES " \t\n\v\f\r"

static int	add_values_stack(t_stack *pa, char **values);
static int	check_duplicate(t_stack *pa);
static void	*free_all(char **values);
static int	free_and_return(char **values, int ret);

int	parse_input(t_stack *pa, int nb_args, char **args)
{
	int		arg_i;
	char	**values;
	int		ret;

	arg_i = 0;
	while (arg_i < nb_args)
	{
		values = ft_split(args[arg_i], WHITE_SPACES);
		if (values == NULL)
			return (MALLOC_FAIL);
		if (values[0] == NULL)
			return (free_and_return(values, WRONG_INPUT));
		ret = add_values_stack(pa, values);
		if (ret != 0)
		{
			free_all(values);
			return (ret);
		}
		arg_i++;
		free_all(values);
	}
	if (check_duplicate(pa) != 0)
		return (DUPLICATE_VALUE);
	return (0);
}

static int	add_values_stack(t_stack *pa, char **values)
{
	int		val_i;
	t_pair	*tmp;
	t_node	*node_tmp;

	val_i = 0;
	while (values[val_i] != NULL)
	{
		tmp = ft_malloc(1 * sizeof(t_pair));
		if (tmp == NULL)
			return (MALLOC_FAIL);
		if (ft_atoi_err(&(tmp->value), values[val_i]) != 0)
		{
			free(tmp);
			return (WRONG_INPUT);
		}
		node_tmp = ft_dc_node_new(tmp);
		if (node_tmp == NULL)
		{
			free(tmp);
			return (MALLOC_FAIL);
		}
		ft_dc_stack_add_back(pa, node_tmp);
		val_i++;
	}
	return (0);
}

static int	check_duplicate(t_stack *pa)
{
	int		i;
	int		j;
	t_node	*node_i;
	t_node	*node_j;

	i = 0;
	node_i = pa->head;
	node_j = pa->head;
	while (i < pa->size)
	{
		j = 0;
		while (j < pa->size)
		{
			if (node_i != node_j)
				if (((t_pair *)node_i->content)->value
					== ((t_pair *)node_j->content)->value)
					return (1);
			node_j = node_j->next;
			j++;
		}
		node_i = node_i->next;
		i++;
	}
	return (0);
}

static void	*free_all(char **values)
{
	int	i;

	i = 0;
	while (values[i] != NULL)
	{
		free(values[i]);
		i++;
	}
	free(values);
	return (NULL);
}

static int	free_and_return(char **values, int ret)
{
	free_all(values);
	return (ret);
}
