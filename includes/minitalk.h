/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:09:49 by amanasse          #+#    #+#             */
/*   Updated: 2022/09/26 09:43:37 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <ctype.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include "../sources/libft/includes/libft.h"

# define BUFFER 2
# define BUFFER_MAX 7

typedef struct s_server
{
	char	buff[BUFFER_MAX];
	char	str1[BUFFER];
	char	*tmp;
	char	*str_def;
	int		x;
	int		i;
	int		nb;
	char	a;
}				t_server;

typedef struct s_client
{
	char	binaire[BUFFER_MAX];
	char	*str;
	char	*chaine_octet;
	int		i;
	int		av;
	void	*p_str;
}				t_client;

void	put_my_buff(t_server *g_mini);

#endif