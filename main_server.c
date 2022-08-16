/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:35:39 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/16 16:34:39 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void bin_to_char(char *str)
// {




// }

void    make_my_buff (t_minitalk *mini, char c)
{
    mini->buff[mini->x] = c;
        mini->x++;
    if (mini->x == BUFFER_MAX)
    {
        printf("str = %s\n", mini->buff);
        // bin_to_char(mini->buff);
        mini->x = 0;
    }
}

void    listen(int sig)
{
    t_minitalk  mini;

    if (sig == SIGUSR1)
	{
		make_my_buff(&mini, '1');
		write(1, "1\n", 2);
	}
    else if (sig == SIGUSR2)
    {
		make_my_buff(&mini, '0');
		write(1, "0\n", 2);
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

    // SA_SIGACTION POUR RECUP LE SIGNAL DE LEMETTEUR
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