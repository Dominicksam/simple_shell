#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

int call_cd(char *input);
int _env1(char *env_name, char *env_value);
int _unenv(char *env_name);
int env(void);
int environ_cmd(char *input);
int input_env(char *str);
int handle_cd(char *input, char *input_dup);
void _exit_status(char *input);
extern char **environ;
char *_strdup(char *str);
int no_input(char *input);
int write_str(char *str);
unsigned int _strcmp(char *str1, char *str2);
unsigned int _strlen(const char *str);
int compare_path(char *str);
int input_cd(char *str);
char *_strcat(char *src, char *dest);
int _fork(char *input, char *token, int arg_size);
int _fork_proc(char *str, char *str1, char *token);
int _atoi(char *str);

#endif
