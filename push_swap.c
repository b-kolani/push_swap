/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:42:37 by bkolani           #+#    #+#             */
/*   Updated: 2024/12/11 15:34:46 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *s_a, t_stack *s_b)
{
	if (list_size(s_a) <= 3)
	{
		sort_first_three_elements(&s_a);
		ft_lstclear(&s_a);
	}
	else
		sort_stack(s_a, s_b);
}

int	main(int argc, char **argv)
{
	t_stack	*s_a;
	t_stack	*s_b;

	s_b = NULL;
	if (argc < 2)
		return (0);
	if (!check_args(argv, argc) || !check_overflow(argv, argc))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	s_a = parse_args(argv, argc);
	if (repeated_nbrs(s_a))
	{
		write(2, "Error\n", 6);
		ft_lstclear(&s_a);
		return (1);
	}
	if (is_sorted(s_a) || list_size(s_a) <= 1)
	{
		ft_lstclear(&s_a);
		return (0);
	}
	push_swap(s_a, s_b);
}
