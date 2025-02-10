/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:35:37 by jweber            #+#    #+#             */
/*   Updated: 2025/02/10 18:09:01 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "instruction.h"
#include "io.h"
#include "printing.h"

void	merge_sort_rec(t_stack *a, t_stack *b, int *c_pos, int start, int end, int nb_elems);
void	merge_sort_sort(t_stack *a, t_stack *b, int *c_pos, int start, int middle, int nb_elems, int end);
void	pushing_back(t_stack *a, t_stack *b, int start, int end);
int get_val1(t_stack b, int c_pos);
int get_val2(t_stack b, int c_pos, int middle, int start);
void	pa_at_middle(t_stack *a, t_stack *b, int *c_pos, int middle, int start);
void	pa_at_start(t_stack *a, t_stack *b, int *c_pos);

void	merge_sort(t_stack *a, t_stack *b)
{
	int start;
	int	end;
	int	current_pos;
	int	nb_elems;

	start = 0;
	end = a->size;
	nb_elems = a->size;
	current_pos = 0;
	merge_sort_rec(a, b, &current_pos, start, end, nb_elems);
}

void	merge_sort_rec(t_stack *a, t_stack *b, int *c_pos, int start, int end, int nb_elems)
{
	int	middle;

	if (end - start <= 1)
		return ;
	middle = (start + end) / 2;
	merge_sort_rec(a, b, c_pos, start, middle, nb_elems);
	merge_sort_rec(a, b, c_pos, middle, end, nb_elems);

	merge_sort_sort(a, b, c_pos, start, middle, nb_elems, end);
}

void	merge_sort_sort(t_stack *a, t_stack *b, int *c_pos, int start, int middle, int nb_elems, int end)
{
	int	counter;
	int	counter_cpos;

	(void) middle;
	(void) counter_cpos;
	counter_cpos=0;
	while (*c_pos % (nb_elems) != start)
	{
		inst_r(a);
		(*c_pos)++;	
	}
	//print_stacks(*a, *b);
	counter = 0;
	while (start + counter < end)
	{
		inst_pb(a, b);
		counter++;
	}
	/*
	while (start + counter > start)
	{
		//inst_pa(a, b);
		//counter--;
		counter--;
	}
	*/
	//inst_rr(b);
	pushing_back(a, b, start, end);
}

void	pushing_back(t_stack *a, t_stack *b, int start, int end)
{
	int		i;
	int		c_pos;
	int		middle;
	int		val1;
	int		val2;
	int		nb_elems;

	c_pos = 0;
	i = 0;
	nb_elems = end - start;
	if ((end + start) % 2 == 1)
		middle = (start + end) / 2 + 1;
	else
		middle = (start + end) / 2;
	while (i < nb_elems)
	{
		c_pos = c_pos % b->size;
		if (b->size == 1)
		{
			inst_pa(a, b);
		}
		else if (end <= middle)
		{
			pa_at_start(a, b, &c_pos);
			middle--;
		}
		else if (middle <= start)
			pa_at_middle(a, b, &c_pos, middle, start);
		else 
		{
			val1 = get_val1(*b, c_pos);
			val2 = get_val2(*b, c_pos, middle, start);
			if (val1 > val2)
			{
				pa_at_start(a, b, &c_pos);
				middle--;
			}
			else
				pa_at_middle(a, b, &c_pos, middle, start);
		}
		end--;
		i++;
	}
}

int get_val1(t_stack b, int c_pos)
{
	while (c_pos % b.size != 0)
	{
		b.head = b.head->prev;
		c_pos--;
	}
	return (*((int *)b.head->content));
}

int get_val2(t_stack b, int c_pos, int middle, int start)
{
	while (c_pos % b.size != middle - start)
	{
		b.head = b.head->next;
		c_pos++;
	}
	return (*((int *)b.head->content));
}

void	pa_at_start(t_stack *a, t_stack *b, int *c_pos)
{
	while (*c_pos % b->size != 0)
	{
		inst_rr(b);
		(*c_pos)--;
	}
	inst_pa(a, b);
}

void	pa_at_middle(t_stack *a, t_stack *b, int *c_pos, int middle, int start)
{
	while (*c_pos % b->size != middle - start)
	{
		inst_r(b);
		(*c_pos)++;
	}
	inst_pa(a, b);
}
