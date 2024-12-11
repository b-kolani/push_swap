/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_perform_op.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:41:28 by bkolani           #+#    #+#             */
/*   Updated: 2024/12/10 12:07:30 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (*s1 && *s1 == *s2)
		return (ft_strcmp(s1 + 1, s2 + 1));
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	is_valid_op(char *op)
{
	return (!ft_strcmp(op, "pa\n") || !ft_strcmp(op, "pb\n")
		|| !ft_strcmp(op, "sa\n") || !ft_strcmp(op, "sb\n")
		|| !ft_strcmp(op, "ra\n") || !ft_strcmp(op, "rb\n")
		|| !ft_strcmp(op, "rr\n") || !ft_strcmp(op, "rra\n")
		|| !ft_strcmp(op, "rrb\n") || !ft_strcmp(op, "rrr\n")
		|| !ft_strcmp(op, "ss\n"));
}

void	apply_op(t_stack **s, char *op)
{
	if (!ft_strcmp(op, "ra"))
	{
		write(1, "ra\n", 3);
		rx(s, NULL, op);
	}
	else if (!ft_strcmp(op, "rra"))
	{
		write(1, "rra\n", 4);
		rrx(s, NULL, op);
	}
	else if (!ft_strcmp(op, "sa"))
	{
		write(1, "sa\n", 3);
		sx(s, NULL, op);
	}
}
