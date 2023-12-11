/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:10:33 by egeraldo          #+#    #+#             */
/*   Updated: 2023/12/11 11:09:22 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	putchar_sig(int signo, siginfo_t *siginfo, void *context)
{
	static unsigned char	c;
	static unsigned int		bit_control;

	(void)context;
	bit_control++;
	if (signo == SIGUSR2)
		c |= 1;
	if (bit_control == 8)
	{
		write(1, &c, 1);
		bit_control = 0;
		c = 0;
	}
	c <<= 1;
	if (kill(siginfo->si_pid, SIGUSR1))
		exit(EXIT_FAILURE);
}

int	main(void)
{
	struct sigaction	server_signal;

	server_signal.sa_sigaction = putchar_sig;
	server_signal.sa_flags = SA_SIGINFO;
	ft_printf("Server PID: %i\n\n", getpid());
	sigaction(SIGUSR1, &server_signal, NULL);
	sigaction(SIGUSR2, &server_signal, NULL);
	while (TRUE)
		pause();
}
