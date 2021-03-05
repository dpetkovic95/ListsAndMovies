
typedef struct {
	char naziv[20];
	char zanr[20];
	int trajanje;
}Film;

typedef struct Cvor{
	Film film;
	struct Cvor *sled;
}Cvor;


void sviFilmovi(Cvor *l){
	if (l == NULL){
		printf("\nLista je prazna.\n\n");
		return;
	}
	Cvor *p;
	p=l;
	int i=1;
	while(p!=NULL){
		printf("\n%d. Film: %s, Zanr: %s, Trajanje: %d min.\n\n",i,p->film.naziv,p->film.zanr,p->film.trajanje);
		p = p->sled;
		i++;
	}
}
struct Cvor* dodajFilm_naPocetak(Cvor *l){
	
	Cvor *novi;
	novi = (Cvor*)malloc(sizeof(Cvor));
	Film movie;
	
	
	printf("\nUnesite naziv filma:\n");
	scanf("%s",&movie.naziv);
	printf("Unesite zanr filma:\n");
	scanf("%s",&movie.zanr);
	printf("Unesite duzinu trajanja filma:\n");
	scanf("%d",&movie.trajanje);
	printf("\n");
	
	novi->film = movie;
	novi->sled = l;
	
	return novi;	
}
struct Cvor* dodajFilm_naKraj(Cvor *l){
	Cvor *q,*novi;
	q = l;
	novi = (Cvor*)malloc(sizeof(Cvor));
	Film movie;
	
	printf("\nUnesite naziv filma:\n");
	scanf("%s",&movie.naziv);
	printf("Unesite zanr filma:\n");
	scanf("%s",&movie.zanr);
	printf("Unesite duzinu trajanja filma:\n");
	scanf("%d",&movie.trajanje);
	printf("\n");
	
	if(q == NULL){
		novi->film = movie;
		novi->sled = l;
		return novi;
	}
	
	while(q->sled!=NULL){
		q = q->sled;
	}
	
	novi -> film = movie;
	novi -> sled = q -> sled;
	q->sled = novi;
	
	return l;
}

struct Cvor* izbrisiFilm(Cvor *l, char naziv_filma[]){
	if (l == NULL){
		printf("\nLista je prazna.\n\n");
		return l;
	}

	if(strcmp(l->film.naziv,naziv_filma) == 0){
		l = l->sled;
		return l;	
	}
	Cvor *p;
	p=l;
	while(p!=NULL){
		if(strcmp((p->sled)->film.naziv,naziv_filma) == 0){
			p->sled = (p->sled)->sled;
			return l;
		}
		p = p->sled;
		
	}
	return l;
}	









