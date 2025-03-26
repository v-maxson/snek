#ifndef SNEK_CLI_H
#define SNEK_CLI_H

#define ARGP_REQUIRED_ARG_COUNT 0

#define SNEK_DEFAULT_WIDTH 20
#define SNEK_DEFAULT_HEIGHT 20

typedef struct snek_cli_args {
	char *args[ARGP_REQUIRED_ARG_COUNT];
	int width;
	int height;
} snek_cli_args;

snek_cli_args snek_cli_parse(int argc, char *argv[]);

#endif
