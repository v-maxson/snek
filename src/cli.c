#include "cli.h"
#include "version.h"

#include <argp.h>
#include <stdlib.h>

const char *argp_program_version = "snek v" SNEK_VERSION_STRING;
const char *argp_program_bug_address = SNEK_REPO_URL "/issues";
static char doc[] = "snek - A snake clone written in C.";

static struct argp_option options[] = {
	{ "width", 'w', "WIDTH", 0, "Width of the game board. Default: 20" },
	{ "height", 'h', "HEIGHT", 0, "Height of the game board. Default: 20" },
	{ 0 }
};

static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
	snek_cli_args *args = state->input;

	switch (key) {
	case 'w':
		args->width = (int)strtol(arg, &arg, 10);
		break;
	case 'h':
		args->height = (int)strtol(arg, &arg, 10);
		break;

	case ARGP_KEY_ARG:
		if (state->arg_num >= ARGP_REQUIRED_ARG_COUNT)
			argp_usage(state);
		args->args[state->arg_num] = arg;
		break;
	case ARGP_KEY_END:
		if (state->arg_num < ARGP_REQUIRED_ARG_COUNT)
			argp_usage(state);
		break;
	default:
		return ARGP_ERR_UNKNOWN;
	}

	return 0;
}

static struct argp argp = { options, parse_opt, 0, doc };

snek_cli_args snek_cli_parse(int argc, char *argv[])
{
	snek_cli_args args;
	args.width = SNEK_DEFAULT_WIDTH;
	args.height = SNEK_DEFAULT_HEIGHT;

	argp_parse(&argp, argc, argv, 0, 0, &args);
	return args;
}