/*
 * @file
 * Main program file.
 */

// C11 standard headers.
#include <stdlib.h>
#include <stdio.h>
#include <stdalign.h>
#include <stddef.h>
#include <stdint.h>

// GNU C Library headers.
#include <unistd.h>

// Example program headers.
#include "utility.h"

void recurse() {
	recurse();
}

/**
 * Program entry point.
 *
 * @see https://en.cppreference.com/w/c/language/main_function
 */
int main (int argc, char *argv[]) {
	printf("This GNU Autotools skeleton project works!\n\n");


	for (int i = 0; i < 64; i++) {
		if (i % 2 == 0)
			printf("a");
		else
			printf("b");
	}
	printf("\n");

	uint_least64_t t = 0;
	t = ~t;
	printf("%zX\n", t);
	printf("%s\n", format_size_t(t));

	uint_least64_t sz = 1024*1024 * 68;

	printf("Allocating %s sized character array.\n", format_size_t(sz));

	return EXIT_SUCCESS;

	char *buffer = (char *) malloc(sz * sizeof(char));

	buffer[sz-1] = 'a';

	sleep(5);

	free(buffer);

	// recurse();

	typedef struct T T;
	struct T {
		char 	a; // 1
		int 	b; // 4
		double  c; // 8
				   // total unpadded:
				   // 13
	};

	printf("Size of      [T]: %zu\n", sizeof(T));
	printf("Alignment of [T]: %zu\n", alignof(T));

	printf("Alignment of [char]: %zu\n", alignof(char));
	printf("Alignment of [int]: %zu\n", alignof(int));
	printf("Alignment of [long]: %zu\n", alignof(long));
	printf("Alignment of [float]: %zu\n", alignof(float));
	printf("Alignment of [double]: %zu\n", alignof(double));
	printf("Alignment of [void*]: %zu\n", alignof(void*));

	T x = {'a', 1024, 1.23456789e10};

	printf(
		"Offset [T.a]: %zu\n" \
		"Offset [T.b]: %zu\n" \
		"Offset [T.c]: %zu\n",
		offsetof(T, a),
		offsetof(T, b),
		offsetof(T, c)
	);

	printf(
		"Address [T.a]: %p\n" \
		"Address [T.b]: %p\n" \
		"Address [T.c]: %p\n",
		&x.a,
		&x.b,
		&x.c
	);

	// Silly way of setting the value of T.b to 7. Works only for little-endian.
	char *p = &x.a;
	p += 4;
	*p = 7; p++;
	*p = 0; p++;
	*p = 0; p++;
	*p = 0;

	printf(
		"Value [T.a]: %c\n" \
		"Value [T.b]: %d\n" \
		"Value [T.c]: %.4e\n",
		x.a,
		x.b,
		x.c
	);

	return EXIT_SUCCESS;
}
