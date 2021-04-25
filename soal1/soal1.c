
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <wait.h>

time_t my_time;
struct tm * timeinfo;

int date(int surp){
    int hour = 21;
    if(surp == 1) hour = 21-6;

    time (&my_time);
    timeinfo = localtime (&my_time);
    if(timeinfo->tm_mday == 25 && timeinfo->tm_mon == 4 && timeinfo->tm_hour == hour && timeinfo->tm_min == 02){
    return 1; }
return 0;
}

void execute(char **args){
int pid = fork();
int status;
if(pid == 0)
{
execvp(args[0],args);
}
while(wait(&status) > 0);
}


int main(){

char *folder[3] = {"Musyik/", "Fyim/", "Pyoto/"};
char *link[3] = {"https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download","https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download","https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download"};
char *zipfiles[3] = {"Musyik.zip","Fyim.zip","Pyoto.zip"};

int download = 0;
int zipfile = 0;

pid_t pid, sid;
pid = fork();

if(pid < 0)
exit(EXIT_FAILURE);

if(pid > 0)
exit(EXIT_SUCCESS);

umask(0);

sid=setsid();

if(sid < 0)
exit(EXIT_FAILURE);

if((chdir("/home/drigo/Desktop/modul2")) < 0)
exit(EXIT_FAILURE);

close(STDIN_FILENO);
close(STDOUT_FILENO);
close(STDERR_FILENO);

while(1){
if(date(1) && download == 0){
for(int i = 0 ; i < 3 ; i++){
char *args[] = {"mkdir", folder[i], NULL};
execv("/bin/mkdir",args);
}

for(int j = 0 ; j < 3 ; j++){
if(fork() == 0){
char *argv[] = {"wget","-q","--no-check-certificate",link[j],"-O",zipfiles[j],NULL};
execv("/bin/wget",argv);
}
}

for(int i = 0 ; i < 3 ; i++){
int status;
pid_t pid = wait(&status);
waitpid(pid, &status, WUNTRACED);
}

for(int j = 0 ; j < 3 ; j++){
if(fork() == 0){
char *argv[] = {"unzip","-q",zipfiles[j],"-d","",NULL};
execv("/bin/unzip",argv);
}
}

for(int j = 0 ; j < 3 ; j++){
int status;
pid_t pid = wait(&status);
waitpid(pid, &status, WUNTRACED);
}

download ++;
}

if(date(0) && zipfile == 0){
if(1){
char *args[] = {"zip","-r", "Lopyu_Stevany",folder[0],folder[1],folder[2],NULL};
execute(args);
}
zipfile ++;
}

if(download && zipfile){
exit(EXIT_FAILURE);
}
sleep(1);
}
return 0;
}#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <wait.h>

time_t my_time;
struct tm * timeinfo;

int date(int surp){
    int hour = 21;
    if(surp == 1) hour = 21-6;

    time (&my_time);
    timeinfo = localtime (&my_time);
    if(timeinfo->tm_mday == 25 && timeinfo->tm_mon == 4 && timeinfo->tm_hour == hour && timeinfo->tm_min == 02){
    return 1; }
return 0;
}

void execute(char **args){
int pid = fork();
int status;
if(pid == 0)
{
execvp(args[0],args);
}
while(wait(&status) > 0);
}


int main(){

char *folder[3] = {"Musyik/", "Fyim/", "Pyoto/"};
char *link[3] = {"https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download","https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download","https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download"};
char *zipfiles[3] = {"Musyik.zip","Fyim.zip","Pyoto.zip"};

int download = 0;
int zipfile = 0;

pid_t pid, sid;
pid = fork();

if(pid < 0)
exit(EXIT_FAILURE);

if(pid > 0)
exit(EXIT_SUCCESS);

umask(0);

sid=setsid();

if(sid < 0)
exit(EXIT_FAILURE);

if((chdir("/home/drigo/Desktop/modul2")) < 0)
exit(EXIT_FAILURE);

close(STDIN_FILENO);
close(STDOUT_FILENO);
close(STDERR_FILENO);

while(1){
if(date(1) && download == 0){
for(int i = 0 ; i < 3 ; i++){
char *args[] = {"mkdir", folder[i], NULL};
execv("/bin/mkdir",args);
}

for(int j = 0 ; j < 3 ; j++){
if(fork() == 0){
char *argv[] = {"wget","-q","--no-check-certificate",link[j],"-O",zipfiles[j],NULL};
execv("/bin/wget",argv);
}
}

for(int i = 0 ; i < 3 ; i++){
int status;
pid_t pid = wait(&status);
waitpid(pid, &status, WUNTRACED);
}

for(int j = 0 ; j < 3 ; j++){
if(fork() == 0){
char *argv[] = {"unzip","-q",zipfiles[j],"-d","",NULL};
execv("/bin/unzip",argv);
}
}

for(int j = 0 ; j < 3 ; j++){
int status;
pid_t pid = wait(&status);
waitpid(pid, &status, WUNTRACED);
}

download ++;
}

if(date(0) && zipfile == 0){
if(1){
char *args[] = {"zip","-r", "Lopyu_Stevany",folder[0],folder[1],folder[2],NULL};
execute(args);
}
zipfile ++;
}

if(download && zipfile){
exit(EXIT_FAILURE);
}
sleep(1);
}
return 0;
}
