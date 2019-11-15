/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:52:53 by mkhoza            #+#    #+#             */
/*   Updated: 2019/07/22 14:53:17 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	ft_putnbr(int n)
{
	unsigned int	nb;

	if (n < 0)
	{
		nb = -n;
		ft_putchar('-');
	}
	else
		nb = n;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	else
		ft_putchar(nb + '0');
}
