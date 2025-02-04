/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:49:25 by jweber            #+#    #+#             */
/*   Updated: 2025/02/04 16:19:45 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"
#include "lists_double_circular.h"
#include "io.h"
#include "parsing.h"
#include <stdio.h>

static void	my_print(void *a);
static void	*my_free(void *content);

int	main(int argc, char **argv)
{
	/* stacks declaration */
	t_stack	a;
	t_stack	b;

	/* init of stack a and b */
	a.head = NULL;
	a.size = 0;
	b.head = NULL;
	b.size = 0;
	if (argc <= 1)
	{
		return (0);
	}
	if (parse_input(&a, argc - 1, argv + 1) != 0)
	{
		ft_printf_fd(1, "Error\n");
		return (1);
	}
	printf("test\n");
	ft_printf_fd(1, "affichage stack b :\n");
	ft_dc_stack_print(a, &my_print);
	ft_dc_stack_clear(&a, &my_free);
}

static void	*my_free(void *content)
{
	if (content != NULL)
		free(content);
	return (NULL);
}

static void	my_print(void *a)
{
	ft_printf_fd(1, "val : %i\n", *(int *)a);
}
