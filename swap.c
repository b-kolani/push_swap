/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:18:43 by bkolani           #+#    #+#             */
/*   Updated: 2024/12/09 22:49:54 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **s)
{
	int	tmp;

	if (!s || !(*s)->next)
		return ;
	tmp = (*s)->value;
	(*s)->value = (*s)->next->value;
	(*s)->next->value = tmp;
}

void	sx(t_stack **s_a, t_stack **s_b, char *op)
{
	if (op[0] == 's' && op[1] == 'a')
		swap(s_a);
	if (op[0] == 's' && op[1] == 'b')
		swap(s_b);
	if (op[0] == 's' && op[1] == 's' && list_size(*s_a) > 1
		&& list_size(*s_b) > 1)
	{
		swap(s_a);
		swap(s_b);
	}
}
