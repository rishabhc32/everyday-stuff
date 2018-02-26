// Reference: https://www.cprogramming.com/tutorial/function-pointers.html

#include <stdio.h>

long int add(int x, int y ) {
	return x+y;
}

int main() {
	long int (*add_pointer)(int, int) = NULL;

	add_pointer = &add;
	printf("%ld\n", add_pointer(2,3));

	add_pointer = add;
	printf("%ld\n", add_pointer(4,5));

	return 0;
}
