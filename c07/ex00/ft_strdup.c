/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <hayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 22:52:21 by hayou             #+#    #+#             */
/*   Updated: 2022/04/29 19:31:24 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dest;

	len = 0;
	while (src[len])
		len ++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i ++;
	}
	dest[len] = 0;
	return (dest);
}
/*
#include <stdio.h>
int main()
{
    //ex00
    printf("-------ex00-------\n\n");
    char ex00_src[] = "hello my name is hunpark!";

    printf("src : %s\n", ex00_src);
    printf("strdup : %s\n\n", ft_strdup(ex00_src));
    free(ft_strdup(ex00_src));
}*/
