/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <hayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:42:31 by hayou             #+#    #+#             */
/*   Updated: 2022/04/25 14:37:04 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_check(char *base)
{
	int	len;
	int	i;

	len = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[len])
	{
		i = 0;
		while (i < len)
		{
			if (base[len] == base[i])
				return (0);
			i++;
		}
		if (base[len] == '+' || base[len] == '-')
			return (0);
		len ++;
	}
	return (len);
}

void	ft_printnbr(long long nbr, int base_len, char *base)
{
	if (nbr >= base_len)
		ft_printnbr(nbr / base_len, base_len, base);
	ft_putchar(base[nbr % base_len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_len;
	long long	nb;

	nb = (long long)nbr;
	base_len = ft_check(base);
	if (base_len == 0)
		return ;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	ft_printnbr(nb, base_len, base);
}
