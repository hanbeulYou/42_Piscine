/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queenz_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <hayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:10:18 by hayou             #+#    #+#             */
/*   Updated: 2022/04/26 16:11:38 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_print(int table[10][10])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (table[i][j] == 1)
			{
				c = '0' + j;
				write(1, &c, 1);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

int	ft_check_fn(int table[10][10], int idx, int check_i, int check_j)
{
	int	i;
	int	j;

	i = idx / 10 + check_i;
	j = idx % 10 + check_j;
	while (i >= 0 && j >= 0 && j < 10)
	{
		if (table[i][j] != 0)
			return (0);
		i += check_i;
		j += check_j;
	}
	return (1);
}

int	ft_check(int table[10][10], int idx)
{
	if (ft_check_fn(table, idx, -1, 0) == 0)
		return (0);
	if (ft_check_fn(table, idx, -1, -1) == 0)
		return (0);
	if (ft_check_fn(table, idx, -1, 1) == 0)
		return (0);
	return (1);
}

void	ft_puzzle(int table[10][10], int idx, int *res)
{
	if (idx >= 100)
	{
		(*res)++;
		ft_print(table);
		return ;
	}
	if (ft_check(table, idx) == 1)
	{
		table[idx / 10][idx % 10] = 1;
		ft_puzzle(table, idx + 10 - idx % 10, res);
		table[idx / 10][idx % 10] = 0;
	}
	if (idx % 10 < 9)
	{
		ft_puzzle(table, idx + 1, res);
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	j;
	int	res;
	int	table[10][10];

	res = 0;
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			table[i][j] = 0;
			j++;
		}
		i++;
	}
	ft_puzzle(table, 0, &res);
	return (res);
}
/*
int main(void)
{
	printf("\n\n%d\n\n\n", ft_ten_queens_puzzle());
	return (0);
}*/
