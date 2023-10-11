#ifndef _SHELL_H_
#define _SHELL_H_
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*==================================================*/
/*============     Shell_Init       ==============*/
/*==================================================*/

int main(int ac, char **av, char **env);
void prompt(void);
void handle(int signals);
void _EOF(char *buffer);
void shell_exit(char **func);

/*==================================================*/
/*============     create_child       ==============*/
/*==================================================*/

void create_child(char **func, char *name, char **env, int circle);
int change_dir(const char *path);

/*==================================================*/
/*============        Execute       ==============*/
/*==================================================*/

void execute(char **func, char *name, char **env, int circle);
void print_env(char **env);
char **_get_path(char **env);
void msgerror(char *name, int circle, char **func);

/*==================================================*/
/*============          token      ==============*/
/*==================================================*/

char **token(char *buffer, const char *s);

/*==================================================*/
/*============     Free Memory      ==============*/
/*==================================================*/

void free_dp(char **func);
void free_exit(char **func);

/*==================================================*/
/*============  sec_Functions    ==============*/
/*==================================================*/

int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _stringint(char *s);
char *_strcat(char *dest, char *src);

/*==================================================*/
/*============  write    ==============*/
/*==================================================*/

int _putchar(char c);
int _printstring(char *str);

/*==================================================*/
/*============  build    ==============*/
/*==================================================*/
extern char **environ;
void exits(char **func);
void env(char **func __attribute__ ((unused)));
void _setenv(char **func);
char *_getenv(const char *name);
char *_strcat_all(char *name, char *sep, char *value);

/**
 * struct mybuild - pointer to function with corresponding buildin command
 * @name: buildin command
 * @func: execute the buildin command
 */
typedef struct mybuild
{
	char *name;
	void (*func)(char **);
} mybuild;

/*==================================================*/
/*============  build_cunt    ==============*/
/*==================================================*/

void _unsetenv(char **arv);
void(*checkbuild(char **func))(char **func);
void _echo(void);
void _echo_zero(void);
void _echo_path(void);

/*============ END      ==============*/

#endif /* _SHELL_H_ */
