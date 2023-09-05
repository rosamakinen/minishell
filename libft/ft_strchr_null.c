/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:37:40 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/21 17:37:41 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_null(const char *s, int c)
{
	if (c == '\0')
		return (NULL);
	while (*s)
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
