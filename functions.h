#ifndef _COMMON_FUNCTIONS
    #define _COMMON_FUNCTIONS
    #ifndef _POSIX_SOURCE
        #define _POSIX_SOURCE 201304L
    #endif

/* Argument header for printf functions (cprintf(INT, INT, INT, CHAR, ...)) */
#ifndef _STDIO_H
    #include <stdio.h>
#endif
/* Argument header for variadic functions (cprintf(INT, INT, INT, CHAR, ...)) */
#ifndef _STDARG_H
    #include <stdarg.h>
#endif
/* String-munging header (strncmp_r(CHAR, CHAR, INT)) */
#ifndef _STRING_H
    #include <string.h>
#endif

/* TTY color & formating enums */
typedef enum TXT_STYLE {
    TXT_NULL = 0, 
    TXT_BOLD = 1, 
    TXT_UNDERLINE = 4
} style_t;

typedef enum FG_COLOR {
    FG_NULL = 0, 
    FG_BLACK = 30, 
    FG_RED = 31, 
    FG_GREEN = 32, 
    FG_YELLOW = 33, 
    FG_BLUE = 34, 
    FG_MAGENTA = 35, 
    FG_CYAN = 36, 
    FG_WHITE = 37
} fgcolor_t;

typedef enum BG_COLOR {
    BG_NULL = 0,
    BG_BLACK = 40,
    BG_RED = 41, 
    BG_GREEN = 42, 
    BG_YELLOW = 43, 
    BG_BLUE = 44, 
    BG_MAGENTA = 45, 
    BG_CYAN = 46, 
    BG_WHITE = 47
} bgcolor_t;

/* cprintf - Print formatted text with color */
int cprintf(fgcolor_t fg, bgcolor_t bg, style_t style, const char *format, ...);
int cfprintf(FILE *stream, fgcolor_t fg, bgcolor_t bg, style_t style, const char *format, ...);

/* strncmp_r - Compare strings from the rightmost side to n length */
int strncmp_r(const char *s1, const char *s2, int n);
#endif
