#include <stdio.h>

int	main(){
	int z = printf("z : %d\n", 42);
	int t = printf("t : %1d\n", 42);	//	ignored width
	int a = printf("a : %30d\n", 42);  //	fail
	int b = printf("b : %2147483648d\n", 42); //	width = 0
	int bb = printf("b : %-2147483649d\n", 42); //	width = 0
	int c = printf("c : %9223372036854775809d\n", 42); //	width = 0
	int d = printf("d : %*d\n", 2147483647, 42);

	printf("\n\n---check---\n\n");

	printf("z : %d\n", z);
	printf("t : %d\n", t);
	printf("a : %d\n", a);
	printf("b : %d\n", b);
	printf("c : %d\n", c);
	printf("d : %d\n", d);

	printf("\n\n---width check---\n\n");

	int width = 1;

	for (int	i = 1; i < 8; width *= 2, i++)
		printf("%*d\n", width, i);

	printf("%30d\n", 42);
	printf("%9223372036854775808d\n", 42);
	printf("%9223372036854775809d\n", 42);
}
