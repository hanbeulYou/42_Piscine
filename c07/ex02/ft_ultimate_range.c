/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <hayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 23:31:12 by hayou             #+#    #+#             */
/*   Updated: 2022/04/29 19:31:58 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long	size;
	long long	i;

	i = 0;
	if (min >= max)
		return (0);
	size = max - min;
	*range = (int *)malloc(sizeof(int) * size);
	if (range == 0)
		return (-1);
	while (i < size)
	{
		range[0][i] = min + i;
		i ++;
	}
	return (size);
}
/*
#include <stdio.h>
int main()
{
    printf("-------ex02-------\n\n");
    int	*ex02_arr1;
    int	*ex02_arr2;
    int	*ex02_arr3;
	int size1 = ft_ultimate_range(&ex02_arr1, 5, 10);
    int size2 = ft_ultimate_range(&ex02_arr2, -4, 10);
    int size3 = ft_ultimate_range(&ex02_arr3, 10, 1);
    
    printf("min : 5, max : 10, size : %d\n", size1);
	for (int i = 0; i < size1 ; i++)
	{
		printf("%d ", ex02_arr1[i]);
	}
    printf("\n\n");
    printf("min : -4, max : 10, size : %d\n", size2);
	for (int i = 0; i < size2 ; i++)
	{
		printf("%d ", ex02_arr2[i]);
	}
    printf("\n\n");
    printf("min : 10, max : 1, size : %d\n", size3);
	printf("%p ", ex02_arr3);
    printf("\n\n");
    free(ex02_arr1);
    free(ex02_arr2);
    free(ex02_arr3);
}*/
