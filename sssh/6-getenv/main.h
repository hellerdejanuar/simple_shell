#ifndef BASH
#define BASH

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
int _strcmp(char *s1, char *s2);
int _tokcntr(char *str, char *token);
char **_getline_tok(void);
char **_token_to_av(char *str, char* separator);
char **_getline_tok(void);
char *_strconcat(char *s1, char *s2);
unsigned int _list_cntr(char **list);
int _strlen(char *s);
int _strcomp(const char *, const char *);
char *_getenv(const char *);
#endif
