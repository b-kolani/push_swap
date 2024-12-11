/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:03:27 by bkolani           #+#    #+#             */
/*   Updated: 2024/12/10 10:07:42 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_not_nbr(char *arg)
{
	if (*arg == '-' || *arg == '+')
		arg++;
	if (*arg > '9' || *arg < '0')
		return (1);
	while (*arg && *arg != ' ')
	{
		if (*arg > '9' || *arg < '0')
			return (1);
		arg++;
	}
	return (0);
}

void	ft_free(char **splited_str)
{
	int	i;

	i = 0;
	while (splited_str[i])
	{
		free(splited_str[i]);
		splited_str[i] = NULL;
		i++;
	}
}

int	check_one_arg(char *arg)
{
	int		i;
	char	**splited_str;

	while (*arg == ' ')
		arg++;
	if (!*arg)
		return (0);
	splited_str = ft_split(arg, ' ');
	i = 0;
	while (splited_str[i])
	{
		if (is_not_nbr(splited_str[i]))
		{
			ft_free(splited_str);
			free(splited_str);
			return (0);
		}
		i++;
	}
	ft_free(splited_str);
	free(splited_str);
	return (1);
}

int	check_args(char **argv, int argc)
{
	int	i;

	if (argc == 2)
		return (check_one_arg(argv[1]));
	i = 1;
	while (i < argc)
	{
		if (!check_one_arg(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_overflow(char **argv, int argc)
{
	char	**splited_str;
	int		i;

	while (argc > 1)
	{
		argc--;
		i = -1;
		splited_str = ft_split(argv[argc], ' ');
		while (splited_str[++i])
		{
			if (ft_atoi(splited_str[i]) > INT_MAX
				|| ft_atoi(splited_str[i]) < INT_MIN)
			{
				ft_free(splited_str);
				free(splited_str);
				return (0);
			}
		}
		ft_free(splited_str);
		free(splited_str);
	}
	return (1);
}
