/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:52:00 by hayou             #+#    #+#             */
/*   Updated: 2022/04/24 16:19:30 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col(int **table, int idx)
{
	int	i;
	int	check[5];

	i = 0;
	while (i < 5)
	{
		check[i] = 0;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (table[i][idx % 4] != 0)
			check[table[i][idx % 4]]++;
		if (check[table[i][idx % 4]] > 1)
			return (0);
		i++;
	}
	return (1);
}

int	check_row(int **table, int idx)
{
	int	i;
	int	check[5];

	i = 0;
	while (i < 5)
	{
		check[i] = 0;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (table[idx / 4][i] != 0)
			check[table[idx / 4][i]]++;
		if (check[table[idx / 4][i]] > 1)
			return (0);
		i++;
	}
	return (1);
}

int	check(int **table, int idx)
{
	if (check_row(table, idx) && check_col(table, idx))
		return (1);
	return (0);
}
