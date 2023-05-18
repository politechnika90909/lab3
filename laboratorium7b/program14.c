#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


//podstawowa wersja programu wyświetla cykliczne 3 napisy ponaciśnięciu CTRL+C
//zakończenie programu CTRL+\ (SIGQUIT)


char napisy[3][80]={"Ha! Ha! Ha! To tylko sygnał powierzchowny!\n", "Tylko proces %d śmieje się sygnałowi %d prosto w twarz!\n", "Auć - to bolało!\n"};
int nr_napisu=0;
sigset_t sygnaly;


void obsluga_sig_int(int sig) {
	sigaddset(&sygnaly, sig);
}


void obsluga_sig_quit(int sig) {
	sigaddset(&sygnaly, sig);
}



void obsluga_sig_alarm(int sig){
	if(sigismember(&sygnaly, 2)){
		printf("SIGINT\n");
	}
	if(sigismember(&sygnaly, 3)){
		printf("SIGQUIT\n");
	}
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
    printf("sprawdzam\n");
}

int main(int argc, char** argv) {


    sigemptyset(&sygnaly);

	signal(SIGINT,obsluga_sig_int);
	signal(SIGQUIT, obsluga_sig_quit);
	signal(SIGALRM, obsluga_sig_alarm);
	alarm(5);
	while (1) {
		printf("Cześć tu proces: %d\n",getpid());
		sleep(1);
	}
	return 0;
}
