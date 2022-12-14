/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:35:39 by amanasse          #+#    #+#             */
/*   Updated: 2022/09/20 16:19:24 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

t_server	g_mini;

char	bin_to_char(void)
{
	g_mini.i = 0;
	g_mini.nb = 0;
	if (g_mini.buff[g_mini.i] == '1')
		g_mini.nb += 64;
	g_mini.i++;
	if (g_mini.buff[g_mini.i] == '1')
		g_mini.nb += 32;
	g_mini.i++;
	if (g_mini.buff[g_mini.i] == '1')
		g_mini.nb += 16;
	g_mini.i++;
	if (g_mini.buff[g_mini.i] == '1')
		g_mini.nb += 8;
	g_mini.i++;
	if (g_mini.buff[g_mini.i] == '1')
		g_mini.nb += 4;
	g_mini.i++;
	if (g_mini.buff[g_mini.i] == '1')
		g_mini.nb += 2;
	g_mini.i++;
	if (g_mini.buff[g_mini.i] == '1')
		g_mini.nb += 1;
	return (g_mini.nb);
}

int	init_mini(void)
{
	g_mini.x = 0;
	ft_memset(g_mini.buff, 0, 7);
	ft_memset(g_mini.str1, 0, 2);
	g_mini.str_def = malloc(1);
	if (g_mini.str_def == NULL)
		return (0);
	g_mini.str_def[0] = '\0';
	return (1);
}

void	make_my_buff(char c)
{
	g_mini.buff[g_mini.x] = c;
	g_mini.x += 1;
	if (g_mini.x == BUFFER_MAX)
	{
		if (bin_to_char() == 0)
		{
			ft_putstr_fd(g_mini.str_def, 1);
			write(1, "\n", 1);
			free(g_mini.str_def);
			if (init_mini() == 0)
				exit(0);
		}
		else
			put_my_buff(&g_mini);
	}
}

void	listen(int sig, siginfo_t *t_info, void *content)
{
	(void) t_info;
	(void) content;
	if (sig == SIGUSR1)
		make_my_buff('1');
	else if (sig == SIGUSR2)
		make_my_buff('0');
	else if (sig == SIGINT)
	{
		free(g_mini.str_def);
		g_mini.tmp = NULL;
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void) argv;
	if (argc == 1)
	{
		sigemptyset(&sa.sa_mask);
		sigaddset(&sa.sa_mask, SIGINT);
		sigaddset(&sa.sa_mask, SIGUSR1);
		sigaddset(&sa.sa_mask, SIGUSR2);
		if (init_mini() == 0)
			return (0);
		sa.sa_sigaction = &listen;
		sa.sa_flags = SA_RESTART;
		ft_putnbr_fd(getpid(), 1);
		write (1, "\n", 1);
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		sigaction(SIGINT, &sa, NULL);
		while (1)
		{
		}
	}
	else
		write (2, "Error\nNeed Only 1 Argument", 25);
	return (0);
}
