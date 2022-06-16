#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIMS " \t\r\n\a"

extern char **environ;

/* memory management functions */
void _memcpy(void *newptr, const void *oldptr, unsigned int size);
void *_realloc(void *oldptr, unsigned int oldsize, unsigned int newsize);
char **grid_realloc(char **oldptr, unsigned int oldsize, unsigned int newsize);

/* string manipulation functions */
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_concatpath(char *pathdir, char *str);

/* split functions */
int is_delim(char c, char *delim);
char *_strtok(char *str, char *delim);
char **split_string(char *str);

/* env functions */
char *getfullenv(char *var_name);
char *_getenv(char *name);
char **getpathdirs(char *path_val);

/* print functions */
int _putchar(char c);
void _puts(char *str);

/* builtin functions */
int print_env(void);
int builtincheck(char **av, char *line, char **pathdirs, int exitstatus);

/* program flow functions */
void prompt(void);
char *read_line(void);
char *fullpath(char **av, char **pathdirs);
int _launch(char **av, char *fullpath);

#endif
