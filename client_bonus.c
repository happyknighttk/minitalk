/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkayis <tkayis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:13:34 by tkayis            #+#    #+#             */
/*   Updated: 2023/06/07 17:22:41 by tkayis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putsuccess(void)
{
	ft_putstr("\n****--------------------------------------------****\n");
	ft_putstr("****---------  Successful transaction!  --------****\n");
	ft_putstr("****--------------------------------------------****\n\n");
}

void	signal_received(int signum)
{
	if (signum == SIGUSR1)
		ft_putsuccess();
}

int	send_bits(int pid, char chr)
{
	int	bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		if ((chr >> bit_index) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (-1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (-1);
		}
		bit_index--;
		usleep(142);
	}
	return (1);
}

void	deliver_message(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (send_bits(pid, str[i]) > 0)
			i++;
		else
		{
			ft_putstr("Failure! Message could not reach the server!\n");
			break ;
		}
	}
	send_bits(pid, '\n');
	send_bits(pid, '\0');
}

int	main(int argc, char *argv[])
{
	unsigned int	pid;

	if (argc != 3)
	{
		ft_putstr("Invalid argument!\nUsage: [program name(./client)]\
		[process id of the server]\
		[Message]\n");
		return (0);
	}
	signal(SIGUSR1, signal_received);
	pid = ft_atoi(argv[1]);
	deliver_message(pid, argv[2]);
	return (0);
}
