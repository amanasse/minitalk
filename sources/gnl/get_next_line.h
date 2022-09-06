/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:32:34 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/08 13:09:29 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 500
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <ctype.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strlen_gnl(char *s);
char	*ft_strdup_gnl(char *s);
char	*get_next_line(int fd);
int		check_sep(char *str);
char	*stock_line_last(char *dest);

#endif