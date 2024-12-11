/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:35:38 by bkolani           #+#    #+#             */
/*   Updated: 2024/12/11 18:11:41 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_op(t_stack **s_a, t_stack **s_b, char *op)
{
	if (list_size(*s_a) < 1 && list_size(*s_b))
		return ;
	if (op[0] == 's')
		sx(s_a, s_b, op);
	if (op[0] == 'p')
		px(s_a, s_b, op);
	if (op[0] == 'r' && op[1] == 'r' && op[3])
		rrx(s_a, s_b, op);
	else
		rx(s_a, s_b, op);
}

static void	get_and_exec_ops(t_stack **s_a, t_stack **s_b)
{
	char	*line;

	if (!s_a)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	line = get_next_line(0);
	while (line)
	{
		if (!is_valid_op(line))
		{
			write(2, "Error\n", 6);
			ft_lstclear(s_a);
			ft_lstclear(s_b);
			exit(0);
		}
		exec_op(s_a, s_b, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_stack	*s_a;
	t_stack	*s_b;

	s_b = NULL;
	if (ac < 2)
		return (0);
	if (!check_args(av, ac) || !check_overflow(av, ac))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	s_a = parse_args(av, ac);
	if (repeated_nbrs(s_a))
	{
		ft_lstclear(&s_a);
		write(2, "Error\n", 6);
		return (1);
	}
	get_and_exec_ops(&s_a, &s_b);
	if (is_sorted(s_a) && s_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&s_a);
	return (0);
}
