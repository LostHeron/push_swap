/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:44:46 by jweber            #+#    #+#             */
/*   Updated: 2025/02/17 14:31:07 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "sorting.h"
#include "cost_sort.h"
#include "lists_double_circular.h"
#include "math.h"
#include "push_swap.h"
#include "printing.h"
#include "io.h"

static int		get_ra(t_stack a, int val_b);
static void		chose_push(t_stack *a, t_stack *b);
static t_inst	get_nb_inst(t_stack a, t_stack b, int j);
static void		calculate_nb_inst(t_inst *ptr_inst);
static void		push_using(t_stack *a, t_stack *b, t_inst inst);
static void		rotate_to_min(t_stack *a);

int	cost_sort(t_stack *a, t_stack *b)
{
	//ft_printf_fd(1, "vraiment au debut de cost_sort\n");
	//ft_printf_fd(1, "stacks au debut : \n");
	//print_stacks(*a, *b);
	while (a->size > 3)
		inst_pb(a, b);
	//ft_printf_fd(1, "stacks apres push dans b: \n");
	//print_stacks(*a, *b);
	sort_three(a);
	//ft_printf_fd(1, "stacks apres trie de A : \n");
	//print_stacks(*a, *b);
	while (b->size > 0)
	{
		chose_push(a, b);
	}
	rotate_to_min(a);
	return (0);
}

static void	rotate_to_min(t_stack *a)
{
	int		i;
	int		nb_rotate;
	int		min;
	t_node	*tmp;

	tmp = a->head;
	i = 0;
	min = ((t_pair *)a->head->content)->value;
	nb_rotate = 0;
	while (i < a->size)
	{
		if (((t_pair *)tmp->content)->value < min)
		{
			min = ((t_pair *)tmp->content)->value;
			nb_rotate = i;
		}
		i++;
		tmp = tmp->next;
	}
	i = -1;
	if (nb_rotate > a->size / 2)
		while (++i < a->size - nb_rotate)
			inst_rr(a);
	else
		while (++i < nb_rotate)
			inst_r(a);
}

static void	chose_push(t_stack *a, t_stack *b)
{
	int		i;
	int		j;
	t_inst	inst_tmp;
	t_inst	inst;

	i = 0;
	while (i < b->size)
	{
		//ft_printf_fd(1, "############################################\n");
		//ft_printf_fd(1, "############## AVANT PUSH ##################\n");
		//print_stacks(*a, *b);
		//ft_printf_fd(1, "############################################\n");
		j = 0;
		inst = get_nb_inst(*a, *b, j);
		while (j < b->size)
		{
			inst_tmp = get_nb_inst(*a, *b, j);
			//ft_printf_fd(1, "inst_tmp.nb_inst = %i\n", inst_tmp.nb_inst);
			//ft_printf_fd(1, "inst.nb_inst = %i\n", inst.nb_inst);
			if (inst_tmp.nb_inst < inst.nb_inst)
			{
				inst = inst_tmp;
				//ft_printf_fd(1, "On a trouvé meilleur instruction possible \n");
				//ft_printf_fd(1, "j = %i\n", j);
				//ft_printf_fd(1, "inst.nb_inst = %i\n", inst.nb_inst);
			}
			j++;
		}
		//ft_printf_fd(1, "inst.type = %i\n", inst.type);
		//ft_printf_fd(1, "inst.nb_inst = %i\n", inst.nb_inst);
		push_using(a, b, inst);
		//ft_printf_fd(1, "############################################\n");
		//ft_printf_fd(1, "############## APRES PUSH ##################\n");
		//print_stacks(*a, *b);
		//ft_printf_fd(1, "############################################\n\n\n");
	}
}

static t_inst	get_nb_inst(t_stack a, t_stack b, int j)
{
	int		i;
	int		val_b;
	t_inst	inst;

	//ft_printf_fd(1, "------>dans get_nb_inst\n");
	i = 0;
	while (i < j)
	{
		b.head = b.head->next;
		i++;
	}
	inst.nb_rb = j % b.size;
	val_b = ((t_pair *)b.head->content)->value;
	inst.nb_ra = get_ra(a, val_b) % a.size;
	inst.nb_rra = (a.size - inst.nb_ra) % a.size;
	inst.nb_rrb = (b.size - inst.nb_rb) % b.size;
	calculate_nb_inst(&inst);
	//ft_printf_fd(1, "((t_pair *)b.head->content)->value = %i\n", ((t_pair *)b.head->content)->value);
	//ft_printf_fd(1, "inst.nb_rb = %i\n", inst.nb_rb);
	//ft_printf_fd(1, "inst.nb_rrb = %i\n", inst.nb_rrb);
	//ft_printf_fd(1, "inst.nb_ra = %i\n", inst.nb_ra);
	//ft_printf_fd(1, "inst.nb_rra = %i\n", inst.nb_rra);
	//ft_printf_fd(1, "inst.nb_inst = %i\n", inst.nb_inst);
	//ft_printf_fd(1, "inst.type = %i\n", inst.type);
	//ft_printf_fd(1, "sortie get_nb_inst ------>\n");
	return (inst);
}

static void	push_using(t_stack *a, t_stack *b, t_inst inst)
{
	int	i;
	int	nb_rr;
	int	nb_rrr;

	nb_rr = ft_abs(inst.nb_rb - inst.nb_ra);
	//ft_printf_fd(1, "nb_rr = %i\n", nb_rr);
	nb_rrr = ft_abs(inst.nb_rrb - inst.nb_rra);
	//ft_printf_fd(1, "nb_rrr = %i\n", nb_rrr);
	if (inst.type == 1)
	{
		//ft_printf_fd(1, "Cas inst.type == 1\n");
		i = -1;
		while (++i < nb_rr)
			inst_r_both(a, b);
		i = -1;
		while (++i < ft_abs(nb_rr - inst.nb_rb))
			inst_r(b);
		i = -1;
		while (++i < ft_abs(nb_rr - inst.nb_ra))
			inst_r(a);
	}
	else if (inst.type == 2)
	{
		//ft_printf_fd(1, "Cas inst.type == 2\n");
		//ft_printf_fd(1, "ft_abs(inst.nb_rrb - inst.nb_rra) = %i\n", ft_abs(inst.nb_rrb - inst.nb_rra));
		//ft_printf_fd(1, "inst.nb_rrb - inst.nb_rra = %i\n", inst.nb_rrb - inst.nb_rra);
		//ft_printf_fd(1, "inst.nb_rrb = %i\n", inst.nb_rrb);
		//ft_printf_fd(1, "inst.nb_rra = %i\n", inst.nb_rra);
		//ft_printf_fd(1, "inst.nb_rrr = %i\n", inst.nb_rr);
		//ft_printf_fd(1, "inst.nb_rrr = %i\n", inst.nb_rr);
		//ft_printf_fd(1, "inst.nb_rr - inst.nb_ra = %i\n", inst.nb_rr - inst.nb_rb);
		//ft_printf_fd(1, "inst.nb_rr - inst.nb_rb = %i\n", inst.nb_rr - inst.nb_rb);
		//ft_printf_fd(1, "inst.nb_rr - inst.nb_ra = %i\n", inst.nb_rr - inst.nb_rb);
		i = -1;
		while (++i < nb_rrr)
			inst_rr_both(a, b);
		i = -1;
		while (++i < ft_abs(nb_rrr - inst.nb_rrb))
			inst_rr(b);
		i = -1;
		while (++i < ft_abs(nb_rrr - inst.nb_rra))
			inst_rr(a);
	}
	else if (inst.type == 3)
	{
		//ft_printf_fd(1, "\t Cas inst.type == 3\n");
		//ft_printf_fd(1, "\t inst.nb_rb = %i\n", inst.nb_rb);
		//ft_printf_fd(1, "\t inst.nb_rrb = %i\n", inst.nb_rrb);
		//ft_printf_fd(1, "\t inst.nb_ra = %i\n", inst.nb_ra);
		//ft_printf_fd(1, "\t inst.nb_rra = %i\n", inst.nb_rra);
		//ft_printf_fd(1, "\t inst.nb_inst = %i\n", inst.nb_inst);
		i = -1;
		while (++i < inst.nb_rra)
			inst_rr(a);
		i = -1;
		while (++i < inst.nb_rb)
			inst_r(b);
	}
	else if (inst.type == 4)
	{
		//ft_printf_fd(1, "Cas inst.type == 4\n");
		i = -1;
		while (++i < inst.nb_ra)
			inst_r(a);
		i = -1;
		while (++i < inst.nb_rrb)
			inst_rr(b);
	}
	else if (inst.type == 5)
	{
		//ft_printf_fd(1, "Cas inst.type == 5\n");
		i = -1;
		while (++i < inst.nb_ra)
			inst_r(a);
		i = -1;
		while (++i < inst.nb_rb)
			inst_r(b);
	}
	else if (inst.type == 6)
	{
		//ft_printf_fd(1, "Cas inst.type == 6\n");
		i = -1;
		while (++i < inst.nb_rra)
			inst_rr(a);
		i = -1;
		while (++i < inst.nb_rrb)
			inst_rr(b);
	}
	inst_pa(a, b);
}

static void	calculate_nb_inst(t_inst *ptr_inst)
{
	int	res_tmp;
	int	nb_rr;
	int	nb_rrr;

	nb_rr = ft_abs(ptr_inst->nb_rb - ptr_inst->nb_ra);
	nb_rrr = ft_abs(ptr_inst->nb_rrb - ptr_inst->nb_rra);
	//ft_printf_fd(1, "nb_rr = %i\n", nb_rr);
	//ft_printf_fd(1, "nb_rrr = %i\n", nb_rrr);
	res_tmp = nb_rr + ft_abs(nb_rr - ptr_inst->nb_ra)
		+ ft_abs(nb_rr - ptr_inst->nb_rb);
	//ft_printf_fd(1, "res_tmp = %i\n", res_tmp);
	ptr_inst->nb_inst = res_tmp;
	ptr_inst->type = 1;
	res_tmp = nb_rrr + ft_abs(nb_rrr - ptr_inst->nb_rra)
		+ ft_abs(nb_rrr - ptr_inst->nb_rrb);
	if (res_tmp < ptr_inst->nb_inst)
	{
		ptr_inst->nb_inst = res_tmp;
		ptr_inst->type = 2;
	}
	res_tmp = ptr_inst->nb_rb + ptr_inst->nb_rra;
	if (res_tmp < ptr_inst->nb_inst)
	{
		ptr_inst->nb_inst = res_tmp;
		ptr_inst->type = 3;
	}
	res_tmp = ptr_inst->nb_rrb + ptr_inst->nb_ra;
	if (res_tmp < ptr_inst->nb_inst)
	{
		ptr_inst->nb_inst = res_tmp;
		ptr_inst->type = 4;
	}
	res_tmp = ptr_inst->nb_ra + ptr_inst->nb_rb;
	if (res_tmp < ptr_inst->nb_inst)
	{
		ptr_inst->nb_inst = res_tmp;
		ptr_inst->type = 5;
	}
	res_tmp = ptr_inst->nb_rra + ptr_inst->nb_rrb;
	if (res_tmp < ptr_inst->nb_inst)
	{
		ptr_inst->nb_inst = res_tmp;
		ptr_inst->type = 6;
	}
}

static int	get_ra(t_stack a, int val_b)
{
	int		i;
	int		count_ra;
	long	diff;
	long	diff_tmp;

	i = 0;
	diff = (long)((t_pair *)a.head->content)->value - val_b;
	count_ra = i;
	while (i < a.size)
	{
		//ft_printf_fd(1, "on compare : \n");
		//ft_printf_fd(1, "val_b = %i \n", val_b);
		//ft_printf_fd(1, "et :\n");
		//ft_printf_fd(1, "((t_pair *)a.head->content)->value = %i\n", ((t_pair *)a.head->content)->value);
		diff_tmp = (long)((t_pair *)a.head->content)->value - val_b;
		if (ft_labs(diff_tmp) < ft_labs(diff))
		{
			diff = diff_tmp;
			count_ra = i;
		}
		/*
		else if (ft_labs(diff_tmp) == ft_labs(diff))
		{
			if (diff_tmp >= 0)
			{
				diff = diff_tmp;
				count_ra = i;
			}
		}
		*/
		a.head = a.head->next;
		i++;
	}
	if (diff >= 0)
	{
		//ft_printf_fd(1, "on est dans get_ra \n");
		//ft_printf_fd(1, "pour le nb de B : %i \n", val_b);
		//ft_printf_fd(1, "ON return : (count_ra)\n");
		//ft_printf_fd(1, "count_ra = %i\n", count_ra);
		return (count_ra);
	}
	else
	{
		//ft_printf_fd(1, "on est dans get_ra \n");
		//ft_printf_fd(1, "pour le nb de B : %i \n", val_b);
		//ft_printf_fd(1, "ON return : (count_ra + 1)\n");
		//ft_printf_fd(1, "count_ra + 1 = %i\n", count_ra + 1);
		return (count_ra + 1);
	}
}
