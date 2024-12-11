/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheaper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:11:46 by bkolani           #+#    #+#             */
/*   Updated: 2024/12/09 18:59:53 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_ind(t_stack *s, int value)
{
	int	ind;

	ind = 0;
	while (s && s->value != value)
	{
		ind++;
		s = s->next;
	}
	return (ind);
}

int	get_target(t_stack *s_a, int value)
{
	int	tmp;
	int	target;

	tmp = INT_MAX;
	if (value > list_max(s_a))
		return (get_ind(s_a, list_min(s_a)));
	while (s_a)
	{
		if (s_a->value > value && s_a->value < tmp)
		{
			tmp = s_a->value;
			target = s_a->index;
		}
		s_a = s_a->next;
	}
	return (target);
}

void	set_target(t_stack **s_a, t_stack **s_b)
{
	t_stack	*tmp;

	tmp = *s_b;
	while (tmp)
	{
		tmp->target_index = get_target(*s_a, tmp->value);
		tmp = tmp->next;
	}
}

t_move_cost	min_cost(t_stack *s_b)
{
	t_move_cost	cheaper_inds;
	int			min;
	int			tmp;

	tmp = INT_MAX;
	while (s_b)
	{
		min = (s_b->move_cost_b > 0) * s_b->move_cost_b
			+ (s_b->move_cost_b < 0) * (-s_b->move_cost_b);
		min += (s_b->move_cost_a > 0) * s_b->move_cost_a
			+ (s_b->move_cost_a < 0) * (-s_b->move_cost_a);
		if (min < tmp)
		{
			cheaper_inds.move_cost_a = s_b->target_index;
			cheaper_inds.move_cost_b = s_b->index;
			tmp = min;
		}
		s_b = s_b->next;
	}
	return (cheaper_inds);
}

void	send_to_stack_a(t_stack **s_a, t_stack **s_b)
{
	t_move_cost	cheaper_inds;

	while (list_size(*s_b) > 0)
	{
		reset_ind(s_a);
		reset_ind(s_b);
		set_target(s_a, s_b);
		calculate_moves_cost(s_a, s_b);
		cheaper_inds = min_cost(*s_b);
		optimize_rotation_moves(s_a, s_b, &cheaper_inds);
		px(s_a, s_b, "pa");
		write(1, "pa\n", 3);
	}
}
