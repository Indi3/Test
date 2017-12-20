#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

//Deklaracja funkcji
void print_my_data(){
	fprintf(stdout, "UID %d\t\tGID %d\n", getuid(), getgid());
	fprintf(stdout, "PID %d\t\tPPID %d\n", getpid(), getppid());
}

int main(int argc, char **argv){

	printf("Proces macierzysty:\n");
	print_my_data();
	int id_potomek;
	int time;
	char znak;
	char temp[16];
	for(int i = 0; i < 3; i++){

		id_potomek = fork();

		switch(id_potomek){
			//Bląd forka
			case -1:
				printf("fork error");
				exit(1);

			break;
			//To co wykonuje proces potomny
			case 0:
				printf("\nHej jestem potomkiem!!\n");
				print_my_data();

			break;
			//To co wykonuje proces macierzysty
			//default:
			//oczekiwanie na koniec potomka
				/*wait(&time);
				fprintf(stdout,"Wcisnij [enter]");
				fscanf(stdin,"%c",&znak);
				printf("\n");*/

				//sprintf(temp, "pstree -p %d", id_potomek);

				//system(temp);
				//execl("/usr/bin/pstree", "pstree","-p",temp, NULL);
				//execl("/usr/bin/pstree", "pstree","-p", NULL);
		}

//Konczenie pętli, gdy wykonuje sie potomek, aby nie powielać tych samych danych
		if(id_potomek == 0)
			break;
	}

	//Wypisywanie drzewa procesów
	if(id_potomek > 0){
		//wait(&time);
		printf("\n\n\n");
		sprintf(temp, "pstree -p %d", getpid());
		system(temp);
		//printf("\n%d\n", getpid());
		printf("\n\n\n");
		sprintf(temp, "pstree -p %d", getpid());
		execl("/usr/bin/pstree", "pstree","-p",temp, NULL);
	}

	//execl("/usr/bin/echo", "echo", "Testowe echo hihi", NULL);
}
