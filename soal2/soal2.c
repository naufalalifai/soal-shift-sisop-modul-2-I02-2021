#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main() {
    pid_t child_id;
    int status;

    child_id = fork();

    if(child_id < 0) {
        exit(EXIT_FAILURE);
    }
    if(child_id == 0) {
        pid_t childchild = fork();

        if(childchild < 0) {
            exit(EXIT_FAILURE); 
        }
        if(childchild == 0) {
            char *argv[] = {"mkdir", "-p", "/home/alifai/modul2/petshop", NULL};
            execv("/bin/mkdir", argv);
        }
        sleep(1);
	childchild = fork();
	if(childchild == 0) {
		char *argv[] = {"unzip","/home/alifai/Downloads/pets.zip", "-d" , "/home/alifai/modul2/petshop", NULL};
                execv("/usr/bin/unzip", argv);
	}
    }

    while((wait(&status)) > 0);
    pid_t child_id1 = fork();
    if(child_id1 < 0) {
        exit(EXIT_FAILURE); 
    }
    if(child_id1 == 0) {
        DIR *dir;
        struct dirent *input;
        dir = opendir("/home/alifai/modul2/petshop");
        while((input = readdir(dir)) != NULL) {
            char folder_name[1000];
            sprintf(folder_name, "/home/alifai/modul2/petshop/%s", input->d_name);
            if(strcmp(input->d_name, ".") == 0 || strcmp(input->d_name, "..") == 0){
                continue;
            }
            else if(input->d_type == DT_DIR) {
                pid_t childchild = fork();
                if(childchild < 0) {
                    exit(EXIT_FAILURE); 
                }
                if(childchild == 0) {
                    char *argv[] = {"rm", "-rf" , folder_name , NULL};
                    execv("/bin/rm", argv);
                }
            }
        }
    }

    while((wait(&status)) > 0);
    pid_t child_id2 = fork();
    if(child_id2 == 0) {
        DIR *dir2;
        struct dirent *input;
        dir2 = opendir("/home/alifai/modul2/petshop");
        while((input = readdir(dir2)) != NULL) {
            char folder_name[1000];
            if(strcmp(input->d_name, ".") == 0 || strcmp(input->d_name, "..") == 0){
                continue;
            }
            strcpy(folder_name, "/home/alifai/modul2/petshop/");
            strcat(folder_name, strtok(input->d_name, ";"));
            pid_t childchild = fork();
            
            if(childchild == 0) {
                char *argv[] = {"mkdir", "-p", folder_name, NULL};
                execv("/bin/mkdir", argv);
            }
        }
    }
}
