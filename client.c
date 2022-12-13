/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:53:20 by met-tahe          #+#    #+#             */
/*   Updated: 2022/12/07 12:53:24 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	envoi_signal(int pid, char *str)
{
	int	i;

	while (*str)
	{
		i = 8;
		while (i--)
		{
			if (*str >> i & 1)
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(0);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(0);
			}
			usleep(120);
		}
		str++;
	}
}

int	main(int c, char *v[])
{
	int		pid;
	char	*str;

	if (c != 3 || ft_strlen(v[2]) == 0 || v[1][0] == '-')
	{
		ft_putstr("PLEASE ENTER THE PID & STRING !!");
		exit(0);
	}
	pid = ft_atoi(v[1]);
	str = v[2];
	envoi_signal(pid, str);
}
