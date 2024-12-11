/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:42:33 by bkolani           #+#    #+#             */
/*   Updated: 2024/12/11 18:26:43 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*read_and_store(int fd, char *backup)
{
	ssize_t	bytes_read;
	char	buffer[101];

	bytes_read = 1;
	while (!ft_strchr(backup, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, 100);
		if (bytes_read == -1)
		{
			free(backup);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		backup = ft_strjoin(backup, buffer);
	}
	return (backup);
}

char	*reset_backup(char *backup)
{
	int		i;
	int		j;
	char	*new_backup;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	if (backup[i] == '\n')
		i += 1;
	new_backup = (char *)malloc((ft_strlen(backup) - i + 1) * sizeof(char));
	if (!new_backup)
		return (NULL);
	j = 0;
	while (backup[i])
		new_backup[j++] = backup[i++];
	new_backup[j] = '\0';
	free(backup);
	return (new_backup);
}

char	*extract_line(char *backup)
{
	char	*str_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!*backup)
		return (NULL);
	while (backup[i] && backup[i] != '\n')
		i++;
	if (backup[i] == '\n')
		i += 1;
	str_line = (char *)malloc((i + 1) * sizeof(char));
	if (!str_line)
		return (NULL);
	while (j < i && backup[j])
	{
		str_line[j] = backup[j];
		j++;
	}
	str_line[i] = '\0';
	return (str_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup;

	if (fd < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	backup = read_and_store(fd, backup);
	if (!backup)
		return (NULL);
	line = extract_line(backup);
	backup = reset_backup(backup);
	return (line);
}
