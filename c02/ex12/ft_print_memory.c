/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:15:27 by hayou             #+#    #+#             */
/*   Updated: 2022/05/05 19:45:54 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_addr(unsigned long long add)
{
	if (add > 16)
		print_addr(add / 16);
	write(1, &"0123456789abcdef"[add % 16], 1);
}

void	print_zero(unsigned long long add)
{
	unsigned long long	temp;
	unsigned long long	len;

	temp = add;
	len = 1;
	while (temp > 16)
	{
		temp /= 16;
		len ++;
	}
	while (len < 16)
	{
		write(1, "0", 1);
		len ++;
	}
	print_addr(add);
}

void	print_hexa(char c, unsigned int len, int check)
{
	int	i;

	if (check == 1)
	{
		i = (int)c;
		write(1, &"0123456789abcdef"[i / 16], 1);
		write(1, &"0123456789abcdef"[i % 16], 1);
	}
	else
		write(1, "  ", 2);
	if (len % 2 == 1)
		write(1, " ", 1);
}

void	print_str(char *str)
{
	unsigned int	i;
	unsigned char	c;

	i = 0;
	while (i < 16 && str[i])
	{
		c = (unsigned char)str[i];
		if (c >= 32 && c <= 126)
			write(1, &c, 1);
		else
			write(1, ".", 1);
		i ++;
	}
	if (str[i] == 0)
		write(1, ".", 1);
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long long	len;
	char				*str;

	len = 0;
	str = (char *)addr;
	while (len < size)
	{
		print_zero((unsigned long long)addr);
		write(1, ": ", 1);
		while (str[len] || len == size - 1)
		{
			print_hexa(str[len], len, 1);
			len ++;
			if (len % 16 == 0)
				break ;
		}
		while (len % 16 != 0)
		{
			print_hexa(0, len, 0);
			len ++;
		}
		print_str(str + len - 16);
		addr += 16;
	}
	return (addr);
}

int	main()
{
	char	str[92] = "Bonjour les aminches   c  est fou tout ce qu on peut faire avec   print_memory    lol lol";
	str[20] = 0x09;
 	str[21] = 0x0a;
 	str[22] = 0x09;
 	str[33] = 0x09;
 	str[38] = 0x09;
 	str[63] = 0x09;
 	str[64] = 0x0a;
 	str[65] = 0x09;
 	str[78] = 0x0a;
 	str[79] = 0x0a;
 	str[80] = 0x0a;
 	str[81] = 0x09;
	str[85] = 0x2e;
	str[89] = 0x0a;
	str[90] = 0x20;
	ft_print_memory(str, 92);
}
