/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:52:00 by hayou             #+#    #+#             */
/*   Updated: 2022/04/24 16:19:23 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_left(int **table, int i, int **input)
{
	int	count;
	int	max;
	int	idx;

	count = 0;
	max = 0;
	idx = 0;
	while (idx < 4)
	{
		if (max < table[i][idx])
		{
			count ++;
			max = table[i][idx];
		}
		idx ++;
	}
	if (count != input[2][i])
		return (0);
	return (1);
}

int	check_right(int **table, int i, int **input)
{
	int	count;
	int	max;
	int	idx;

	count = 0;
	max = 0;
	idx = 3;
	while (idx >= 0)
	{
		if (max < table[i][idx])
		{
			count ++;
			max = table[i][idx];
		}
		idx --;
	}
	if (count != input[3][i])
		return (0);
	return (1);
}

int	check_up(int **table, int j, int **input)
{
	int	count;
	int	max;
	int	idx;

	count = 0;
	max = 0;
	idx = 0;
	while (idx < 4)
	{
		if (max < table[idx][j])
		{
			count ++;
			max = table[idx][j];
		}
		idx ++;
	}
	if (count != input[0][j])
		return (0);
	return (1);
}

int	check_down(int **table, int j, int **input)
{
	int	count;
	int	max;
	int	idx;

	count = 0;
	max = 0;
	idx = 3;
	while (idx >= 0)
	{
		if (max < table[idx][j])
		{
			count ++;
			max = table[idx][j];
		}
		idx --;
	}
	if (count != input[1][j])
		return (0);
	return (1);
}

int	finish_all(int **table, int idx, int **input)
{
	int	flag;

	flag = 1;
	if (idx % 4 == 3)
	{
		if (check_right(table, idx / 4, input) && \
				check_left(table, idx / 4, input))
			flag = 1;
		else
			flag = 0;
	}
	if (idx / 4 == 3)
	{
		if (check_up(table, idx % 4, input) && \
				check_down(table, idx % 4, input))
			flag = 1;
		else
			flag = 0;
	}
	return (flag);
}
