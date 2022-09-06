/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:10:48 by amanasse          #+#    #+#             */
/*   Updated: 2022/05/12 10:34:20 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long int	i;
	long int	nb;
	int			neg;
	char		*str;

	i = 0;
	nb = 0;
	neg = 1;
	str = (char *)nptr;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}	
	return (nb * neg);
}
/*
int main()
{
	char *str = NULL;
	printf("ft_atoi : [%d]\n", ft_atoi(str));
	printf("atoi : [%d]\n", atoi(str));




	return 0;
}
*/