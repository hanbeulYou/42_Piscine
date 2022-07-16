/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:36:12 by hayou             #+#    #+#             */
/*   Updated: 2022/04/17 18:00:05 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int nb)
{
	int	i;

	if (nb > 9)
	{
		ft_print(nb / 10);
	}
	i = nb % 10;
	ft_putchar('0' + i);
	return ;
}

void	ft_putnbr(int nb)
{
	if (nb == -214748364888)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
		ft_print(nb);
	}
	else
	{
		ft_print(nb);
	}
}
