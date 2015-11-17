#include "functions.h"

/**
 * cprintf, cfprintf - Print formatted text with color
 */
int cprintf(fgcolor_t fg, bgcolor_t bg, style_t style, const char *format, ...) {
    // Variable arguments list for printf
    va_list cpf_args;
    
    // Handle our printf args and print out the string
    va_start(cpf_args, format);
      // Apply console formatting (FG, BG, Style, respectively)
      if(fg > 29 && fg < 38) { printf("\033[%dm", fg); }
      if(bg > 39 && bg < 48) { printf("\033[%dm", bg); }
      if(style == 1 || style == 4) { printf("\033[%dm", style); }
      int handler = vprintf(format, cpf_args);
      // Reset console formatting
      printf("\033[0m");
    va_end(cpf_args);

    return handler;
}

int cfprintf(FILE *stream, fgcolor_t fg, bgcolor_t bg, style_t style, const char *format, ...) {
    // Variable arguments list for printf
    va_list pargs;
    
    // Handle our printf args and print out the string
    va_start(pargs, format);
      // Apply console formatting (FG, BG, Style, respectively)
      if(fg > 29 && fg < 38) { fprintf(stream, "\033[%dm", fg); }
      if(bg > 39 && bg < 48) { fprintf(stream, "\033[%dm", bg); }
      if(style == 1 || style == 4) { fprintf(stream, "\033[%dm", style); }
      int handler = vfprintf(stream, format, pargs);
      // Reset console formatting
      fprintf(stream, "\033[0m");
    va_end(pargs);

    return handler;
}

/**
 * strncmp_r - Compare strings from the rightmost side to n length
 */
int strncmp_r(const char *s1, const char *s2, int n) {
    // Set maxlength, then re-assign if second is smaller
    int s_maxlen = strlen(s1);
    if(strlen(s2) < strlen(s1)) s_maxlen = strlen(s2);
    
    // If checking length is smaller than maxlength, use that.
    if(n < s_maxlen) s_maxlen = n;
    
    // Truncate strings to maxlength, from the right.
    char sub1[s_maxlen];
    char sub2[s_maxlen];
    strncpy(sub1, &s1[strlen(s1) - s_maxlen], s_maxlen + 1);
    strncpy(sub2, &s2[strlen(s2) - s_maxlen], s_maxlen + 1);
    
    // Compare the strings
    return strcmp(sub1, sub2);
}
