#include "header.h"
void executesingle(char **arr,int i)
{
	char command[50],env[50],option[50],fullcom[80];	
	char env1[40] = "/bin/",env2[40] = "/sbin/",env3[40]="/usr/bin/",env4[40]="/usr/sbin/",env5[40]="/etc/";
	int opt_rows=1,opt_cols = 0,ct;
	pid_t childA,childB,cmd1,cmd2;

	sscanf(arr[i],"%s\t%s\t%[^\n]s",command,env,option);
	//if(strcmp(option,"NULL") == 0)
	//{
	//	option[0] = '\0';
	//}
	if(strcmp(env,"-") != 0)
	{
		strcat(env,"/");
		strcat(env,command);
	}
	else
	{
		strcat(env1,command);
		strcat(env2,command);
		strcat(env3,command);
		strcat(env4,command);
		strcat(env5,command);
	}
	char *args[10];
	args[0] = command;
	if(strcmp(option,"NULL")) {
	args[1] = (char *)malloc(10*sizeof(char));
	for(ct=0;option[ct]!='\0';ct++)
	{
		if(option[ct] == ' ')
		{
			args[opt_rows][opt_cols] = '\0';
			opt_rows++;
			args[opt_rows] = (char *)malloc(10*sizeof(char));
			opt_cols=0;	
			continue;
		}
		args[opt_rows][opt_cols++] = option[ct];
		
	}
	args[opt_rows][opt_cols] = '\0';
	args[opt_rows+1] = NULL;
	
	}
	else args[1] = NULL;
	//args[1] = option;
	cmd2 = fork();
	if(!cmd2)
	{
	 //	printf("-----------executing command in array at position %d-------------\n",i);
		printf("path=%s args=%s %s %s\n",env,args[0],args[1],args[2]);			
		if(strcmp(env,"-") == 0)
		{

			printf("-------%s %s----------\n",env1,args[0]);
			execv(env1,args); 
			execv(env2,args); 
			execv(env3,args);
			execv(env4,args); 
			execv(env5,args); 
		}			

		if(execv(env,args)==-1) 
			printf("execv call failed at i=%d!\n",i);
		exit(0);
	}
	else wait(NULL);
}
