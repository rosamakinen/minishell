/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_null_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:36:05 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/21 17:36:06 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*free the str & null terminates the entire str and return it*/
char	*ft_free_null_str(char *str)
{
	if (str)
		free(str);
	str = NULL;
	return (str);
}
