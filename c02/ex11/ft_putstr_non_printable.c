/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:12:46 by hayou             #+#    #+#             */
/*   Updated: 2022/04/27 21:49:53 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printhexa(int i)
{
	ft_putchar('\\');
	ft_putchar("0123456789abcdef"[i / 16]);
	ft_putchar("0123456789abcdef"[i % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if ((*str >= 32 && *str <= 126))
			ft_putchar(*str);
		else
			ft_printhexa((unsigned char)*str);
		str ++;
	}
}
