/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <hayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:16:28 by hayou             #+#    #+#             */
/*   Updated: 2022/04/26 18:42:15 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long long	i;
	long long	n;

	n = 1;
	while (n * n <= nb)
		n++;
	i = 2;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (0);
	else if (nb == 2)
		return (1);
	while (i <= n)
	{
		if (nb % i == 0)
			return (0);
		i ++;
	}
	return (1);
}
