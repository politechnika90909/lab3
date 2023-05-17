#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


//podstawowa wersja programu wyświetla cykliczne 3 napisy ponaciśnięciu CTRL+C
//zakończenie programu CTRL+\ (SIGQUIT)


char napisy[3][80]={"Ha! Ha! Ha! To tylko sygnał powierzchowny!\n", "Tylko proces %d śmieje się sygnałowi %d prosto w twarz!\n", "Auć - to bolało!\n"};
int nr_napisu=0;


void obsluga_sig_int(int sig) {
	printf(napisy[nr_napisu],getpid(),sig);
	nr_napisu=((nr_napisu + 1) % 3);
}

void dawne(int sig){
	exit(0);
}

void obsluga_sig_quit(int sig){
	signal(SIGINT, dawne);
	printf("Przywrócono normalne działanie");
}

int main(int argc, char** argv) {
	signal(SIGINT,obsluga_sig_int);
	signal(SIGQUIT, obsluga_sig_quit);
	while (1) {
		printf("Cześć tu proces: %d\n",getpid());
		sleep(1);
	}
	return 0;
}
