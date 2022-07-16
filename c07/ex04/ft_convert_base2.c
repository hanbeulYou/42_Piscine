/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <hayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:43:00 by hayou             #+#    #+#             */
/*   Updated: 2022/04/28 20:12:25 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_len(char *base)
{
	int	len;
	int	i;

	len = 0;
	while (base[len])
	{
		i = 0;
		while (i < len)
		{
			if (base[len] == base[i])
				return (0);
			i ++;
		}
		if (base[len] == '+' || base[len] == '-')
			return (0);
		if ((base[len] >= 9 && base[len] <= 13) || base[len] == 32)
			return (0);
		len ++;
	}
	if (len <= 1)
		return (0);
	return (len);
}

int	check_in_base(char c, char *base, int base_len)
{
	int	idx;

	idx = 0;
	while (idx < base_len)
	{
		if (c == base[idx])
			return (idx);
		idx ++;
	}
	return (-1);
}

int	count_output_len(long long value, int base_len)
{
	int	count;

	count = 1;
	while (value >= base_len)
	{
		value /= base_len;
		count ++;
	}
	return (count);
}
