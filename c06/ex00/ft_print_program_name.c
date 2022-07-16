/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:37:55 by hayou             #+#    #+#             */
/*   Updated: 2022/04/27 16:03:36 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	idx;

	if (argc != 1)
		return (0);
	idx = 0;
	while (argv[0][idx])
	{
		ft_putchar(argv[0][idx]);
		idx++;
	}
	ft_putchar('\n');
	return (0);
}
