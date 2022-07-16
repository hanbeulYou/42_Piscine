/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:25:50 by hayou             #+#    #+#             */
/*   Updated: 2022/04/27 21:42:14 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len ++;
	while (i + 1 < size)
	{
		if (src[i] != '\0')
			dest[i] = src[i];
		else
			break ;
		i ++;
	}
	dest[i] = '\0';
	return (len);
}
