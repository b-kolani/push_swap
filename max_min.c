/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:49:02 by bkolani           #+#    #+#             */
/*   Updated: 2024/12/10 12:42:26 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_max(t_stack *s)
{
	int	max;

	max = s->value;
	s = s->next;
	while (s)
	{
		if (s->value > max)
			max = s->value;
		s = s->next;
	}
	return (max);
}

int	list_min(t_stack *s)
{
	int	min;

	min = s->value;
	s = s->next;
	while (s)
	{
		if (s->value < min)
			min = s->value;
		s = s->next;
	}
	return (min);
}
