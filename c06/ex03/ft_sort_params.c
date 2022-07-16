/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <hayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:58:45 by hayou             #+#    #+#             */
/*   Updated: 2022/04/27 16:08:17 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i ++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	return (s1[i] - s2[i]);
}

void	ft_putstr(char **str, int num)
{
	int	idx;
	int	i;

	i = 1;
	while (i < num)
	{
		idx = 0;
		while (str[i][idx])
		{
			write(1, &str[i][idx], 1);
			idx++;
		}
		write(1, "\n", 1);
		i ++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (i < argc)
	{
		j = 1;
		while (j < argc - i - 1)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				str = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = str;
			}
			j++;
		}
		i ++;
	}
	ft_putstr(argv, argc);
	return (0);
}
