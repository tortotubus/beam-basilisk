# 2 "ast/defaults.h"

/**
# Default variables/function declarations 

So that we can avoid parsing system libraries (maybe we should just do it...)

A list of declarations can be generated using something like

~~~bash
grep -o '‘.*’' /tmp/errors | sort | uniq | sed 's/[‘’]//g' > /tmp/list
for f in `cat /tmp/list`; do man 3 $f | grep -m1 "$f.*;"; done 
~~~

## Type definitions */

typedef void QFILE, FILE, extrae_type_t, extrae_value_t;
typedef void MPI_Datatype, MPI_Request, MPI_Comm, MPI_Op, MPI_Aint, Node;
typedef int bool, MPI_Status;
typedef long size_t, clock_t, int64_t, uint32_t, uint16_t;
typedef void GLfloat, GLubyte;
typedef void framebuffer, fbdepth_t, Frustum;
typedef void Kdt, KdtRect, KdtSum, KdtCheck;
typedef void va_list;

/**
## From standard C libraries */

void abort(void);
int abs(int j);
int atexit(void (*function)(void));
double atof(const char *nptr);
int atoi(const char *nptr);
void *calloc(size_t nmemb, size_t size);
clock_t clock(void);
void exit(int status);
double fabs(double x);
int fclose(FILE *stream);
int fflush(FILE *stream);
int fgetc(FILE *stream);
char *fgets(char *s, int size, FILE *stream);
FILE *fopen(const char *pathname, const char *mode);
int fprintf(FILE *stream, const char *format, ...);
int fputc(int c, FILE *stream);
int fputs(const char *s, FILE *stream);
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
void free(void *ptr);
int fscanf(FILE *stream, const char *format, ...);
int fseek(FILE *stream, long offset, int whence);
long ftell(FILE *stream);
char *getenv(const char *name);
void *malloc(size_t size);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
int pclose(FILE *stream);
void perror(const char *s);
FILE *popen(const char *command, const char *type);
double pow(double x, double y);
int printf(const char *format, ...);
void qsort(void *base, size_t nmemb, size_t size,
	   int (*compar)(const void *, const void *));
int rand (void);
int rename(const char *oldpath, const char *newpath);
void srand (unsigned int seed);
void *realloc(void *ptr, size_t size);
int remove(const char *pathname);
int setenv(const char *name, const char *value, int overwrite);
int sigemptyset(sigset_t *set);
int snprintf(char *str, size_t size, const char *format, ...);
int sprintf(char *str, const char *format, ...);
double sqrt(double x);
int sscanf(const char *str, const char *format, ...);
extern FILE *stderr;
extern FILE *stdin;
extern FILE *stdout;
char *strcat(char *dest, const char *src);
char *strchr(const char *s, int c);
int strcmp(const char *s1, const char *s2);
char *strcpy(char *dest, const char *src);
char *strdup(const char *s);
size_t strlen(const char *s);
char *strncpy(char *dest, const char *src, size_t n);
char *strstr(const char *haystack, const char *needle);
char *strtok(char *str, const char *delim);
int system(const char *command);

/**
## Tricks for AST

The following are declarations semantically equivalent to their real
implementations (which are often C preprocessor macros). */

enum AstBoolean { false, true };
const void * NULL;
void *sysmalloc(size_t size);
void *syscalloc(size_t nmemb, size_t size);
void *sysrealloc(void *ptr, size_t size);
void sysfree(void *ptr);
char *systrdup(const char *s);
int npe(), pid();
extern FILE *sysstderr;
extern FILE *sysstdin;
extern FILE *sysstdout;
