/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:31:24 by hayou             #+#    #+#             */
/*   Updated: 2022/04/17 18:02:27 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char *c, int n)
{
	write(1, c, n);
	if (c[0] == ':' - n)
		return ;
	write(1, ", ", 2);
}

void	ft_dfs(int idx, int i, char *c, int n)
{
	if (idx == n)
	{
		ft_putchar(c, n);
		return ;
	}
	else
	{
		while (i < 10)
		{
			c[idx] = '0' + i;
			ft_dfs(idx + 1, i + 1, c, n);
			i++;
		}
		return ;
	}
}

void	ft_print_combn(int n)
{
	char	c[10];

	ft_dfs(0, 0, c, n);
}
