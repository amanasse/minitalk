/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:34:16 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/10 17:53:20 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main (int argc, char **argv)
{
    printf("client OK :\n");
    (void)argc;

    if (argc >= 2)
    {
    	kill(atoi(argv[1]), SIGUSR2);
		usleep(90);
    	kill(atoi(argv[1]), SIGUSR1);
		usleep(90);
    	kill(atoi(argv[1]), SIGUSR2);
		usleep(90);
    	kill(atoi(argv[1]), SIGUSR1);
		usleep(90);
    	kill(atoi(argv[1]), SIGUSR1);
		usleep(90);
    	kill(atoi(argv[1]), SIGUSR1);
		usleep(90);
    	kill(atoi(argv[1]), SIGUSR1);
		usleep(90);
    	kill(atoi(argv[1]), SIGUSR1);
		usleep(90);
    	kill(atoi(argv[1]), SIGUSR1);
		usleep(90);
    	kill(atoi(argv[1]), SIGUSR1);
		usleep(90);
    	kill(atoi(argv[1]), SIGUSR1);
    }
    return (0);
}