/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:07:41 by egeraldo          #+#    #+#             */
/*   Updated: 2023/12/11 12:44:56 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile int	g_sync_signal = FALSE;

void	sync_client_server(int signo)
{
	if (signo == SIGUSR1)
		g_sync_signal = TRUE;
}

void	send_bit(int server_pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_sync_signal = FALSE;
		if (((c >> bit) & 1) == 0)
		{
			if (kill(server_pid, SIGUSR1))
				exit(EXIT_FAILURE);
		}
		else if (((c >> bit) & 1) == 1)
		{
			if (kill(server_pid, SIGUSR2))
				exit(EXIT_FAILURE);
		}
		bit--;
		while (!g_sync_signal)
			;
	}
}

int	check_args(int argc, char *pid)
{
	int	i;

	if (argc != 3)
	{
		ft_printf("Error: number of arguments invalid \n");
		ft_printf("Enter type like this\n");
		ft_printf("./server SERVER_PID message\n");
		return (1);
	}
	i = -1;
	while (pid[++i])
	{
		if (!(pid[i] >= '0' && pid[i] <= '9'))
			return (ft_printf("Enter a valid SERVER PID number"));
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int					server_pid;
	char				*string;
	struct sigaction	client_signal;

	if (check_args(argc, argv[1]))
		return (1);
	server_pid = ft_atoi(argv[1]);
	string = argv[2];
	client_signal.sa_handler = sync_client_server;
	client_signal.sa_flags = 0;
	sigaction(SIGUSR1, &client_signal, NULL);
	while (*string != '\0')
		send_bit(server_pid, *string++);
}
