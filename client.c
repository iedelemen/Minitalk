/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:44:56 by idelemen          #+#    #+#             */
/*   Updated: 2024/02/28 12:14:06 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write (1, &str[i++], 1);
}

int	ft_atoi(char *str)
{
	int	index;

	index = 0;
	while (*str)
		index = index * 10 + (*str++ - '0');
	return (index);
}

void	ft_transfer_center(char c, int pid)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (i < 8)
	{
		if (c << i & 128)
			error = kill(pid, SIGUSR1);
		else
			error = kill(pid, SIGUSR2);
		i++;
		usleep(150);
	}
	if (error == -1)
	{
		ft_putstr("Incorrect PID entered");
		exit(1);
	}
}

int	main(int arc, char **arv)
{
	int	pid;
	int	i;

	i = 0;
	if (arc == 3)
	{
		pid = ft_atoi(arv[1]);
		while (arv[2][i])
			ft_transfer_center(arv[2][i++], pid);
	}
	else
	{
		ft_putstr("Format error");
		exit (1);
	}
	return (0);
}
