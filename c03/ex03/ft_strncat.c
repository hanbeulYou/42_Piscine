/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 22:39:05 by hayou             #+#    #+#             */
/*   Updated: 2022/04/21 19:26:29 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	len;
	unsigned int	i;

	len = 0;
	i = 0;
	while (dest[len])
		len ++;
	while (i < nb)
	{
		if (src[i] != '\0')
		{
			dest[len + i] = src[i];
		}
		else
			break ;
		i ++;
	}
	dest[len + i] = '\0';
	return (dest);
}
