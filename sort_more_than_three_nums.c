/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_than_three_nums.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:52:17 by bkolani           #+#    #+#             */
/*   Updated: 2024/12/10 12:02:45 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *s_a, t_stack *s_b)
{
	int	average;
	int	size;

	average = list_average(s_a);
	size = list_size(s_a);
	while (size > 0 && list_size(s_a) > 3)
	{
		if (s_a->value <= average)
		{
			px(&s_a, &s_b, "pb");
			write(1, "pb\n", 3);
		}
		else
		{
			rx(&s_a, &s_b, "ra");
			write(1, "ra\n", 3);
		}
		size--;
	}
	while (list_size(s_a) > 3)
	{
		px(&s_a, &s_b, "pb");
		write(1, "pb\n", 3);
	}
	sort_and_transfer_to_a(&s_a, &s_b);
}
