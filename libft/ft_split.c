/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:27:41 by ajothos           #+#    #+#             */
/*   Updated: 2021/12/18 16:51:42 by ajothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	ft_count_words(const char *str, char c)
{
	size_t	count;
	int		start;

	start = 1;
	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			if (start)
				count++;
			start = 0;
		}
		else
			start = 1;
		str++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	int			str_i;
	size_t		cycle_i;
	int			new_one;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!result)
		return (NULL);
	str_i = 0;
	cycle_i = 0;
	while (cycle_i < ft_count_words(s, c))
	{
		while (s[str_i] && s[str_i] == c)
			str_i++;
		new_one = str_i;
		while (s[str_i] && s[str_i] != c)
			str_i++;
		result[cycle_i] = ft_substr(s, new_one, str_i - new_one);
		str_i++;
		cycle_i++;
	}
	result[cycle_i] = NULL;
	return (result);
}
