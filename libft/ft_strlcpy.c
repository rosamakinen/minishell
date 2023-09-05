/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:38:09 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/21 17:38:10 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!dstsize)
		return (src_len);
	if (dstsize)
	{
		if (src_len >= dstsize)
		{
			len = dstsize - 1;
		}
		else
		{
			len = src_len;
		}
		ft_memcpy((char *)dst, (char *)src, len);
		dst[len] = '\0';
	}
	return (src_len);
}
