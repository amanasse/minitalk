/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_serveur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:35:39 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/15 16:32:02 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    listen(int sig)
{
    if (sig == SIGUSR1)
        write(1, "ft_stock_1\n", 11);
    else if (sig == SIGUSR2)
        write(1, "ft_stock_0\n", 11);
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
    sa.sa_handler = &listen;
    sa.sa_flags = SA_RESTART;
    printf("serveur OK : %d\n",getpid());
    sleep(1);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    sigaction(SIGINT, &sa, NULL);
    
    while (1)
    {
        // signal = pause;
    }
    return (0);
}