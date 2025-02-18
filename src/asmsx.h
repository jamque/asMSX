#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <assert.h>
#include <stdint.h>
#include <unistd.h>
#include <libgen.h>
#include <sys/stat.h>

#ifndef PATH_MAX
#ifdef WIN32
#define PATH_MAX (_MAX_PATH)
#else
#include <limits.h>
#endif
#endif


// Our modules
#include "types.h"
#include "labels.h"

/* rom type */
#define Z80 0
#define ROM 1
#define BASIC 2
#define MSXDOS 3
#define MEGAROM 4
#define SINCLAIR 5

/* mapper type */
#define KONAMI 0
#define KONAMISCC 1
#define ASCII8 2
#define ASCII16 3

/* MSX tape file name length */
#define FNAME_MSX_LEN 6


/* Globals */ //TODO: All globals must be removed in the future
extern char verbose, zilog;

extern char* fname_src;
extern int pass, lines;

extern char error_buffer[124];

/* function declarations */
extern void write_tape(const int, const char *, const char *, const int, const int, const int, const int, const char *);
int d_rand(void);
extern char* safe_strcat(char* dest, char* orig, unsigned int max_size, char* fname_src, int lines);
extern void error_message(int n, char* fname_src, int lines);
extern void warning_message(int n, char* fname_src, int lines, int pass, int* warnings);
extern char* replaceWord(const char* s, const char* oldW, const char* newW, int* count); 
extern int isDirectory(const char *path);
