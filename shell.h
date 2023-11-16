#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

typedef struct
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

extern char **environ;

void prompt_display(void);
void dm_print(const char *text);
void read_command(char *command, size_t size, FILE *file);
int execute_command(const char *command);
void dm_print_int(int value);
int interactive(info_t *info);
int is_delim(char c, char *delim);
int _isalpha(int c);
int my_setenv(const char *name, const char *value, int overwrite);
int my_unsetenv(const char *name);

#endif

