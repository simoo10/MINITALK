/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_server.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:23:51 by met-tahe          #+#    #+#             */
/*   Updated: 2022/12/07 13:23:54 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *s);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *c);

#endif
