/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:22:23 by ajothos           #+#    #+#             */
/*   Updated: 2021/12/18 16:51:44 by ajothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	len_of_both;
	char	*final_string;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	len_of_both = s1_len + s2_len + 1;
	final_string = malloc(sizeof(char) * len_of_both);
	if (final_string == NULL)
		return (NULL);
	ft_memmove(final_string, s1, s1_len);
	ft_memmove(final_string + s1_len, s2, s2_len);
	final_string[len_of_both - 1] = '\0';
	return (final_string);
}
