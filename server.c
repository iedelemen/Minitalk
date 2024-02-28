/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:37:28 by idelemen          #+#    #+#             */
/*   Updated: 2024/02/28 11:35:55 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	write (1, &"0123456789"[n % 10], 1);
}

void	handler(int signal)
{
	static char	c;
	static int	i;

	if (signal == SIGUSR1)
		c = c << 1 | 1;
	else
		c = c << 1;
	i++;
	if (i == 8)
	{
		write (1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	write (1, "Server PID:", 11);
	ft_putnbr(getpid());
	write (1, "\n", 2);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
