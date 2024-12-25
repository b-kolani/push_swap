/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:35:21 by bkolani           #+#    #+#             */
/*   Updated: 2024/12/10 14:21:06 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*parse_one_arg(char *arg)
{
	int	len;
	t_stack	*s;

	s = NULL;
	len = ft_strlen(arg);
	while (len > 0)
	{
		len--;
		while (arg[len] == ' ')
			len--;
		if (len < 0)
			break ;
		while (arg[len] >= '0' && arg[len] <= '9')
			len--;
		if (arg[len] != '-' && arg[len] != '+')
			len++;
		if (arg[len])
			push(&s, ft_atoi(&arg[len]));
	}
	return (s);
}

static t_stack	*parse_many_args(char **argv, int argc)
{
	t_stack	*s;
	char	**splited_args;
	int		j;

	s = NULL;
	while (argc > 0)
	{
		j = 0;
		splited_args = ft_split(argv[argc], ' ');
		while (splited_args[j])
			j++;
		while (--j >= 0)
			push(&s, ft_atoi(splited_args[j]));
		ft_free(splited_args);
		free(splited_args);
		argc--;
	}
	return (s);
}

t_stack	*parse_args(char **argv, int argc)
{
	if (argc == 2)
		return (parse_one_arg(argv[1]));
	else
		return (parse_many_args(argv, argc - 1));
}

int	repeated_nbrs(t_stack *s)
{
	t_stack	*tmp;

	while (s)
	{
		if (!s->next)
			break ;
		tmp = s->next;
		while (tmp)
		{
			if (s->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		s = s->next;
	}
	return (0);
}
