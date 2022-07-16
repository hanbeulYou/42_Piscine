/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <hayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:08:40 by hayou             #+#    #+#             */
/*   Updated: 2022/04/26 18:45:42 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long	n;

	if (nb < 0)
		return (0);
	n = 1;
	while (n * n < nb)
		n ++;
	if (n * n == nb)
		return (n);
	return (0);
}
