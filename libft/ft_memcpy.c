/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:36:38 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/21 17:36:39 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*str;
	char	*dest;

	str = (char *)src;
	dest = (char *)dst;
	if (!str && !dest && n > 0)
		return (NULL);
	while (n-- > 0)
		*(dest++) = *(str++);
	dest = NULL;
	str = NULL;
	return (dst);
}
