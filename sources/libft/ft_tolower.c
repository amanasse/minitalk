/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:15:25 by amanasse          #+#    #+#             */
/*   Updated: 2022/05/12 10:38:02 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}

/*
int main()
{
	int a;
	a = 66;
	printf("%d\n", tolower(a));
	printf("%d\n", ft_tolower(a));
	printf("%d\n", a);
	return 0;
}
*/
