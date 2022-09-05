/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:09:49 by amanasse          #+#    #+#             */
/*   Updated: 2022/09/05 15:52:56 by amanasse         ###   ########.fr       */
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
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"

# define BUFFER 2
# define BUFFER_MAX 7

typedef struct s_minitalk
{
    char 	buff[BUFFER_MAX];
	char	str1[BUFFER];
    char    *str_def;
	char	*tmp;
    int 	x;
    int 	i;
    int 	nb;
    char 	a;
}               t_minitalk;




#endif