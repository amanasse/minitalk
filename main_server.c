/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:35:39 by amanasse          #+#    #+#             */
/*   Updated: 2022/09/05 16:12:59 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_minitalk g_mini;

void	join_my_char(void)
{
	g_mini.str1[0] = g_mini.nb;
	g_mini.str1[1] = '\0';
	printf("str1 = %s\n", g_mini.str1);
}

char bin_to_char(void)
{
	g_mini.i = 0;
	g_mini.nb = 0;
	if(g_mini.buff[g_mini.i] == '1')
		g_mini.nb += 64;
	g_mini.i++;			
	if(g_mini.buff[g_mini.i] == '1')
		g_mini.nb += 32;
	g_mini.i++;
	if(g_mini.buff[g_mini.i] == '1')
		g_mini.nb += 16;
	g_mini.i++;
	if(g_mini.buff[g_mini.i] == '1')
		g_mini.nb += 8;
	g_mini.i++;
	if(g_mini.buff[g_mini.i] == '1')
		g_mini.nb += 4;
	g_mini.i++;
	if(g_mini.buff[g_mini.i] == '1')
		g_mini.nb += 2;
	g_mini.i++;
	if(g_mini.buff[g_mini.i] == '1')
		g_mini.nb += 1;
	printf ("g_mini.nb = %d\n", g_mini.nb);
	return (g_mini.nb);		
}




void    make_my_buff (char c)
{
	if (g_mini.x > BUFFER_MAX || g_mini.x < 0)
		g_mini.x = 0;
    g_mini.buff[g_mini.x] = c;
    printf("g_mini.buff[g_mini.x] = %c\n", g_mini.buff[g_mini.x] = c);
    g_mini.x += 1;
	
		
    if (g_mini.x == BUFFER_MAX)
    {
        printf("str = %s\n", g_mini.buff);
		bin_to_char();
		// if (bin_to_char(g_mini) == 0)
		// 	printf("str_DEFFFFFFF = %s\n", g_mini.str_def);
		join_my_char();
		printf("lettre retournee = %c\n", g_mini.nb);
		// if (g_mini.str_def[0] != '\0')
		g_mini.str_def = ft_strjoin(g_mini.str_def, g_mini.str1);
		// else
		// 	g_mini.str_def = g_mini.str1;
		printf("str_def = %s\n", g_mini.str_def);

		g_mini.x = 0;
    }
}

void	init_mini(void)
{
	g_mini.x = 0;
	ft_memset(g_mini.buff, 0, 7);
	g_mini.str_def = malloc(1);
	g_mini.str_def[0] = '\0';
}

void    listen(int sig)
{
    // t_minitalk  mini;
	
	// init_mini(&mini);
    if (sig == SIGUSR1)
	{
		write(1, "1\n", 2);
		make_my_buff('1');
	}
    else if (sig == SIGUSR2)
    {
		write(1, "0\n", 2);
		make_my_buff('0');
	}	
	else 
	{
		write(1, "exit\n", 5);
		exit(0);
	}
}

int main ()
{
    struct sigaction sa;
	// t_minitalk	d;
    // SA_SIGACTION POUR RECUP LE SIGNAL DE LEMETTEUR
	
	init_mini();
    sa.sa_handler = listen;
    sa.sa_flags = SA_RESTART;
    printf("serveur OK : %d\n",getpid());
    // sleep(1);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    sigaction(SIGINT, &sa, NULL);
    
    while (1)
    {
        // signal = pause;
    }
    return (0);
}