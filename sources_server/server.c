/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:51:20 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/05 14:06:22 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	print_pid(void)
{
	char	*pid_s;

	pid_s = ft_itoa(getpid());
	ft_putstr_fd("PID : ", 1);
	ft_putstr_fd(pid_s, 1);
	ft_putstr_fd("\n", 1);
	free(pid_s);
}

static void	ft_rec_len(int *current_bit, char **str, int *rec, int sig)
{
	static int	len = 0;

	if (sig == SIGUSR2)
		len += ft_recusive_power(2, *current_bit);
	if (*current_bit == 31)
	{
		*rec = 1;
		*str = ft_calloc_exit(sizeof(char), len + 1);
		*current_bit = 0;
		len = 0;
		return ;
	}
	(*current_bit)++;
}

static void	ft_reboot(int *l_rec, char **str, int *i)
{
	*l_rec = 0;
	if (str)
	{
		ft_putstr_fd(*str, 1);
		ft_putchar_fd('\n', 1);
		free(*str);
		*str = 0;
	}
	*i = 0;
}

static void	ft_signal(int sig, siginfo_t *info, void *context)
{
	static int				c = 0;
	static int				current_bit = 0;
	static int				l_rec = 0;
	static int				i = 0;
	static char				*str;

	(void)context;
	if (!l_rec)
		ft_rec_len(&current_bit, &str, &l_rec, sig);
	else
	{
		if (sig == SIGUSR2)
			c += ft_recusive_power(2, current_bit);
		if (current_bit == 7)
		{
			send_rep(info, c);
			str[i++] = c;
			current_bit = 0;
			if (c == 0)
				return (ft_reboot(&l_rec, &str, &i));
			c = 0;
			return ;
		}
		current_bit++;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	if (argc != 1)
		ft_error("Error : no parameters needed");
	print_pid();
	sa.sa_sigaction = ft_signal;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error("SIGUSR1 ERROR");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_error("SIGUSR2 ERROR");
	while (1)
		pause();
	(void)argv;
	return (0);
}
