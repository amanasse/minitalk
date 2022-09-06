/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:05:13 by amanasse          #+#    #+#             */
/*   Updated: 2022/08/08 13:05:39 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long long nb, char *base)
{
	if (nb >= (unsigned long long)ft_strlen_printf(base))
	{
		ft_putnbr_base(nb / (unsigned long long)ft_strlen_printf(base), base);
		ft_putnbr_base(nb % (unsigned long long)ft_strlen_printf(base), base);
	}
	else
		write (1, &base[nb], 1);
}
