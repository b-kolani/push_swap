/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:31:58 by bkolani           #+#    #+#             */
/*   Updated: 2024/12/08 18:27:15 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strncpy(char *s1, char const *s2, int n)
{
	int	i;

	i = -1;
	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

int	ft_count_words(char const *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

char	**create_result(char const *str, char **result, char c, int i)
{
	int		j;
	int		k;

	k = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		j = i;
		while (str[i] && str[i] != c)
			i++;
		if (i > j)
		{
			result[k] = (char *)malloc((i - j) + 1 * sizeof(char));
			if (!result[k])
			{
				while (k > 0)
					free(result[--k]);
				return (NULL);
			}
			ft_strncpy(result[k++], &str[j], (i - j));
		}
	}
	result[k] = NULL;
	return (result);
}

char	**ft_split(char const *str, char c)
{
	int		words_counted;
	int		i;
	char	**result;

	i = 0;
	words_counted = ft_count_words(str, c);
	result = (char **)malloc((words_counted + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (!create_result(str, result, c, i))
	{
		free(result);
		return (NULL);
	}
	return (result);
}
