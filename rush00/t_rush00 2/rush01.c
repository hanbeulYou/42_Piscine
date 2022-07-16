/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <hayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 13:02:21 by hayou             #+#    #+#             */
/*   Updated: 2022/04/17 13:02:33 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_firstline(int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
		{
			ft_putchar('/');
		}
		else if (i == x - 1)
		{
			ft_putchar('\\');
		}
		else
		{
			ft_putchar('*');
		}
		i++;
	}
	ft_putchar('\n');
}

void	ft_otherline(int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0 || i == x - 1)
		{
			ft_putchar('*');
		}
		else
		{
			ft_putchar(' ');
		}
		i++;
	}
	ft_putchar('\n');
}

void	ft_lastline(int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
		{
			ft_putchar('\\');
		}
		else if (i == x - 1)
		{
			ft_putchar('/');
		}
		else
		{
			ft_putchar('*');
		}
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	line;

	line = 0;
	if (x < 1 || y < 1)
	{
		return ;
	}
	while (line < y)
	{
		if (line == 0)
		{
			ft_firstline(x);
		}
		else if (line == y - 1)
		{
			ft_lastline(x);
		}
		else
		{
			ft_otherline(x);
		}
		line++ ;
	}
}
