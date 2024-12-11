/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:56:38 by bkolani           #+#    #+#             */
/*   Updated: 2024/12/09 17:32:05 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **s)
{
	t_stack	*tmp;
	int		top;

	if (!s || !(*s)->next)
		return ;
	tmp = *s;
	top = tmp->value;
	while (tmp->next)
	{
		tmp->value = tmp->next->value;
		tmp = tmp->next;
	}
	tmp->value = top;
}

void	rx(t_stack **s_a, t_stack **s_b, char *op)
{
	if (op[0] == 'r' && op[1] == 'a')
		rotate(s_a);
	if (op[0] == 'r' && op[1] == 'b')
		rotate(s_b);
	if (op[0] == 'r' && op[1] == 'r')
	{
		rotate(s_a);
		rotate(s_b);
	}
}

static void	r_rotate(t_stack **s)
{
	t_stack	*tmp;
	int		value_1;
	int		value_2;

	if (!s || !(*s)->next)
		return ;
	tmp = (*s)->next;
	value_1 = (*s)->value;
	while (tmp)
	{
		value_2 = tmp->value;
		tmp->value = value_1;
		value_1 = value_2;
		tmp = tmp->next;
	}
	(*s)->value = value_1;
}

void	rrx(t_stack **s_a, t_stack **s_b, char *op)
{
	if (op[0] == 'r' && op[1] == 'r' && op[2] == 'a')
		r_rotate(s_a);
	if (op[0] == 'r' && op[1] == 'r' && op[2] == 'b')
		r_rotate(s_b);
	if (op[0] == 'r' && op[1] == 'r' && op[2] == 'r')
	{
		r_rotate(s_a);
		r_rotate(s_b);
	}
}
