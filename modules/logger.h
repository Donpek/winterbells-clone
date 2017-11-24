#ifndef LOGGER
#define LOGGER
//
#include "graphics.h"
#include <stdio.h>
#include <SDL.h>
//
FILE *logger;
//
#define LOGGER_FILENAME "log.txt"
#define LOGGER_MODE "w"
//
void logger_init();
void log_debug(char *message);
void log_error_SDL(char *message);
void log_error_TTF(char *message);
void logger_quit();
//
#endif
