/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:08:06 by abouazi           #+#    #+#             */
/*   Updated: 2022/03/16 20:08:10 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	i;
	static char	c;
	static int	last_pid;
	int			bit;

	(void)ucontext;
	if (last_pid != 0 && last_pid != info->si_pid)
	{
		i = 0;
		c = 0;
		write(1, "\n", 1);
	}
	i++;
	bit = sig - 30;
	c = (c << 1) | bit;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	last_pid = info->si_pid;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handler;
	sa.sa_mask = 0;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "the pid :", 9);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		pause();
	}
}
