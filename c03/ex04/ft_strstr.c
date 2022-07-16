/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 22:46:08 by hayou             #+#    #+#             */
/*   Updated: 2022/04/21 15:23:34 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	check;

	if (!*to_find)
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			i = 0;
			check = 0;
			while (to_find[i])
			{
				if (str[i] != to_find[i])
					check = 1;
				i ++;
			}
			if (check == 0)
				return (str);
		}
		str ++;
	}
	return (0);
}
