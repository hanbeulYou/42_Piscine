/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 23:56:45 by hayou             #+#    #+#             */
/*   Updated: 2022/04/21 19:40:53 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	count_len(char *array)
{
	unsigned int	len;

	len = 0;
	while (array[len])
		len ++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len_src;
	unsigned int	i;

	i = 0;
	len_dest = count_len(dest);
	len_src = count_len(src);
	if (len_dest >= size)
		return (len_src + size);
	while (i < size - len_dest - 1 && src[i] != '\0')
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
