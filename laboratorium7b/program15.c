#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


//podstawowa wersja programu wyświetla cykliczne 3 napisy ponaciśnięciu CTRL+C
//zakończenie programu CTRL+\ (SIGQUIT)


char napisy[3][80]={"Ha! Ha! Ha! To tylko sygnał powierzchowny!\n", "Tylko proces %d śmieje się sygnałowi %d prosto w twarz!\n", "Auć - to bolało!\n"};
int nr_napisu=0;
sigset_t *sygnaly;
struct sigaction struktura;





void obsluga_sig_int(int sig) {
	printf("int\n");
	sleep(2);
}


void obsluga_sig_quit(int sig) {
	printf("quit\n");
}

void dawne(int sig){
	exit(0);
}

sa_handler = obsluga_sig_int;


int main(int argc, char** argv) {
	

	sigaction(SIGINT, struktura.sa_handler, NULL);
	signal(SIGQUIT, obsluga_sig_quit);

	while (1) {
		printf("Cześć tu proces: %d\n",getpid());
		sleep(1);
	}
	return 0;
}
