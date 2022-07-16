/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:43:08 by hayou             #+#    #+#             */
/*   Updated: 2022/04/19 19:42:56 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_type(char c)
{
	if (c >= 'A' && c <= 'Z')
		return ('U');
	else if (c >= 'a' && c <= 'z')
		return ('L');
	else if (c >= '0' && c <= '9')
		return ('D');
	else
		return ('O');
}

char	*ft_strcapitalize(char *str)
{
	int		idx;
	char	type;

	idx = 0;
	while (str[idx])
	{
		type = ft_type(str[idx]);
		if (idx == 0)
		{
			if (type == 'L')
				str[idx] -= 32;
		}
		else if (ft_type(str[idx - 1]) == 'O')
		{
			if (type == 'L')
				str[idx] -= 32;
		}
		else if (type == 'U')
		{
			str[idx] += 32;
		}
		idx ++;
	}
	return (str);
}
