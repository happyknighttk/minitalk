/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkayis <tkayis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:13:41 by tkayis            #+#    #+#             */
/*   Updated: 2023/06/07 17:13:44 by tkayis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *ucontext)
{
	static int	i = 7;
	static int	chr = 0;
	int			bit;

	bit = 0;
	(void)ucontext;
	if (signum == SIGUSR1)
		bit = 1;
	else if (signum == SIGUSR2)
		bit = 0;
	chr = chr + (bit << i);
	if (i == 0 && chr == 0)
		kill(info->si_pid, SIGUSR1);
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
	struct sigaction	sa;

	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	write(1, "Server PID: ", 12);
	ft_itoa_and_print_pid(getpid());
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
