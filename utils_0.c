/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:26:09 by bkolani           #+#    #+#             */
/*   Updated: 2024/12/11 18:13:59 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	int			res;
	long long	check_over;

	i = 0;
	sign = 1;
	res = 0;
	check_over = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		check_over = ((long long)res * 10 + (str[i] - '0')) * (long long)sign;
		if (check_over > 2147483647 || check_over < -2147483648)
			return (write(2, "Error\n", 6), exit(5), 5);
		res = (res * 10) + str[i++] - '0';
	}
	return (res * sign);
}

int	list_size(t_stack *s)
{
	int	size;

	size = 0;
	while (s)
	{
		size++;
		s = s->next;
	}
	return (size);
}

int	list_average(t_stack *s_a)
{
	int	total;
	int	count;

	total = 0;
	count = 0;
	while (s_a)
	{
		total += s_a->value;
		count++;
		s_a = s_a->next;
	}
	if (!count)
		return (0);
	return (total / count);
}
