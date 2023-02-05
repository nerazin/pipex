/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:47:32 by ajothos           #+#    #+#             */
/*   Updated: 2021/10/19 16:37:43 by ajothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, unsigned int len)
{
	char			*dest_pointer;
	const char		*src_pointer;

	dest_pointer = (char *) dst;
	src_pointer = (char *) src;
	if (dst || src)
	{
		if (dest_pointer < src_pointer)
			while (len--)
				*dest_pointer++ = *src_pointer++;
		else
			while (len--)
				*(dest_pointer + len) = *(src_pointer + len);
	}
	return (dst);
}
