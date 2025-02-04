/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:22:16 by jweber            #+#    #+#             */
/*   Updated: 2025/02/04 16:05:23 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "parsing.h"
#include "standard.h"
#include <stdio.h>
# define WHITE_SPACES " \t\n\v\f\r"

static void	*free_all(char **values);

int	parse_input(t_stack *pa, int nb_args, char **args)
{
	int	arg_i;
	int	val_i;
	int	*tmp;
	char **values;
	t_node	*node_tmp;

	arg_i = 0;
	while (arg_i < nb_args)
	{
		values = ft_split(args[arg_i], WHITE_SPACES);
		if (values == NULL)
			return (1);
		val_i = 0;
		while (values[val_i] != NULL)
		{
			tmp = malloc(1 * sizeof(int));
			if (tmp == NULL)
			{
				free_all(values);
				return (1);
			}
			if (ft_atoi_err(tmp, values[val_i]) == 1)
			{
				free_all(values);
				free(tmp);
				return (2);
			}
			node_tmp = ft_dc_node_new(tmp);
			if (node_tmp == NULL)
			{
				free_all(values);
				free(tmp);
				return (1);
			}
			ft_dc_stack_add(pa, node_tmp);
			val_i++;
		}
		arg_i++;
		free_all(values);
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
