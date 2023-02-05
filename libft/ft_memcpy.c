/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:47:30 by ajothos           #+#    #+#             */
/*   Updated: 2021/12/18 17:49:30 by ajothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest_pointer;
	char	*src_pointer;

	dest_pointer = (char *) dst;
	src_pointer = (char *) src;
	while (n)
	{
		*(dest_pointer++) = *(src_pointer++);
		n--;
	}
	return (dst);
}
