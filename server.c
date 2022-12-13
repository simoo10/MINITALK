/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:53:34 by met-tahe          #+#    #+#             */
/*   Updated: 2022/12/07 12:53:39 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	gestion_signal(int sign)
{
	static char	s;
	static int	i;

	s = s | (sign == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		ft_putchar(s);
		s = 0;
	}
	else
		s = s << 1;
}

int	main(void)
{
	ft_putstr("SERVEUR PID = ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	ft_putstr("---WAITING FOR TH MESSAGE COMING FROM CLIENT---\n");
	signal(SIGUSR2, gestion_signal);
	signal(SIGUSR1, gestion_signal);
	while (1)
		pause();
	return (0);
}
