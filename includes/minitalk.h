/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:09:49 by amanasse          #+#    #+#             */
/*   Updated: 2022/09/06 17:42:18 by amanasse         ###   ########.fr       */
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
# include "../sources/libft/libft.h"
# include "../sources/ft_printf/ft_printf.h"
# include "../sources/gnl/get_next_line.h"

# define BUFFER 2
# define BUFFER_MAX 7

typedef struct s_minitalk
{
    char 	buff[BUFFER_MAX];
	char	str1[BUFFER];
    char    *tmp;
    char    *str_def;
    int 	x;
    int 	i;
    int 	nb;
    char 	a;
}               t_minitalk;




#endif