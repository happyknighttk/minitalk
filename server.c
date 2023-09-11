/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkayis <tkayis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:14:03 by tkayis            #+#    #+#             */
/*   Updated: 2023/08/17 16:24:11 by tkayis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	static int	i = 7;
	static int	chr = 0;
	int			bit;

	bit = 0;
	if (signum == SIGUSR1)
		bit = 1;
	else if (signum == SIGUSR2)
		bit = 0;
	chr = chr + (bit << i);
	if (i == 0)
	{
		write(1, &chr, 1);
		i = 7;
		chr = 0;
	}
	else
		i--;
}

int	main(void)
{
	write(1, "Server PID: ", 12);
	ft_itoa_and_print_pid(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
