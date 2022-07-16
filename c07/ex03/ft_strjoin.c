/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:12:08 by hayou             #+#    #+#             */
/*   Updated: 2022/05/01 05:09:13 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len ++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i])
		i++;
	while (*src)
	{
		dest[i] = *src;
		i ++;
		src ++;
	}
	dest[i] = 0;
	return (dest);
}

char	*do_malloc(int len, int size)
{
	char	*str;

	if (size == 0)
		len = 0;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == 0)
		return (0);
	str[0] = 0;
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i ++;
	}
	i = ft_strlen(sep);
	len += (size - 1) * i;
	str = do_malloc(len, size);
	i = 0;
	while (i < size)
	{
		str = ft_strcat(str, strs[i]);
		i++;
		if (i != size)
			str = ft_strcat(str, sep);
	}
	return (str);
}
