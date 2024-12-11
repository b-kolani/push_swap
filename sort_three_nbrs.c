/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_nbrs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:31:15 by bkolani           #+#    #+#             */
/*   Updated: 2024/12/10 17:28:42 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elements(t_stack **s_a)
{
	t_stack	*s;

	s = *s_a;
	if (s->value > s->next->value && s->next->value < s->next->next->value)
	{
		if (s->value < s->next->next->value)
			apply_op(s_a, "sa");
		else
			apply_op(s_a, "ra");
	}
	else if (s->value > s->next->value && s->next->value > s->next->next->value)
	{
		apply_op(s_a, "sa");
		apply_op(s_a, "rra");
	}
}

void	sort_first_three_elements(t_stack **s_a)
{
	t_stack	*s;

	s = *s_a;
	if (list_size(s) == 2 && s->value > s->next->value)
	{
		apply_op(s_a, "sa");
		return ;
	}
	if (s->value < s->next->value && s->next->value > s->next->next->value)
	{
		if (s->value < s->next->next->value)
		{
			apply_op(s_a, "rra");
			apply_op(s_a, "sa");
		}
		else
			apply_op(s_a, "rra");
	}
	else
		sort_three_elements(s_a);
}

void	sort_remaining_elements(t_stack **s_a, int size)
{
	t_stack	*s;
	int		ind;

	s = *s_a;
	ind = -1;
	while (s->next)
	{
		ind++;
		if (s->value > s->next->value)
			break ;
		s = s->next;
	}
	if (ind >= 0 && ind < size / 2)
	{
		while (ind-- >= 0)
			apply_op(s_a, "ra");
	}
	else if (ind >= 0 && ind >= size / 2)
	{
		while (ind++ < size - 1)
			apply_op(s_a, "rra");
	}
}

void	sort_and_transfer_to_a(t_stack **s_a, t_stack **s_b)
{
	sort_first_three_elements(s_a);
	send_to_stack_a(s_a, s_b);
	if (!is_sorted(*s_a))
		sort_remaining_elements(s_a, list_size(*s_a));
	ft_lstclear(s_a);
}
