/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:34:01 by hayou             #+#    #+#             */
/*   Updated: 2022/04/30 01:47:24 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	base_len(char *base);
int	check_in_base(char c, char *base, int base_len);
int	count_output_len(long long value, int base_len);

long long	ft_atoi(char *str, char *base, int base_len)
{
	int			sign;
	long long	atoi;

	atoi = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str ++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str ++;
	}
	while (*str)
	{
		if (check_in_base(*str, base, base_len) != -1)
		{
			atoi *= base_len;
			atoi += check_in_base(*str, base, base_len);
			str++;
		}
		else
			break ;
	}
	return (atoi * sign);
}

char	*ft_itoa(long long value, char *base, int base_len, int sign)
{
	int		str_len;
	int		idx;
	char	*str;

	str_len = count_output_len(value, base_len);
	if (sign == -1)
		str_len ++;
	str = (char *)malloc(sizeof(char) * str_len + 1);
	if (str == 0)
		return (0);
	idx = str_len - 1;
	str[str_len] = 0;
	while (value >= base_len)
	{
		str[idx] = base[value % base_len];
		value /= base_len;
		idx --;
	}
	str[idx] = base[value % base_len];
	if (sign == -1)
		str[0] = '-';
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char		*str;
	int			base_from_len;
	int			base_to_len;
	long long	value;

	base_from_len = base_len(base_from);
	base_to_len = base_len(base_to);
	if (base_from_len == 0 || base_to_len == 0)
		return (0);
	value = ft_atoi(nbr, base_from, base_from_len);
	if (value >= 0)
		str = ft_itoa(value, base_to, base_to_len, 1);
	else
		str = ft_itoa(value * (-1), base_to, base_to_len, -1);
	return (str);
}
