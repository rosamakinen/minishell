/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:08:13 by rmakinen          #+#    #+#             */
/*   Updated: 2023/08/22 10:08:19 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../headers/lexer.h"

void	ft_putstr_fd(char *s, int fd, int print_shellname)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	if (print_shellname)
		ft_putstr_fd("TeenyTinyMiniShell\U0001F43E>: ", fd, 0);
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
