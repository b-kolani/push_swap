/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rotation_moves.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:06:40 by bkolani           #+#    #+#             */
/*   Updated: 2024/12/10 13:01:04 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_to_target(t_stack **s_a, int chp_ind_rot_in_a, int rot_dir)
{
	int	size;

	size = list_size(*s_a);
	if (rot_dir)
	{
		while (chp_ind_rot_in_a > 0)
		{
			rx(s_a, NULL, "ra");
			write(1, "ra\n", 3);
			chp_ind_rot_in_a--;
		}
	}
	else
	{
		while (chp_ind_rot_in_a < size)
		{
			rrx(s_a, NULL, "rra");
			write(1, "rra\n", 4);
			chp_ind_rot_in_a++;
		}
	}
}

void	rotate_b_to_target(t_stack **s_b, int chp_ind_rot_in_b, int rot_dir)
{
	int	size;

	size = list_size(*s_b);
	if (rot_dir)
	{
		while (chp_ind_rot_in_b > 0)
		{
			rx(NULL, s_b, "rb");
			write(1, "rb\n", 3);
			chp_ind_rot_in_b--;
		}
	}
	else
	{
		while (chp_ind_rot_in_b < size)
		{
			rrx(NULL, s_b, "rrb");
			write(1, "rrb\n", 4);
			chp_ind_rot_in_b++;
		}
	}
}

void	rotate_a_and_b_together(t_stack **s_a, t_stack **s_b,
	t_move_cost *cheaper_inds, int size)
{
	if (cheaper_inds->move_cost_a > size / 2)
	{
		while (size - cheaper_inds->move_cost_a > 0)
		{
			rrx(s_a, s_b, "rrr");
			write(1, "rrr\n", 4);
			cheaper_inds->move_cost_a++;
		}
	}
	else
	{
		while (cheaper_inds->move_cost_a > 0)
		{
			rx(s_a, s_b, "rr");
			write(1, "rr\n", 3);
			cheaper_inds->move_cost_a--;
		}
	}
}

void	optimize_rotation_moves(t_stack **s_1, t_stack **s_2,
	t_move_cost *cheaper_inds)
{
	if (!cheaper_inds->move_cost_a && !cheaper_inds->move_cost_b)
		return ;
	if ((cheaper_inds->move_cost_a == cheaper_inds->move_cost_b
			&& cheaper_inds->move_cost_a < list_size(*s_1) / 2
			&& cheaper_inds->move_cost_b < list_size(*s_1) / 2)
		|| (list_size(*s_1) - cheaper_inds->move_cost_a == list_size(*s_2)
			- cheaper_inds->move_cost_b
			&& cheaper_inds->move_cost_b
			&& cheaper_inds->move_cost_b > list_size(*s_1) / 2))
	{
		rotate_a_and_b_together(s_1, s_2, cheaper_inds, list_size(*s_1));
		return ;
	}
	if (cheaper_inds->move_cost_a && cheaper_inds->move_cost_a > 0
		&& cheaper_inds->move_cost_a <= list_size(*s_1) / 2)
		rotate_a_to_target(s_1, cheaper_inds->move_cost_a, 1);
	else if (cheaper_inds->move_cost_a && cheaper_inds->move_cost_a > 0
		&& cheaper_inds->move_cost_a > list_size(*s_1) / 2)
		rotate_a_to_target(s_1, cheaper_inds->move_cost_a, 0);
	if (cheaper_inds->move_cost_b && cheaper_inds->move_cost_b > 0
		&& cheaper_inds->move_cost_b <= list_size(*s_2) / 2)
		rotate_b_to_target(s_2, cheaper_inds->move_cost_b, 1);
	else if (cheaper_inds->move_cost_b && cheaper_inds->move_cost_b > 0
		&& cheaper_inds->move_cost_b > list_size(*s_2) / 2)
		rotate_b_to_target(s_2, cheaper_inds->move_cost_b, 0);
}
