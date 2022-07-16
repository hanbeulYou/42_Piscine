#include <stdio.h>
#include <stdlib.h>

#include "./ex00/ft_iterative_factorial.c"
#include "./ex01/ft_recursive_factorial.c"
#include "./ex02/ft_iterative_power.c"
#include "./ex03/ft_recursive_power.c"
#include "./ex04/ft_fibonacci.c"
#include "./ex05/ft_sqrt.c"
#include "./ex06/ft_is_prime.c"
#include "./ex07/ft_find_next_prime.c"

int main(int argc, char **argv)
{
	if(argc == 1)
		return (0);

	int n = atoi(argv[1]);
/*	printf("Ex 00\n");
	printf("%d! = %d\n\n", n, ft_iterative_factorial(n));

	printf("Ex 01\n");
	printf("%d! = %d\n\n", n, ft_recursive_factorial(n));

	int p = atoi(argv[2]);
	printf("Ex 02\n");
	printf("%d^%d = %d\n\n", n, p, ft_iterative_power(n, p));

	printf("Ex 03\n");
	printf("%d^%d = %d\n\n", n, p, ft_recursive_power(n, p));

	printf("Ex 04\n");
	printf("Fibonacci(%d) : = %d\n\n", n, ft_fibonacci(n));
*/
	printf("Ex 05\n");
	printf("Does (%d) have a Square Root? : %d\n\n", n, ft_sqrt(n));

	printf("Ex 06\n");
	printf("Is (%d) a Prime Number? : %d\n\n", n, ft_is_prime(n));

	printf("Ex 07\n");
	printf("The next Prime Number of (%d) is : %d\n\n", n, ft_find_next_prime(n));
	return (0);
}
