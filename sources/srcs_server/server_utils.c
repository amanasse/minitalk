/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:56:33 by amanasse          #+#    #+#             */
/*   Updated: 2022/09/20 16:19:25 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	put_my_buff(t_server *g_mini)
{
	g_mini->str1[0] = g_mini->nb;
	g_mini->str1[1] = '\0';
	g_mini->tmp = g_mini->str_def;
	g_mini->str_def = ft_strjoin(g_mini->str_def, g_mini->str1);
	if (g_mini->str_def == NULL)
	{
		free (g_mini->tmp);
		exit (0);
	}
	free (g_mini->tmp);
	g_mini->tmp = NULL;
	g_mini->x = 0;
}
