#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>
#include <time.h>

int main() {
	pid_t pid;
	char curtime[100];
	time_t t1 = time(NULL);
	struct tm*p1 = localtime(&t1);
	strftime (curtime, 100, "%Y-%m-%d_%H:%M:%S", p1);

	pid = fork ();
	if (pid < 0) exit(0);
	if (pid > 0) exit (0);
		if (cid == 0){
			char *agv[] = {"mkdir", curtime, NULL};
			execv ("/bin/mkdir", agv);
		}
	sleep(40);
}
