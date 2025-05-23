/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:45:56 by jweber            #+#    #+#             */
/*   Updated: 2025/02/24 12:31:48 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_pair
{
	int	index;
	int	value;
}		t_pair;

# define WRITE_ERROR -1
# define INVALID_INST -2
# define MALLOC_FAIL -3
# define WRONG_INPUT -4
# define DUPLICATE_VALUE -5

#endif
