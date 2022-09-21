/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:34:16 by amanasse          #+#    #+#             */
/*   Updated: 2022/09/21 15:21:39 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

t_client	g_c;

char	*binaire(char a)
{
	int		i;
	char	*octet;

	i = 6;
	octet = malloc(8);
	if (octet == NULL)
		return (NULL);
	while (i >= 0)
	{
		octet[i] = a % 2 + '0';
		a = a / 2;
		i--;
	}
	octet[7] = '\0';
	return (octet);
}

int	make_chaine_octet(void)
{
	g_c.tmp = binaire(g_c.str[g_c.i]);
	if (g_c.tmp == NULL)
		return (0);
	g_c.tmp2 = g_c.chaine_octet;
	g_c.chaine_octet = ft_strjoin(g_c.chaine_octet, g_c.tmp);
	if (g_c.chaine_octet == NULL)
	{
		free(g_c.tmp);
		free(g_c.tmp2);
		g_c.tmp = NULL;
		g_c.tmp2 = NULL;
		return (0);
	}
	free(g_c.tmp);
	free(g_c.tmp2);
	g_c.tmp = NULL;
	g_c.tmp2 = NULL;
	return (1);
}

void	send_signal(char **argv)
{
	g_c.i = 0;
	while (g_c.chaine_octet[g_c.i] != '\0')
	{
		if (g_c.chaine_octet[g_c.i] == '1' && ft_atoi(argv[1]) > 0)
			kill(ft_atoi(argv[1]), SIGUSR1);
		else if (g_c.chaine_octet[g_c.i] == '0' && ft_atoi(argv[1]) > 0)
			kill(ft_atoi(argv[1]), SIGUSR2);
		else
		{
			write (2, "Error\n", 6);
			free(g_c.tmp);
			free(g_c.chaine_octet);
			g_c.tmp = NULL;
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
		g_c.str = argv[2];
		g_c.i = 0;
		g_c.chaine_octet = malloc(1);
		if (g_c.chaine_octet == NULL)
			return (0);
		g_c.chaine_octet[0] = '\0';
		while (g_c.str[g_c.i])
		{
			if (make_chaine_octet() == 0)
				return (0);
			g_c.i++;
		}
		if (make_chaine_octet() == 0)
			return (0);
		send_signal(argv);
	}
	else if (argc > 3)
		write (2, "Error\nToo many Arguments\n", 25);
	return (0);
}
