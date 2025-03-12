/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:52:35 by jweber            #+#    #+#             */
/*   Updated: 2025/02/05 15:17:00 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "ft_lists_double_circular.h"

int	ft_atoi_err(int *b, char *nptr);
int	parse_input(t_stack *pa, int nb_args, char **args);

#endif
