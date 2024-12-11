/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:34:01 by bkolani           #+#    #+#             */
/*   Updated: 2024/12/08 17:16:59 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_moves_cost(t_stack **s_a, t_stack **s_b)
{
	t_stack	*tmp;
	int		size_a;
	int		size_b;

	tmp = *s_b;
	size_a = list_size(*s_a);
	size_b = list_size(*s_b);
	while (tmp)
	{
		tmp->move_cost_b = tmp->index;
		if (tmp->index > size_b / 2)
			tmp->move_cost_b = tmp->index - size_b;
		tmp->move_cost_a = tmp->target_index;
		if (tmp->target_index > size_a / 2)
			tmp->move_cost_a = tmp->target_index - size_a;
		tmp = tmp->next;
	}
}

void	reset_ind(t_stack **s)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *s;
	while (tmp)
	{
		tmp->index = i++;
		tmp = tmp->next;
	}
}
