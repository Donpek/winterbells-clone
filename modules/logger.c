#include "logger.h"
//
void logger_init(){
  logger = fopen(LOGGER_FILENAME, LOGGER_MODE);
  fprintf(logger, "[INNER] Logger opened.\n");
}
void log_debug(char *message){
  fprintf(logger, "[DEBUG] %s\n", message);
}
void log_error_SDL(char *message){
  fprintf(logger, "[ERROR] %s: %s.\n", message, SDL_GetError());
}
// void log_error_TTF(char *message){
//   fprintf(logger, "[ERROR] %s: %s.\n", message, TTF_GetError());
// }
void logger_quit(){
  fprintf(logger, "[INNER] Logger closed.\n");
  fclose(logger);
}
