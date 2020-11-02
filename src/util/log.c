#include "log.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>

void loge(const char *format, ...)
{
  FILE *f;
  va_list ap;
  char out[512];

  time_t t = time(NULL);
  struct tm tm = {0};
  char *after_date = &out[21];

  tm = *localtime(&t);

  strftime(out, 22, "[%Y-%m-%d:%H:%M:%S]", &tm);
  strcpy(after_date, "[ERROR]");

  f = fopen("session.log", "a");

  va_start(ap, format);
  vsprintf(after_date + 8, format, ap);
  va_end(ap);

  out[28] = ' ';

  fprintf(stdout, "%s\n", out);
  fprintf(f, "%s\n", out);

  fclose(f);
}

void logi(const char *format, ...)
{
  FILE *f;
  va_list ap;
  char out[512];

  time_t t = time(NULL);
  struct tm tm = {0};
  char *after_date = &out[21];

  tm = *localtime(&t);

  strftime(out, 22, "[%Y-%m-%d:%H:%M:%S]", &tm);
  strcpy(after_date, "[INFO]");

  f = fopen("session.log", "a");

  va_start(ap, format);
  vsprintf(after_date + 7, format, ap);
  va_end(ap);

  out[27] = ' ';

  fprintf(stdout, "%s\n", out);
  fprintf(f, "%s\n", out);

  fclose(f);
}
