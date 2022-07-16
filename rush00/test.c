/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:36:40 by hayou             #+#    #+#             */
/*   Updated: 2022/04/16 22:43:25 by hayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

// char형의 문자를 출력하는 함수입니다.
void	ft_putchar(char c)
{
	write(1, &c, 1);
}


// 0번째 줄 & 마지막 줄의 모양을 출력하는 함수입니다. 
// x값을 변수로 받아 while 함수를 사용해 가로 길이에 맞게 출력합니다.
// 맨 처음과 마지막은 'o' 문자를, 가운데는 '-' 문자를 출력하도록 if 문을 사용했습니다.
// 출력을 마치면 줄바꿈(\n)을 붙여주어서 다음 줄로 넘어갑니다.
void	ft_firstline(int x)
{
	int i;

	i = 0;
	while(i < x)
	{
		if(i == 0 || i == x - 1)
		{
			ft_putchar('o');
		}
		else
		{
			ft_putchar('-');
		}
		i++;
	}
	ft_putchar('\n');
}


// 0번째 줄 & 마지막 줄을 제외한 나머지 줄의 모양을 출력하는 함수입니다.
// 맨 처음과 마지막은 '|' 문자를, 가운데는 ' ' 공백 처리하도록 if 문을 사용했습니다.
// 출력을 마치면 줄바꿈(\n)을 붙여주어서 다음 줄로 넘어갑니다.
void	ft_otherline(int x)
{
	int i;

	i = 0;
	while(i < x)
	{
		if(i == 0 || i == x - 1)
		{
			ft_putchar('|');
		}
		else
		{
			ft_putchar(' ');
		}
		i++;
	}
	ft_putchar('\n');
}


// 사실상 메인 함수인 rush 함수입니다. 
// 문제에서 주어졌듯이 x, y값을 변수로 받아 가로 x, 세로 y의 크기를 갖는 박스?를 출력합니다.
// x, y 값은 정수 값을 받으므로, 상자를 그릴 수 없는 0과 음수값에 대한 예외처리를 해주었습니다.
// while 문을 통해 0 ~ y-1 번째 줄을 출력합니다. 이 때 각 줄에 맞는 함수를 호출해 각 줄을 출력합니다.
// 맨 처음 줄과 마지막 줄은 ft_firstline이라는 함수를, 가운데는 ft_otherlines라는 함수를 통해 출력합니다.
void	rush(int x, int y)
{
	int line;

	line = 0;
	if(x < 1 || y < 1)
	{
		write(1, "ERROR!\n", 7);
		return ;
	}
	while(line < y)
	{
		if(line == 0 || line == y - 1)
		{
			ft_firstline(x);
		}
		else
		{
			ft_otherline(x);
		}
		line++ ;
	}
}

// main 함수입니다. rush에 주어진 x, y를 입력하는 역할을 합니다.
int	main(void)
{
	rush(5, 3);
	rush(0, 2);
	rush(1, 0);
	rush(1, -2);
	rush(-1, -2);
	rush(1,2);
	rush(2, 2);
	return (0);
}
