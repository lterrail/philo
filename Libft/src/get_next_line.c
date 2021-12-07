/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:07:23 by cnicolas          #+#    #+#             */
/*   Updated: 2021/11/25 15:46:24 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_line(char *save)
{
	int		i;
	char	*new_line;

	i = 0;
	if (save[0] == 0)
		return (NULL);
	while (save[i] != '\n' && save[i])
		i++;
	new_line = ft_substr(save, 0, i + 1);
	return (new_line);
}

char	*get_save(char *save)
{
	char	*new_save;
	int		save_size;
	int		i;

	i = 0;
	save_size = ft_strlen(save);
	new_save = NULL;
	while (save[i] != '\n' && save[i])
		i++;
	if (save[i] == '\n' && save[i + 1] != 0)
		new_save = ft_substr(save, i + 1, save_size - i);
	free(save);
	save = NULL;
	return (new_save);
}

char	*returned_and_assign(char **save)
{
	char	*line;

	line = get_line(*save);
	*save = get_save(*save);
	return (line);
}

static char	*ft_free_save(char *save)
{
	free(save);
	save = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		buffer[BUFFER_SIZE + 1];
	char		*temp;
	int			res;

	if ((fd < 0 || fd >= MAX_FD) || BUFFER_SIZE < 1)
		return (NULL);
	res = 1;
	if (!save)
	{
		save = ft_strdup("");
		if (!save)
			return (NULL);
	}
	while (ft_strchr(save, '\n') == 0 && res != 0)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		if (res < 0)
			return (ft_free_save(save));
		buffer[res] = 0;
		temp = ft_strjoin(save, buffer);
		free(save);
		save = temp;
	}
	return (returned_and_assign(&save));
}
