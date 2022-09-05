/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:34:16 by amanasse          #+#    #+#             */
/*   Updated: 2022/09/05 16:12:17 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char* binaire(char a)
{
    int i = 6;
    char* octet = malloc(8);
 
    while (i >= 0)
    {
        octet[i] = (a & 1) + '0';
        a >>= 1;
		i--;
    }
    octet[7] = '\0';
    return octet;
}

// char *str_null(char c)
// {
// 	char *str_null;
// 	int i;

// 	if (c == '\0')
// 	{
// 		str_null = malloc(8);
// 		i = 0;
// 		while (i < 7)
// 		{
// 			str_null[i] = '0';
// 			i++;
// 		}
// 		str_null[i] = '\0';
// 	}
// 	return (str_null);
// }

int main (int argc, char **argv)
{
    // printf("client OK :\n");
    (void)argc;
    if (argc == 1)
    {
    	write (2, "Write the ID from the serveur and ONE argument\n", 48);
		return (0);
    }
	else if (argc == 2)
    {
    	write (2, "Write ONE MORE argument\n", 25);
		return (0);
    }
    else if (argc == 3)
    {
		char *str;
		char *chaine_octet;
		int i;
		void *tmp;
		void *tmp2;

		str = argv[2];
		i = 0;
		while (argv[2][i])
		{
			str[i] = argv[2][i];
			i++;
		}
		str[i] = '\0';
		// printf ("str = %s\n", str);
		i = 0;
		chaine_octet = malloc(1);
		chaine_octet[0] = '\0';
		while (str[i])
		{
			tmp = binaire(str[i]);
			tmp2 = chaine_octet;
			chaine_octet = ft_strjoin(chaine_octet, tmp);
			free(tmp);
			free(tmp2);
			tmp = NULL;
			tmp2 = NULL;
			i++;
		}

		tmp = binaire(str[i]);
		tmp2 = chaine_octet;
		chaine_octet = ft_strjoin(chaine_octet, tmp);
		free(tmp);
		free(tmp2);
		tmp = NULL;
		tmp2 = NULL;

		// printf ("str[i] = %c\n", str[i]);

		// printf ("str_null = %s\n", str_null(str[i]));
		// chaine_octet = ft_strjoin(chaine_octet, str_null(str[i]));
		// printf ("chaine_octet = %s\n", chaine_octet);
		i = 0;
		while (chaine_octet[i] != '\0')
		{
			if (chaine_octet[i] == '1')
				kill(ft_atoi(argv[1]), SIGUSR1);
			else
				kill(ft_atoi(argv[1]), SIGUSR2);
			i++;
			usleep(180);
		}
		free(chaine_octet);
    }
    return (0);
}