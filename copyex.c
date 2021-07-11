//CODE TO TAKE INPUT WRITE IT TO SOURCE FILE THEN COPY IT TO THE DESTINATION FILE
//GIVE STRING WITHOUT SPACES FOR INPUT.
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
void main()
{
int fds,fdd,sz,n;
char s[100];
char *ctemp=(char *)calloc(100,sizeof(char));
fdd=creat("des.txt",0777);
fds=open("src.txt",O_WRONLY|O_CREAT,0777);
printf("Enter string: ");
scanf("%s",s);
sz=write(fds,s,strlen(s));
printf("sz=%d\n",sz);
fds=open("src.txt",O_RDONLY|O_APPEND,0777);
sz=read(fds,ctemp,100);
fdd=open("des.txt",O_WRONLY);
ctemp[sz]='\0';
sz=write(fdd,ctemp,strlen(ctemp));
printf("sz=%d\n",sz);
printf("CONTENTS COPIED\n");
printf("SOURCE FILE: ");
fds=open("src.txt",O_RDONLY);
sz=read(fds,ctemp,100);
printf("sz=%d\n",sz);
printf("fds=%d\n",fds);
ctemp[sz]='\0';
printf("%s\n",ctemp);
printf("DESTINATION FILE: ");
fds=open("des.txt",O_RDONLY);
sz=read(fds,ctemp,100);
printf("sz=%d\n",sz);
printf("fds=%d\n",fdd);
ctemp[sz]='\0';
printf("%s\n",ctemp);
close(fdd);
close(fds);
}
