/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:48:24 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/05 14:04:29 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	ft_send_msg(unsigned char c, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		usleep(100);
	}
}

static void	ft_send_len(int len, int pid)
{
	int	i;

	i = -1;
	while (++i < 32)
	{
		if (len & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		len = len >> 1;
		usleep(100);
	}
}

static void	ft_get_rep(int sig)
{
	static int	rec = 0;

	if (sig == SIGUSR1)
		++rec;
	else
	{
		ft_putstr_fd("Received ", 1);
		ft_putnbr_fd(rec, 1);
		ft_putstr_fd(" messages \n", 1);
		exit(0);
	}
}

void	print_text(int msg_len, char *msg)
{
	ft_putstr_fd("Send : ", 1);
	ft_putstr_fd(msg, 1);
	ft_putstr_fd("\nMessage length : ", 1);
	ft_putnbr_fd(msg_len, 1);
	ft_putchar_fd('\n', 1);
}

int	main(int argc, char *argv[])
{
	pid_t	pid_server;
	int		msg_len;
	int		i;

	pid_server = 0;
	if (argc != 3)
		ft_error("USAGE : ./client <PID> <string to send>");
	if (ft_str_isdigit(argv[1]) == 0)
		pid_server = ft_atoi(argv[1]);
	else
		ft_error("ERROR : First argument must be a number.");
	if (pid_server <= 1)
		ft_error("Error : Bad PID.");
	signal(SIGUSR1, ft_get_rep);
	signal(SIGUSR2, ft_get_rep);
	msg_len = ft_strlen(argv[2]);
	print_text(msg_len, argv[2]);
	ft_send_len(msg_len, pid_server);
	i = -1;
	while (argv[2][++i])
		ft_send_msg(argv[2][i], pid_server);
	ft_send_msg(argv[2][i], pid_server);
	while (1)
		pause();
	return (0);
}
