#include <stdio.h>
#include "HelloWorldConfig.h"

int main(int argc, char *argv[]) {
	if (argc < 2 || argc > 2) {
		fprintf(stdout, "%s version %d.%d\n",
			argv[0],
			HelloWorld_VERSION_MAJOR,
			HelloWorld_VERSION_MINOR);
		fprintf(stdout, "Usage: %s name\n",argv[0]);
		return 1;
	}

	fprintf(stdout, "Hello %s!\n",argv[1]);
	return 0;
}