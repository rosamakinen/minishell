/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:36:18 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/21 17:36:20 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(char c)
{
	int	answer;

	answer = 0;
	if (c >= '0' && c <= '9')
		answer = 1;
	else
		answer = 0;
	return (answer);
}
