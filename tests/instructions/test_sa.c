/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:10:13 by jweber            #+#    #+#             */
/*   Updated: 2025/03/10 15:19:39 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "instruction.h"
#include "unity.h"
#include "push_swap.h"
#include <standard.h>
#include <stdlib.h>

t_node	*malloc_node();
void	init_stack(t_stack *stacks[2]);
void	test_address(t_stack *stacks[2]);

void	test_inst_sa_two(void)
{
	t_stack *stacks[2];
	t_stack stack_a;
	t_stack stack_b;
	t_node *node1;
	t_node *node2;

	stacks[STACK_A] = &stack_a;
	stacks[STACK_B] = &stack_b;
	init_stack(stacks);
	node1 = malloc_node();
	if (node1 == NULL)
		return ;
	node2 = malloc_node();
	if (node2 == NULL)
	{
		free(node1);
		return ;
	}
	ft_dc_stack_add_back(&stack_a, node1);
	ft_dc_stack_add_back(&stack_a, node2);
	test_address(stacks);
}

void	test_address(t_stack *stacks[2])
{
	t_node *next_before1;
	t_node *next_after1;
	t_node *prev_before1;
	t_node *prev_after1;
	t_node *next_before2;
	t_node *next_after2;
	t_node *prev_before2;
	t_node *prev_after2;

	next_before1 = stacks[STACK_A]->head->next;
	prev_before1 = stacks[STACK_A]->head->prev;
	next_before2 = stacks[STACK_A]->head->next->next;
	prev_before2 = stacks[STACK_A]->head->next->prev;
	inst_sa(stacks, NO_DISPLAY);
	next_after1 = stacks[STACK_A]->head->next->next;;
	prev_after1 = stacks[STACK_A]->head->next->prev;
	next_after2 = stacks[STACK_A]->head->next;
	prev_after2 = stacks[STACK_A]->head->prev;
	TEST_ASSERT_EQUAL_UINT64(next_before1, next_after1);
	TEST_ASSERT_EQUAL_UINT64(next_before2, next_after2);
	TEST_ASSERT_EQUAL_UINT64(prev_before1, prev_after1);
	TEST_ASSERT_EQUAL_UINT64(prev_before2, prev_after2);
}

void	init_stack(t_stack *stacks[2])
{
	stacks[STACK_A]->head = NULL;
	stacks[STACK_A]->name = "a";
	stacks[STACK_A]->size = 0;
	stacks[STACK_B]->head = NULL;
	stacks[STACK_B]->name = "a";
	stacks[STACK_B]->size = 0;
}

t_node *malloc_node()
{
	t_node *node1;

	node1 = ft_malloc(sizeof(t_node));
	if (node1 == NULL)
		return (NULL);
	node1->content = ft_malloc(sizeof(t_pair));
	if (node1->content == NULL)
	{
		free(node1);
		return (NULL);
	}
	return (node1);
}
