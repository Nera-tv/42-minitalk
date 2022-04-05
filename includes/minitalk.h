/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:20:02 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/05 17:01:45 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include "../libft/libft.h"

void		ft_error(char *msg);
int			ft_str_isdigit(char *num);
int			ft_recusive_power(int nb, int power);
void		*ft_calloc_exit(size_t nmemb, size_t size);
void		send_rep(siginfo_t *info, char c);

#endif