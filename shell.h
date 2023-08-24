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

extern char **environ;

char *strcat(char *dest, char *src);
int strlen(const char *s);
int strcmp(char *s1, char *s2);
int strncmp(const char *s1, const char *s2, size_t len);
char *strdup(char *str);
int atoi(char *s);
int putchar(char c);
void puts(char *str);
void *realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int count_input(char *str);
int count_delims(char *str, char *del);
char *remove_new_line(char *str);
void signal_handler(int sig_id);
void open_help(void);
void print_env(void);
void handle_exit(char **u_tokens, char *line);
int execBuiltInCommands(char **u_tokens, char *line);
void frees_get_env(char *env_path);
void frees_tokens(char **tokens);
int exec(char *cname, char **opts);
char *getenv(const char *name);
char **tokenize(char *str, char *del, int len);
char *find(char *cname);

#endif
