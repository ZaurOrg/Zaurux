#include <sys/types.h>
void sleep(unsigned);
pid_t fork(void);
void panic(char *s);
void idle(void);
int execv(char *, char **);
int execvp(char *, char **);
int execvl(char *, char **, char **);
int execve(char *, char **, char **);
pid_t waitpid(pid_t pid, int *status, int options);
void chdir(char *path);
int mkdir(const char *path, mode_t mode);