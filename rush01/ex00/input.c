/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:52:00 by hayou             #+#    #+#             */
/*   Updated: 2022/04/24 23:01:58 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**make_nn_array(int size)
{
	int	i;
	int	j;
	int	**array;

	array = (int **)malloc(sizeof(int *) * size);
	i = 0;
	while (i < size)
	{
		array[i] = (int *)malloc(sizeof(int) * size);
		j = 0;
		while (j < size)
		{
			array[i][j] = 0;
			j++;
		}
		i++;
	}
	return (array);
}

int	**argv_to_input(int **input, char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str >= '1' && *str <= '4')
		{
			input[i / 4][i % 4] = *str - '0';
			i++;
		}
		str++;
	}
	return (input);
}

int	check_argv(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if ((*str >= 9 && *str <= 13) || *str == 32)
			str++;
		else
		{
			if (*str < '1' || *str > '4')
				return (0);
			else if (*(str+1) > 1'
			else
				count++;
			str ++;
		}
	}
	if (count != 16)
		return (0);
	return (1);
}
