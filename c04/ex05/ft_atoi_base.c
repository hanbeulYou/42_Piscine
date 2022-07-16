/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 19:15:26 by hayou             #+#    #+#             */
/*   Updated: 2022/04/28 16:36:53 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int	len;
	int	i;

	len = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[len])
	{
		i = 0;
		while (i < len)
		{
			if (base[len] == base[i])
				return (0);
			i++;
		}
		if (base[len] == '+' || base[len] == '-')
			return (0);
		len ++;
	}
	return (len);
}

int	base_return(char c, char *base, int base_len)
{
	int	idx;
	int	return_value;

	idx = 0;
	return_value = -1;
	while (idx < base_len)
	{
		if (c == base[idx])
			return_value = idx;
		idx ++;
	}
	return (return_value);
}

int	ft_do_atoi(char *str, char *base, int base_len)
{
	int	atoi;
	int	sign;

	atoi = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str ++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str ++;
	}
	while (*str)
	{
		if (base_return(*str, base, base_len) != -1)
		{
			atoi *= base_len;
			atoi += base_return(*str, base, base_len);
			str ++;
		}
		else
			break ;
	}
	return (atoi * sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	value;

	base_len = check_base(base);
	if (base_len == 0)
		return (0);
	value = ft_do_atoi(str, base, base_len);
	return (value);
}

#include <stdio.h>
int main()
{

	//ex05
	printf("------ ex05 ------\n\n");
	char ex05_str1[] = " \n -+-++-+2147483648";
	char ex05_str2[] = "   ---+AABCDESSEZ";
	char ex05_str3[] = "   ++136667";
	char ex05_str4[] = "   -----+-+!!@@#..<";
	char ex05_str5[] = "  \n \tatoi12-+123base";

	printf("-2147483648\n");
	printf("%d\n\n", ft_atoi_base(ex05_str1, "0123456789"));

	printf("0\n");
	printf("%d\n\n", ft_atoi_base(ex05_str1, ""));

	printf("-67174\n");
	printf("%d\n\n", ft_atoi_base(ex05_str2, "ABCDES"));

	printf("-1\n");
	printf("%d\n\n", ft_atoi_base(ex05_str2, "ABZ"));

	printf("0\n");
	printf("%d\n\n", ft_atoi_base(ex05_str3, "A-+"));

	printf("12347\n");
	printf("%d\n\n", ft_atoi_base(ex05_str3, "3405816"));

	printf("1126397\n");
	printf("%d\n\n", ft_atoi_base(ex05_str4, "!@#$%^&*()~?><'."));

	printf("27\n");
	printf("%d\n\n", ft_atoi_base(ex05_str5, "atoi"));
}

