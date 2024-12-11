/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cheaper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:51:42 by bkolani           #+#    #+#             */
/*   Updated: 2024/12/08 22:09:46 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ops_count(t_move_cost *index, int len_1, int len_2)
{
	int	count;

	count = 0;
	if (index->move_cost_a > len_1 / 2)
		count += len_1 - index->move_cost_a;
	else
		count += index->move_cost_a;
	if (index->move_cost_b > len_2 / 2)
		count += len_2 - index->move_cost_b;
	else
		count += index->move_cost_b;
	if (len_1 - index->move_cost_a == len_2 - index->move_cost_b)
		return (count / 2);
	return (count);
}

int	has_less_operations(t_move_cost *ind_1,
	t_move_cost *ind_2, int len_1, int len_2)
{
	if (ops_count(ind_1, len_1, len_2) < ops_count(ind_2, len_1, len_2))
		return (1);
	return (0);
}
