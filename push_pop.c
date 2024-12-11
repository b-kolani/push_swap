/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:41:10 by bkolani           #+#    #+#             */
/*   Updated: 2024/12/10 11:53:37 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **s, int value)
{
	t_stack	*tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	if (!tmp)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	tmp->value = value;
	tmp->next = *s;
	*s = tmp;
}

int	pop(t_stack **s)
{
	t_stack	*top;
	int		value;

	if (!s)
		return (-1);
	top = *s;
	value = top->value;
	*s = top->next;
	free(top);
	top = NULL;
	return (value);
}

static void	push_op(t_stack **s_1, t_stack **s_2)
{
	int		top_val;
	t_stack	*tmp;

	if (!*s_2)
		return ;
	top_val = pop(s_2);
	push(s_1, top_val);
	tmp = (*s_1)->next;
	while (tmp)
	{
		tmp->index = tmp->index + 1;
		tmp = tmp->next;
	}
}

void	px(t_stack **s_a, t_stack **s_b, char *op)
{
	if (op[0] == 'p' && op[1] == 'a')
		push_op(s_a, s_b);
	if (op[0] == 'p' && op[1] == 'b')
		push_op(s_b, s_a);
}
