/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_sort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:58:02 by jweber            #+#    #+#             */
/*   Updated: 2025/02/17 14:14:52 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COST_SORT_H
# define COST_SORT_H

typedef struct s_inst
{
	int	type;
	int	nb_ra;
	int	nb_rra;
	int	nb_rb;
	int	nb_rrb;
	int	nb_rr;
	int	nb_inst;
}				t_inst;

#endif 
