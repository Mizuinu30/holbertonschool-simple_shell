#ifndef _SHELL_
#define _SHELL_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main(int argc, char **argv, char **env);
int count_input(char *str);
int count_delims(char *str, char *del);
char *remove_new_line(char *str);
void signal_handler(int sig_id);
void open_help(void);
void print_env(char **env);
void handle_exit(char **u_tokens, char *line);
int execBuiltInCommands(char **u_tokens, char *line, char **env);
void frees_get_env(char *env_path);
void frees_tokens(char **tokens);
int exec(char *cname, char **opts, char **env);
char **tokenize(char *str, char *del, int len);
char *find(char *cname);

#endif
