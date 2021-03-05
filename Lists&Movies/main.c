#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkcije.c"


int main(){
	
	Cvor *l;
	l = NULL;
	char naziv_filma[20]; 
	
	int in,in2;
	
	while(in != 4){
		printf("1 - dodaj film.\n2 - lista svih filmova.\n3 - izbrisi film\n4 - kraj\n\n");
		scanf("%d",&in);
		
		if (in == 1){
			
			printf("0 - dodaj na kraj \n1 - dodaj na pocetak\n\n");
			scanf("%d",&in2);
			if(in2)
				l = dodajFilm_naPocetak(l);
			else l = dodajFilm_naKraj(l);
			
		}
		else if (in == 2){
			
			sviFilmovi(l);
		}
		else if(in == 3){
			printf("Unesite naziv filma: \n");
			scanf("%s",&naziv_filma);
			l = izbrisiFilm(l,naziv_filma);
			
		}
}
	
		
		


}
