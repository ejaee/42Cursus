#include <stdio.h>

int	main()
{
	printf("\n----- d -----\n");

	printf("%d\n", 2147483647);
	// printf("%d\n", 2147483648); -> ld
	
	printf("\n----- i -----\n");

	printf("%i\n", 2147483647);
	// printf("%i\n", 2147483648); -> li
	
	printf("\n----- u -----\n");

	printf("%u\n", 2147483647);

	unsigned int a = 4294967295;
	unsigned int b = -4294967294;
	printf("%u\n", a);
	printf("%u\n", b);
	
	printf("%u\n", -1); // underflow
	printf("%u\n", -2147483647); // underflow
								 
	printf("\n----- X -----\n");

	printf("%X\n", 10);
	printf("%X\n", 15);
	printf("%X\n", 2147483647);

	printf("%X\n", -10);
	printf("%X\n", -15);
	printf("%X\n", -2147483646);
	printf("%X\n", -2147483647);
	printf("%X\n", a);

								 
	printf("\n----- x -----\n");

	printf("%x\n", 10);
	printf("%x\n", 15);
	printf("%x\n", 2147483647);

	printf("%x\n", -10);
	printf("%x\n", -15);
	printf("%x\n", -2147483646);
	printf("%x\n", -2147483647);
	// printf("%x\n", 2147483648); -> lX
	
	printf("\n----- test empty -----\n%d\n%s\n%d\n", 1, "\0", 1);

	printf("\n===== test empty =====\n%s", NULL);

}
