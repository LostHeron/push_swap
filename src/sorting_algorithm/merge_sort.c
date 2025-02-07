/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:35:37 by jweber            #+#    #+#             */
/*   Updated: 2025/02/07 20:22:29 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "instruction.h"
#include "io.h"

void	merge_sort_rec(t_stack *a, t_stack *b, int *c_pos, int start, int end, int nb_elems);
void	merge_sort_sort(t_stack *a, t_stack *b, int *c_pos, int start, int middle, int nb_elems, int end);
void	pushing_back(t_stack *a, t_stack *b, int start, int end);
int get_val1(t_stack b, int c_pos);
int get_val2(t_stack b, int c_pos, int middle, int start);
void	pa_at_middle(t_stack *b, int *c_pos, int start, int middle);
void	pa_at_start(t_stack *b, int *c_pos);

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
	// l'idee, il faut push dans b de start à middle,
	// donc faut que c_pos soit à start, si c_pos n'est pas à start,
	// r(a) et c_pos++, until c_pos == start
	// puis b(b) et counter ++ et ça jusque ce que start + counter == end
	// puis dans pb, mettre l'algo pour modif l'ordre dans lequel on push
	//
	// Mais en premier go faire les 3 operation et juste pa back
	ft_printf_fd(1, "on rentre ici avec : \n");
	ft_printf_fd(1, "start = %i\n", start);
	ft_printf_fd(1, "end = %i\n", end);
	ft_printf_fd(1, "middle = %i\n", middle);
	counter_cpos=0;
	while (*c_pos % (nb_elems) != start)
	{
		ft_printf_fd(1, "*c_pos = %i\n", *c_pos);
		inst_r(a);
		(*c_pos)++;	
	}
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
	inst_rr(b);
	pushing_back(a, b, start, end);
	*/
}

void	pushing_back(t_stack *a, t_stack *b, int start, int end)
{
	int		i;
	int		c_pos;
	int		middle;
	int		val1;
	int		val2;
	int		nb_elems;
	int		nb_pushed;
	int		nb_pushed_left;

	c_pos = 0;
	i = 0;
	nb_elems = end - start;
	middle = (start + end) / 2;
	nb_pushed_left = 0;
	while (i < nb_elems)
	{
		nb_pushed = nb_elems - b->size;
		end = end - nb_pushed;
		middle = middle - nb_pushed_left;
		val1 = get_val1(*b, c_pos);
		val2 = get_val2(*b, c_pos, middle, start);
		if (end < middle )
		{
			// go to c_pos = 0 et pa(a, b);
			pa_at_start(a, b, &c_pos);
			nb_pushed++;
		}
		else if (middle <= start)
		{
			// go to c_pos = start - middle et pb;
			pa_at_middle(a, b, &c_pos, start, middle);
			nb_pushed_left++;
			nb_pushed++;
		}
	}
	/*
	if (val1 > val2)
	{
		inst_pa(a, b);
	}
	else
	{
		//bouger en rr(a);
		//puis pa();
	}
	*/
}

int get_val1(t_stack b, int c_pos)
{
	while (c_pos != 0)
	{
		b.head = b.head->next;
		c_pos--;
	}
	return (*((int *)b.head->content));
}

int get_val2(t_stack b, int c_pos, int middle, int start)
{
	while (c_pos % b.size != middle - start)
	{
		b.head = b.head->next;
		c_pos--;
	}
	return (*((int *)b.head->content));
}

void	pa_at_start(t_stack *b, int *c_pos)
{
	while (*c_pos != 0)
	{
		inst_r(b);
		(*c_pos)--;
	}
}

void	pa_at_middle(t_stack *b, int *c_pos, int start, int middle)
{
	while (*c_pos % b->size != middle - start)
	{
		inst_rr(b);
		(*c_pos)++;
	}
}
