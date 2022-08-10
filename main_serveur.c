/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_serveur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:35:39 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/10 15:39:31 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    listen(int sig, siginfo_t *info, void *tmp)
{
    (void)tmp;
    (void)info;
    if (sig == SIGUSR1)
        write(1, "ft_stock_1\n", 5);
    else if (sig == SIGUSR2)
        write(1, "ft_stock_0\n", 5);
    else
        write(1, "error\n", 6);
}
int main ()
{
    struct sigaction sa;


    sa.sa_sigaction = &listen;
    printf("serveur OK : %d\n",getpid());
    sleep(1);

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    printf("listen \n");
    while (1)
        pause();
    printf("serveur KO :\n");
    return (0);
}