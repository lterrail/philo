/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:05:19 by cnicolas          #+#    #+#             */
/*   Updated: 2021/11/25 14:05:20 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_is_separator(char c, char sep)
{
	if (c == sep || c == '\0')
		return (1);
	return (0);
}

static int	ft_count_words(char *str, char sep)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_char_is_separator(str[i + 1], sep) == 1
			&& ft_char_is_separator(str[i], sep) == 0)
			words++;
		i++;
	}
	return (words);
}

static void	ft_write_word(char *dest, char *from, char sep)
{
	int	i;

	i = 0;
	while (ft_char_is_separator(from[i], sep) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static void	*ft_write_split(char **split, char *str, char sep, int i)
{
	int	j;
	int	word;

	word = 0;
	while (str[i] != '\0')
	{
		if (ft_char_is_separator(str[i], sep) == 1)
			i++;
		else
		{
			j = 0;
			while (ft_char_is_separator(str[i + j], sep) == 0)
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (split[word] == NULL)
			{
				while (word > 0)
					free(split[--word]);
				return (NULL);
			}
			ft_write_word(split[word++], (str + i), sep);
			i += j;
		}
	}
	return ((void *)1);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	char	*str;
	int		words;
	int		i;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	words = ft_count_words(str, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (res == NULL)
		return (NULL);
	res[words] = 0;
	i = 0;
	if (ft_write_split(res, str, c, i) == NULL)
	{
		free(res);
		return (NULL);
	}
	return (res);
}
