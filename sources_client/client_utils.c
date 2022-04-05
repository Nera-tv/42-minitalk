/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:34:09 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/05 11:32:18 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 1);
	ft_putchar_fd('\n', 1);
	exit(1);
}

int	ft_str_isdigit(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (ft_isdigit(num[i]) != 1)
			return (1);
		i++;
	}
	return (0);
}
