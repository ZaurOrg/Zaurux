
typedef int pid_t;
typedef void panic_t;
void sleep(unsigned);
pid_t fork(void);
panic_t panic(char *s);
void idle(void);
void execvp(void);