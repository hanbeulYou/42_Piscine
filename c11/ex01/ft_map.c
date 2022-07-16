/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <hayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 04:45:22 by hayou             #+#    #+#             */
/*   Updated: 2022/05/05 12:21:18 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*array;
	int	i;

	array = (int *)malloc(sizeof(int) * length);
	if (!array)
		return (0);
	i = 0;
	while (i < length)
	{
		array[i] = (*f)(tab[i]);
		i ++;
	}
	return (array);
}
