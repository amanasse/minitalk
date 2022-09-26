/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:34:16 by amanasse          #+#    #+#             */
/*   Updated: 2022/09/26 11:20:41 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

t_client	g_c;

int	check_arg(char **argv)
{
	g_c.av = ft_atoi(argv[1]);
	if (g_c.av <= 0)
	{
		write (2, "Error\nWrong PID\n", 16);
		return (0);
	}
	if (kill(g_c.av, 0) != 0)
	{
		write (2, "Error\nWrong PID\n", 16);
		return (0);
	}
	g_c.str = argv[2];
	g_c.i = 0;
	g_c.chaine_octet = malloc(1);
	if (g_c.chaine_octet == NULL)
		return (0);
	g_c.chaine_octet[0] = '\0';
	return (1);
}

char	*binaire(char a)
{
	int		i;

	i = 6;
	while (i >= 0)
	{
		g_c.binaire[i] = a % 2 + '0';
		a = a / 2;
		i--;
	}
	g_c.binaire[7] = '\0';
	return (g_c.binaire);
}

int	make_chaine_octet(void)
{
	binaire(g_c.str[g_c.i]);
	g_c.p_str = g_c.chaine_octet;
	g_c.chaine_octet = ft_strjoin(g_c.chaine_octet, g_c.binaire);
	if (g_c.chaine_octet == NULL)
	{
		free(g_c.p_str);
		g_c.p_str = NULL;
		return (0);
	}
	free(g_c.p_str);
	g_c.p_str = NULL;
	return (1);
}

void	send_signal(void)
{
	g_c.i = 0;
	while (g_c.chaine_octet[g_c.i] != '\0')
	{
		if (g_c.chaine_octet[g_c.i] == '1' && g_c.av > 0)
			kill(g_c.av, SIGUSR1);
		else if (g_c.chaine_octet[g_c.i] == '0' && g_c.av > 0)
			kill(g_c.av, SIGUSR2);
		else
		{
			write (2, "Error\n", 6);
			free(g_c.chaine_octet);
			g_c.chaine_octet = NULL;
			exit(0);
		}
		g_c.i++;
		usleep(TIME_TO_SLEEP);
	}
	free(g_c.chaine_octet);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		write (2, "Error\nWrite the ID from the serveur\n", 36);
	else if (argc == 2)
		write (2, "Error\nWrite ONE MORE argument\n", 30);
	else if (argc == 3)
	{
		if (check_arg(argv) == 0)
			return (0);
		while (g_c.str[g_c.i])
		{
			if (make_chaine_octet() == 0)
				return (0);
			g_c.i++;
		}
		if (make_chaine_octet() == 0)
			return (0);
		send_signal();
	}
	else if (argc > 3)
		write (2, "Error\nToo many Arguments\n", 25);
	return (0);
}
