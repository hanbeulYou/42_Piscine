/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:52:00 by hayou             #+#    #+#             */
/*   Updated: 2022/04/24 22:24:01 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	**make_nn_array(int size);
int	**argv_to_input(int **input, char *str);
int	check_argv(char *str);
int	finish_all(int **table, int idx, int **input);
int	check(int **table, int idx);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int **table)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar('0' + table[i][j]);
			j++;
			if (j != 4)
				ft_putchar(' ');
		}
		i++;
		ft_putchar('\n');
	}
}

int	ft_table(int **table, int idx, int value, int **input)
{
	while (value <= 4)
	{
		table[idx / 4][idx % 4] = value;
		if (check(table, idx) && finish_all(table, idx, input))
		{
			if (idx == 15)
			{
				ft_print(table);
				return (1);
			}
			else
			{
				if (ft_table(table, idx + 1, 1, input))
					return (1);
			}
		}
		value ++;
	}
	table[idx / 4][idx % 4] = 0;
	return (0);
}

void	free_alloc(int **table, int **input)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(table[i]);
		free(input[i]);
		i++;
	}
	free(table);
	free(input);
}

int	main(int argc, char **argv)
{
	int	**input;
	int	**table;
	int	error;

	if (argc != 2)
		return (0);
	error = check_argv(argv[1]);
	if (error == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	input = make_nn_array(4);
	table = make_nn_array(4);
	input = argv_to_input(input, argv[1]);
	error = ft_table(table, 0, 1, input);
	if (error == 0)
		write(1, "Error\n", 6);
	free_alloc(table, input);
	return (0);
}
