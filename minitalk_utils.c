/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:51:11 by met-tahe          #+#    #+#             */
/*   Updated: 2022/12/08 16:51:13 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + '0');
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * (-1));
	}
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	write(1, s, i);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	n;
	size_t	r;

	r = 0;
	i = 0;
	n = 0;
	if (str[i] == '\0')
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			n = 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i++] - '0';
		if (r > __LONG_MAX__ + (n == 1))
			return ((n == 1) - 1);
	}
	if (n)
		r = r * (-1);
	return (r);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}
