/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryouum <maryouum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:31:34 by mabaddi           #+#    #+#             */
/*   Updated: 2026/01/26 09:56:21 by maryouum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	handler(int sig)
{
	static unsigned char	c = 0;
	static int				i = 0;

	c <<= 1;
	if (sig == SIGUSR2)
		c |= 1;
	i++;
	if (i == 8)
	{
		if (c == 0)
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

void	print_pid(void)
{
	char	buf[20];
	int		pid;
	int		i;

	pid = getpid();
	i = 0;
	while (pid > 0)
	{
		buf[i++] = (pid % 10) + '0';
		pid /= 10;
	}
	write(1, "Pid is ", 12);
	while (--i >= 0)
		write(1, &buf[i], 1);
	write(1, "\n", 1);
}

int	main(void)
{
	print_pid();
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
