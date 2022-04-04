#ifndef BASH
#define BASH

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int _strcmp(char *s1, char *s2);
int _tokcntr(char *str, char *token);
char **_getline_tok(void);
char **_token_to_av(char *str, char* separator);
#endif
