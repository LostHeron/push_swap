/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:22:16 by jweber            #+#    #+#             */
/*   Updated: 2025/02/11 11:19:56 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "parsing.h"
#include "standard.h"
#define WHITE_SPACES " \t\n\v\f\r"

static int	add_values_stack(t_stack *pa, char **values);
static int	check_duplicate(t_stack *pa);
static void	*free_all(char **values);

int	parse_input(t_stack *pa, int nb_args, char **args, char **p_option)
{
	int		arg_i;
	int		err_code;
	char	**values;

	arg_i = 0;
	while (arg_i < nb_args)
	{
		values = ft_split(args[arg_i], WHITE_SPACES);
		if (values == NULL || values[0] == NULL)
			return (1);
		err_code = add_values_stack(pa, values);
		if (err_code < 0)
		{
			free_all(values);
			return (1);
		}
		else if (err_code == 2)
		{
			arg_i++;
			*p_option = args[arg_i];
		}
		free_all(values);
		arg_i++;
	}
	if (check_duplicate(pa) != 0)
	{
		return (1);
	}
	return (0);
}

static int	add_values_stack(t_stack *pa, char **values)
{
	int		val_i;
	int		*tmp;
	int		err_code;
	t_node	*node_tmp;

	val_i = 0;
	while (values[val_i] != NULL)
	{
		tmp = malloc(1 * sizeof(int));
		if (tmp == NULL)
			return (-1);
		err_code = ft_atoi_err(tmp, values[val_i]);
		if (err_code == 2)
			return (2);
		else if (err_code == 0)
		{
			node_tmp = ft_dc_node_new(tmp);
			if (node_tmp == NULL)
			{
				free(tmp);
				return (-1);
			}
			ft_dc_stack_add_back(pa, node_tmp);
		}
		else
		{
			free(tmp);
			return (-2);
		}
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
				if (*((int *)node_i->content) == *((int *)node_j->content))
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
