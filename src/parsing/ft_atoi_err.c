/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:24:44 by jweber            #+#    #+#             */
/*   Updated: 2025/02/11 11:19:21 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static long	calc_next_b(int *b, int sign, char c);

int	ft_atoi_err(int *b, char *nptr)
{
	int	i;
	int	sign;
	int	nb_digits;

	i = 0;
	sign = 1;
	*b = 0;
	if (nptr[i] == '\0' || (nptr[i] != '+' && nptr[i] != '-'
			&& !('0' <= nptr[i] && nptr[i] <= '9')))
		return (1);
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	nb_digits = 0;
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		if (calc_next_b(b, sign, nptr[i]) == 1)
			return (1);
		i++;
		nb_digits++;
	}
	if (nptr[i] != '\0' || nb_digits == 0)
		return (1);
	else
		return (0);
}

static long	calc_next_b(int *b, int sign, char c)
{
	int	b_prev;

	b_prev = *b;
	if (sign == -1)
	{
		*b = *b * 10 - (c - '0');
		if (*b > b_prev)
		{
			*b = INT_MAX;
			return (1);
		}
	}
	else
	{
		*b = *b * 10 + (c - '0');
		if (*b < b_prev)
		{
			*b = INT_MAX;
			return (1);
		}
	}
	return (0);
}
