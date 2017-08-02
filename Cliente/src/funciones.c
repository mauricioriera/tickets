#include "../include/header.h"

void error(char error[]) {	
	fprintf(stderr,"%d %s %s\n",errno,error,strerror(errno));
	exit(1);	
}

void clean(char * buff) {
	int i;
	for(i = 0; i < strlen(buff); i++){
		buff[i] = '\0';
	}
}

char * ingresarTicket(int op, char id_ticket[]) {

	char *ticket = (char *) malloc (BUF_SIZE * sizeof(char));
	char titulo[20];
	char autor[30];
	char descripcion[100];
	
	printf ("\nTitulo: ");
	fgets(titulo, 20, stdin);
	*(titulo+(strlen(titulo)-1)) = '\0';
	printf ("Autor: ");
	fgets(autor, 30, stdin);
	*(autor+(strlen(autor)-1)) = '\0';
	printf ("Descripcion: ");
	fgets(descripcion, 100, stdin);
	*(descripcion+(strlen(descripcion)-1)) = '\0';
	
	if (op == 'i')
		sprintf (ticket, "%c|%s|%s|%s", op, titulo, autor, descripcion);
	else
		sprintf (ticket, "%c|%s|%s|%s|%s", op, id_ticket, titulo, autor, descripcion);

	return ticket;
}

void listarTickets(char tickets[]) {

	fprintf(stderr,"%s" ,tickets);
	clean(tickets);
}



