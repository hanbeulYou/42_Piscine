/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <hayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 05:41:07 by hayou             #+#    #+#             */
/*   Updated: 2022/05/05 12:40:34 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	is_up;
	int	is_down;

	i = 0;
	is_up = 1;
	is_down = 1;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			is_up = 0;
		if ((*f)(tab[i], tab[i + 1]) < 0)
			is_down = 0;
		i ++;
	}
	if (is_up == 1 || is_down == 1)
		return (1);
	return (0);
}
