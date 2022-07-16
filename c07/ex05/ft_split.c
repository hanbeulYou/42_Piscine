/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:51:19 by hayou             #+#    #+#             */
/*   Updated: 2022/04/29 23:21:58 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset, int len)
{
	int	i;

	i = 0;
	if (c == 0)
		return (1);
	while (i < len)
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count(char *str, char *charset, int len, int flag)
{
	int	size;

	size = 0;
	if (flag == 0)
	{
		while (*str)
		{
			if (is_sep(*str, charset, len) == 1)
				str ++;
			else
			{
				size ++;
				while (is_sep(*str, charset, len) == 0)
					str++;
			}
		}
		return (size);
	}
	else
	{
		while (*(str + size) && is_sep(*(str + size), charset, len) == 0)
			size ++;
		return (size);
	}
}

char	*split_word(char *str, char *charset, int len, int word_count)
{
	int		idx;
	char	*str_return;

	str_return = (char *)malloc(sizeof(char) * (word_count + 1));
	if (str_return == 0)
		return (0);
	idx = 0;
	while (*str && is_sep(*str, charset, len) == 0)
	{
		str_return[idx] = *str;
		str ++;
		idx ++;
	}
	str_return[idx] = 0;
	return (str_return);
}

char	**do_split(char **array, char *str, char *charset, int size)
{
	int	len;
	int	idx;
	int	wc;

	len = 0;
	while (charset[len])
		len ++;
	idx = 0;
	while (idx < size)
	{
		while (*str)
		{
			if (is_sep(*str, charset, len) == 0)
			{
				wc = ft_count(str, charset, len, 1);
				array[idx] = split_word(str, charset, len, wc);
				str += wc;
				break ;
			}
			str ++;
		}
		idx++;
	}
	array[idx] = 0;
	return (array);
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	int		size;
	int		len;

	len = 0;
	while (charset[len])
		len ++;
	size = ft_count(str, charset, len, 0);
	array = (char **)malloc(sizeof(char *) * (size + 1));
	if (array == 0)
		return (0);
	array = do_split(array, str, charset, size);
	return (array);
}
