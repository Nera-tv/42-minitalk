/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:11:34 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/05 17:02:06 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_recusive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0 && power == 0)
		return (1);
	else
		return (nb * ft_recusive_power(nb, power - 1));
}

void	*ft_calloc_exit(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		exit(1);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

void	send_rep(siginfo_t *info, char c)
{
	static pid_t	client_pid = 0;

	if (!client_pid)
		client_pid = info->si_pid;
	if (!c)
	{
		kill(client_pid, SIGUSR2);
		client_pid = 0;
		return ;
	}
	else
		kill(client_pid, SIGUSR1);
}
