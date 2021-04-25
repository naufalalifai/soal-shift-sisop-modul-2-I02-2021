# soal-shift-sisop-modul-2-I02-2021

## Member's Name
- Muhammad Naufal Alif Islami (05111942000008)
- Drigo Alexander SIhombing (05111942000020)
- Fitriana Zahirah Tsabit (05111942000011)

## Question 1:

## Question 2:
Loba works in a famous pet shop, one day he got a zip containing lots of pets photos and he was ordered to categorize the photos of these pets. Loba finds it difficult to do his work manually, moreover there is the possibility that he will be ordered to do the same thing multiple times. You are Loba's best friend and he is asking for your help to help with his work. 

a)	First, the program needs to extract the given zip into the folder “/home/[user]/modul2/petshop”. Because Loba's boss is careless, the zip may contain unimportant folders, so the program must be able to distinguish between files and folders so that it can process files that should be worked on and delete unnecessary folders.

First, make petshop folder to store the extracted zip file

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

Unzip/extract pets.zip into petshop folder  

    sleep(1);
	  childchild = fork();
	  if(childchild == 0) {
		char *argv[] = {"unzip","/home/alifai/Downloads/pets.zip", "-d" , "/home/alifai/modul2/petshop", NULL};
       	execv("/usr/bin/unzip", argv);
	  }
		    
 Then, we need to delete unnecessary folders. To distinguish files and folders, we use `dirent.h` library.
 
    while((wait(&status)) > 0);
      pid_t child_id1 = fork();
      if(child_id1 < 0) {
        exit(EXIT_FAILURE); 
      }
      if(child_id1 == 0) {
        DIR *dir;
        struct dirent *input;
        dir = opendir("/home/alifai/modul2/petshop");
        
 Ignore current directory and parent directory
 
    while((input = readdir(dir)) != NULL) {
      char folder_name[1000];
      sprintf(folder_name, "/home/alifai/modul2/petshop/%s", input->d_name);
      if(strcmp(input->d_name, ".") == 0 || strcmp(input->d_name, "..") == 0){
        continue;
      }
      
Check if the file type is directory. If it is a directory, then remove the file

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

**RESULT**
![modul2_2a](https://user-images.githubusercontent.com/73649094/115986746-e8f93880-a5db-11eb-9cef-20c50b32064b.png)


b)	Pet photos need to be categorized based on the pet's species, so you will need to create a folder for each species that is in the zip file. Since you can't possibly check manually, the program needs to create the required folders according to the contents of the zip file.
Example: Cats will be stored in "/petshop/cat", turtles will be stored in "/petshop/turtle".

To create folders for each pet’s species, we use `dirent.h` library again

    while((wait(&status)) > 0);
     pid_t child_id2 = fork();
    if(child_id2 == 0) {
        DIR *dir2;
        struct dirent *input;
        dir2 = opendir("/home/alifai/modul2/petshop");
        
Ignore current directory and parent directory

    while((input = readdir(dir2)) != NULL) {
      char folder_name[1000];
      if(strcmp(input->d_name, ".") == 0 || strcmp(input->d_name, "..") == 0){
        continue;
      }
      
`strtok` : get the first token of filename string which is the pet’s species

`strcat` : concatenate result of strtok and folder_name to get the folder path of folder that we will create

    strcpy(folder_name, "/home/alifai/modul2/petshop/");
    strcat(folder_name, strtok(input->d_name, ";"));

create the folder for each species

    pid_t childchild = fork();
            
    if(childchild == 0) {
      char *argv[] = {"mkdir", "-p", folder_name, NULL};
      execv("/bin/mkdir", argv);
    }
    
**RESULT**
![modul2_2b](https://user-images.githubusercontent.com/73649094/115986878-a5eb9500-a5dc-11eb-8b48-9f5350121fee.png)


c)	After the folders are created, your program should move the photos to the folder based on their respective species and rename the photo with the pet's name.
Example: "/petshop/cat/joni.jpg".

d)	Because 1 photo may have more than 1 pet in it, photos must be moved to each corresponding category.
Example: photo with the name "dog;baro;1_cat;joni;2.jpg" is moved to the folder "/petshop/cat/joni.jpg" and "/petshop/dog/baro.jpg".

e)	In each folder, create a file "keterangan.txt" that contains names and ages of all the pets in the folder. 

## Question 3:
