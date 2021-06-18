#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//Declarations structures
typedef struct Fvoiture {
	int matriculeVoiture;
	char marque[20];
	char modele[30];
} Fvoitures;

typedef struct Fclient {
	int numeroClient;
	char nom[20];
	char prenom[30];
	int numeroTelephone;
} Fclients;

typedef struct Flocation {
	int matriculeVoiture;
	int numeroClient;
    char dateLocation[12];
} Flocations;

typedef struct Freservation {
	int matriculeVoiture;
	int numeroClient;
	char dateReservation[12];
    char etat[11];

} Freservations;



//Declarations Nom physique des fichiers	
char Fvoiture[45]="C:\\Users\\HP\\Downloads\\prjttp\\Fvoiture.txt";
char Fclient[45]="C:\\Users\\HP\\Downloads\\prjttp\\Fclient.txt";
char Flocation[45]="C:\\Users\\HP\\Downloads\\prjttp\\Flocation.txt";
char Freservation[45]="C:\\Users\\HP\\Downloads\\prjttp\\Freservation.txt";
char FsupV[45]="C:\\Users\\HP\\Downloads\\prjttp\\FsupV.txt";







//Declaration variables globales ou programme

int X,i,j,k,p,et,T[40];


FILE *fv;
FILE *fc;
FILE *fl;
FILE *fr;


Fvoitures A;
Fclients  B;
Flocations C;
Freservations D;
int Matricule,MatriculeS;




/*procédure d'incertion */
void insertion(int y) {

int NBR;

    if(y==1){
    	 
		 printf("Nombre de voitures a ajouter?\n");
         scanf("%d",&NBR);
	    
    for(X=1;X<=NBR;X++)
        {
		        
		 fv=fopen(Fvoiture,"a");
         i++;
           
		    printf("~~ Info de la voiture %d ~~\n",i);
		    
      	    printf("Donner son matricule :\n");
			scanf("%d",&A.matriculeVoiture);

			printf("Donner La Marque :\n");
			scanf("%s",A.marque);

			printf("Donner Le Modele :\n");
			scanf("%s",A.modele);
			
			printf("***********************\n");


	   // fprintf(fv,"~~ voiture %d ~~\n",i);
		fprintf(fv,"%d\t%s\t%s\n",A.matriculeVoiture,A.marque,A.modele);
	   // fprintf(fv,"____________________________________________________________\n");


           fclose(fv);
		}
        
       
}
     
     
else {
	 
     
       if(y==2){
       	
       	 printf("Nombre de clients a ajouter?\n");
         scanf("%d",&NBR);
	
    for(X=1;X<=NBR;X++)
      {
		
		
		fc=fopen(Fclient,"a");
		
			j++;
            printf("~~Info du client %d ~~\n",j);

			printf("Donner Le numero de client\n");
			scanf("%d",&B.numeroClient);

			printf("Donner son nom\n");
			scanf("%s",B.nom);

			printf("Donner son prenom\n");
			scanf("%s",B.prenom);

			printf("Donner son numero de telephone(10 chiifres max))\n");
			scanf("%d",&B.numeroTelephone);
			
			printf("***********************\n");
          //  fprintf(fc,"~~ client %d ~~\n",j);
            fprintf(fc,"%d\t%s\t%s\t%d\n",B.numeroClient,B.nom,B.prenom,B.numeroTelephone);

		//	fprintf(fc,"____________________________________________________________\n");


	 
        
           fclose(fc);
       }
 }
 
	
	
else {
	
	
	
	  if(y==3){
	  	
	  	 printf("Nombre de locations a ajouter?\n");
         scanf("%d",&NBR);
	
    for(X=1;X<=NBR;X++)
      {
      	
        fl=fopen(Flocation,"a");
        
        	k++;
            printf("~~Info de location %d ~~\n",k);

			printf("Donner Le Matricule\n");
			scanf("%d",&C.matriculeVoiture);

			printf("Donner Le numero de client\n");
			scanf("%d",&C.numeroClient);

			printf("Donner La date de location jj_mm_aaaa\n");
			scanf("%s",C.dateLocation);
			
            printf("***********************\n");
        
		  //  fprintf(fl,"~~ Location %d ~~\n",k);

			fprintf(fl,"%d\t%d\t%s\n",C.matriculeVoiture,C.numeroClient,C.dateLocation);
		//	fprintf(fl,"____________________________________________________________\n");

		
		
        
        fclose(fl);
		}
}


else{


  if(y==4){
  	
  	 printf("Nombre de reservations a ajouter?\n");
     scanf("%d",&NBR);
	
    for(X=1;X<=NBR;X++)
      {

	    fr=fopen(Freservation,"a");
	    	
			p++;

            printf("~~Info de reservation %d ~~\n",p);
            
			printf("Donner Le Matricule\n");
			scanf("%d",&D.matriculeVoiture);

			printf("Donner Le numero de client\n");
			scanf("%d",&D.numeroClient);

			printf("Donner La date de reservation jj_mm_aaaa\n");
			scanf("%s",D.dateReservation);
			
			printf("Choisissez l'etat: 1 :satisfaite 2 :annule 3 :en attente\n");
			
			scanf("%d",&et);
			
			switch (et){
				case 1 :strcpy(D.etat,"satisfaite");break; //assigner satisfaite a D.etat
				case 2 :strcpy(D.etat,"annule");break;
				case 3 :strcpy(D.etat,"en attente") ;	
			};

			
            printf("***********************\n");
            
            
			fprintf(fr,"%d\t%d\t%s\t%s\n",D.matriculeVoiture,D.numeroClient,D.dateReservation,D.etat);

			fclose(fr);
	};};
		
		
	};
}}};





/*Procédure de recherche*/


	void recherche(int y) {
	
    if(y==1){
    fv=fopen(Fvoiture,"r");
    		

     printf("> Donner le matricule a rechercher\n");
     scanf("%d",&X);

			while (fscanf(fv,"%d %s %s",&A.matriculeVoiture,A.marque,A.modele)!=EOF) {
				
				
				if(A.matriculeVoiture==X) { 
			
				
					printf("< la voiture existe\n");
					printf("< Sa marque est %s\n",A.marque);
					printf("< Son modele est %s \n",A.modele);
					fclose(fv);
					}
				}
					
				
				 
				if(A.matriculeVoiture!=X) { 
                	 printf("< la voiture n`existe pas\n");}
				 
	
}

else {


	if (y==2){
		
           printf("> Donner le numero de client a rechercher\n");
           scanf("%d",&X);

		      
			fc=fopen(Fclient,"r");
	       
			
            while(fscanf(fc,"%d %s %s %d",&B.numeroClient,B.nom ,B.prenom,&B.numeroTelephone )!= EOF){
			
					if(X==B.numeroClient){
				
					
					printf("< le client existe\n");
				    printf("< Son numero : %d\n",B.numeroClient);
                    printf("< Son nom : %s\n",B.nom);
				    printf("< Son prenom : %s\n",B.prenom);
                   	printf("< Son numero de telephone : (0)%d\n",B.numeroTelephone);
			        fclose(fc);
					
					}
			}
					if(X!=B.numeroClient){
					printf("< le client n`existe pas\n");}
       }
			
	
	
else{
			
			
if(y==3){
				
    printf("> Donner le matricule a rechercher");
    scanf("%d",&X);
	
			fl=fopen(Flocation,"r");

		
	while (fscanf(fl,"%d %d %s",&C.matriculeVoiture,&C.numeroClient,C.dateLocation)!= EOF){
	
		if(C.matriculeVoiture==X) {
			
			    printf("< location existe\n");
				printf("< son numero : %d\n",C.numeroClient);
				printf("< date de location : %s\n",C.dateLocation);
				
			
			fclose(fl);
			}
			
		}
			if(C.matriculeVoiture!=X){
			printf("< location n`existe pas\n");
			
			}
			   
}


else{

		
if(y==4){
	
	if(fclose(fr)){
	
	
		fr=fopen(Freservation,"r");
		
	};
			
    printf("> Donner le matricule");
    scanf("%d",&X);
    
	while (fscanf(fr,"%d %d %s %s",&D.matriculeVoiture,&D.numeroClient,D.dateReservation,D.etat)!= EOF) {

		if(D.matriculeVoiture==X) {
			
		printf("< reservation existe\n");
		printf("< La date de reservation : %s\n",D.dateReservation);
		printf("< Le numero de client : %d\n",D.numeroClient);
		printf("< L'etat : %s\n",D.etat);

		
		fclose(fr);
		
	    }
	}
		if(D.matriculeVoiture!=X){
		   printf("< Reservation n'existe pas");}

}}}
	
}
}




//procedure suppresion
void suppresion ( int y,int T[40],int NBR){
	
    FILE *fsupv;


	
    if(y==1){
    	 
	
    for(X=1;X<=NBR;X++)
      {
		 fsupv=fopen(FsupV,"w");
		 fv=fopen(Fvoiture,"r");
		 
		 while (fscanf(fv,"%d %s %s",&A.matriculeVoiture,A.marque,A.modele)!= EOF) {
				if(A.matriculeVoiture!=T[X]) {

				fprintf(fsupv,"%d\t%s\t%s\n",A.matriculeVoiture,A.marque,A.modele);

				};};};
				
			    fclose(fsupv);fclose(fv);
			    
				fsupv=fopen(FsupV,"r");
	            fv=fopen(Fvoiture,"w");
	          
	     while(fscanf(fsupv,"%d %s %s",&A.matriculeVoiture,A.marque,A.modele)!= EOF) {
		

			fprintf(fv,"%d\t%s\t%s\n",A.matriculeVoiture,A.marque,A.modele);

//fprintf(fv,"____________________________________________________________\n");

			
				}
				fclose(fsupv);fclose(fv);fsupv=fopen(FsupV,"w");fclose(fsupv);





    for(X=1;X<=NBR;X++){
    	
    	T[X]=T[X+1];
    	
	};
		}
			
	 else {
	 
     
       if(y==2){
       	
    for(X=1;X<=NBR;X++)
      {
		
		fsupv=fopen(FsupV,"a");	
		fc=fopen(Fclient,"r");
		
      
	   while (fscanf(fc,"%d %s %s %d",&B.numeroClient,B.nom,B.prenom,&B.numeroTelephone)!= EOF){
		
		
			if(B.numeroClient!=T[X]) {
				
				fprintf(fsupv,"%d\t%s\t%s\t%d\n",B.numeroClient,B.nom,B.prenom,B.numeroTelephone);
				}}}
				fclose(fsupv);fclose(fc);
				fsupv=fopen(FsupV,"r");
	            fc=fopen(Fclient,"w");
	          
	     while(fscanf(fsupv,"%d %s %s %d",&B.numeroClient,B.nom,B.prenom,&B.numeroTelephone)!= EOF) {
		

			fprintf(fc,"%d\t%s\t%s\t%d\n",B.numeroClient,B.nom,B.prenom,B.numeroTelephone);

				}
				fclose(fsupv);fclose(fc);fsupv=fopen(FsupV,"w");fclose(fsupv);
				
				
				 for(X=1;X<=NBR;X++){
    	
             	T[X]=T[X+1];
    	
                     	};
			}
	
	
	else {
	
	
	
	  if(y==3){
	
    for(X=1;X<=NBR;X++)
      {
		fsupv=fopen(FsupV,"a");	
        fl=fopen(Flocation,"r");
        
      


   while (fscanf(fl,"%d %d %s",&C.matriculeVoiture,&C.numeroClient,C.dateLocation)!= EOF){
		
			if(C.numeroClient!=T[X]) {
				
				fprintf(fsupv,"%d\t%d\t%s\n",C.matriculeVoiture,C.numeroClient,C.dateLocation);
				}}}
			
				fclose(fsupv);fclose(fl);
				fsupv=fopen(FsupV,"r");
	            fl=fopen(Flocation,"w");
	          
	     while(fscanf(fsupv,"%d %d %s",&C.matriculeVoiture,&C.numeroClient,C.dateLocation)!= EOF) {
		

			fprintf(fl,"%d\t%d\t%s\n",C.matriculeVoiture,C.numeroClient,C.dateLocation);
			
				}
				fclose(fsupv);fclose(fl);fsupv=fopen(FsupV,"w");fclose(fsupv);
				
				 for(X=1;X<=NBR;X++){
    	
                	T[X]=T[X+1];
    	
                	};
			}
        
    else{


  if(y==4){
 
	
    for(X=1;X<=NBR;X++)
      {
	    fsupv=fopen(FsupV,"w");
	    fr=fopen(Freservation,"r");
	      	    
		
	     while (fscanf(fr,"%d %d %s %s",&D.matriculeVoiture,&D.numeroClient,D.dateReservation,D.etat)!= EOF){
			if(D.numeroClient!=T[X]) {
				
				fprintf(fsupv,"%d\t%d\t%s\t%s\n",D.matriculeVoiture,D.numeroClient,D.dateReservation,D.etat);
				}}

				}
				fclose(fsupv);fclose(fr);	
			    fsupv=fopen(FsupV,"r");
	            fr=fopen(Freservation,"w");
	          
	     while(fscanf(fsupv,"%d\t%d\t%s\t%s\n",&D.matriculeVoiture,&D.numeroClient,D.dateReservation,D.etat)!= EOF) {
		

			fprintf(fr,"%d\t%d\t%s\t%s\n",D.matriculeVoiture,D.numeroClient,D.dateReservation,D.etat);

				}
				
				fclose(fsupv);fclose(fr);fsupv=fopen(FsupV,"w");fclose(fsupv);
				
				 for(X=1;X<=NBR;X++){
    	
               	T[X]=T[X+1];
    	
                   	};
			}
	};};}
		
	
};



	
//Procedure Mise A Jour 

void miseAjour(){
	
	char date[12];
  
	fr=fopen(Freservation,"r");

while(fscanf(fr,"%d %d %s %s",&D.matriculeVoiture,&D.numeroClient,D.dateReservation,D.etat)!= EOF) {
	
	
	if (strcmp(D.etat, "satisfaite")== 0) //si D.etat == satisfaite
	{
		fl=fopen(Flocation,"a");
		printf("> Donnez la date d'aujord'hui (Pour ajoutez a Flocation)\n");
		scanf("%s",date);
	
     	C.matriculeVoiture=D.matriculeVoiture;
     	C.numeroClient=D.numeroClient;
     	strcpy(C.dateLocation,date);
     	
		printf("> La voiture %d est : louee\n",D.matriculeVoiture);

			T[1]=D.numeroClient;
			

		fprintf(fl,"%d\t%d\t%s\n",D.matriculeVoiture,D.numeroClient,date);	
		
		suppresion(4,T,1);
		
		
		
	}else {
	
	
	     if(strcmp(D.etat,"annule")==0 ){
	     	
	     T[1]=C.numeroClient;	
		 suppresion(4,T,1);
	     
	     printf("> La voiture %d est : libre",D.matriculeVoiture);
	
		 }
		}
	}
		fclose(fl);
	
	while(fscanf(fr,"%d %d %s %s",&D.matriculeVoiture,&D.numeroClient,D.dateReservation,D.etat)!= EOF) {
		
	 printf("> La voiture %d est : reservee",D.matriculeVoiture);
	
	}
		
		fclose(fr);
	
		}
	
	



int main ()

{
	
	int boo,y,NBR,z,W;
	
	
printf("\n *********************************************************************\n\n");
printf(" BIENVENU AU SYSTEM QUI VA VOUS AIDEZ A GERER VOTRE AGENCE DE VOITURE!\n\n");
printf(" *********************************************************************\n\n\n");

do{


	 
 printf("> Tapez sur:\n1 :Pour incerer\n2 :Pour rechercher\n3 :Pour supprimer\n4 :Pour la mise a jour\n0 :Pour quitez\n");
 scanf("%d",&boo);





 
 if (boo==1){
 
	printf("> Dans quel fichier voulez vous incerer?\n");
	printf("1 :Fvoiture\n2 :Fclient\n3 :Flocation\n4 :Freservation\n");
	scanf("%d",&y);
 
 
 insertion(y);
 
 printf("> Les elements sont bien incerer\n");
 };



if(boo==2){
			
printf("> Dans quel fichier voulez vous chercher ?\n");
printf("1 :Fvoiture\n2 :Fclient\n3 :Flocation\n4 :Freservation\n");
scanf("%d",&y);
recherche(y);

};


if(boo==3){

printf("> Dans quel fichier voulez vous supprimer ?\n");
printf("1 :Fvoitures\n2 :Fclients\n3 :Flocations\n4 :Freservations\n");
scanf("%d",&y);


switch (y) {


case 1 :printf("Nombre de voitures a supprimer? :\n");
        scanf("%d",&NBR);
        
        for(z=1;z<=NBR;z++){	
		printf("> Donner le matricule de la voiture %d a supprimer :\n",z);
        scanf("%d",&W);
        T[z]=W;
    }
break;
case 2 :
       	printf("> Donner le Nombre de clients a supprimer :\n");
        scanf("%d",&NBR);
        for(z=1;z<=NBR;z++){
		
		printf("> Donner Le numero %d de client a supprimer\n",z);
		scanf("%d",&W);

        T[z]=W;
    }
      
break;


case 3 :printf("> Donner le nombre de locations a supprimer ? :\n");
        scanf("%d",&NBR);
        
        
        for(z=1;z<=NBR;z++){			
		printf("> Donner Le numero de client %d a supprimer\n",z);
		scanf("%d",&W);
        T[z]=W;
    }
   break; 
     

case 4 : 	
  	    printf("> Donner le nombre de reservations a supprimer :\n");
        scanf("%d",&NBR); 
        for(z=1;z<=NBR;z++){
		
		printf("> Donner Le numero de client %d a supprimer\n",z);
		scanf("%d",&W);
        T[z]=W;

    }
    
	 

}

suppresion(y,T,NBR);
printf("> Les elements sont bien supprimer\n");

}



if(boo==4){
	
	miseAjour();
}




}while(boo!=0);




















	return 0;
}
