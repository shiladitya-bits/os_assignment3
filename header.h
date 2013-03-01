#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
extern void executecmds(char **a,char **b,int len1,int len2);
extern void executesingle(char **,int);

