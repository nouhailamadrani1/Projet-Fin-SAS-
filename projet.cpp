#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
		
		
	
		
		//struct de medicament
		
		typedef struct medicament{
		char nom[20];
		int code;
		int quantite ; 
		float prix ;
		float prix_TTC ;
		}medicament;
		
		// nombre de medicament "nm"
		// type "medicament"
		int nm=0;
		medicament mdc[100];
		
		
    //		*********************************************************************************

		//premier fonction de ajoute un medicament 
		
		
		void ajouterMedicament()
			{
				
					printf("entrer le nom de medicament : \n");
					scanf("%s",mdc[nm].nom);
					printf("entrer le code de medicament : \n");
					scanf("%d",&mdc[nm].code);
					printf("entrer la quantite de medicament : \n");
					scanf("%d",&mdc[nm].quantite);
					printf("entrer le prix de medicament : \n");
					scanf("%f",&mdc[nm].prix);
				
					nm++;
				
			}
		
		//		*********************************************************************************
		//deuxieme fonction de ajoute des nouveaux medicaments
		// n variable de nombre de medicament 
		void ajouterPlusieursMedicaments()
		{
		   int n , i; 
				printf("entrer le nombre de medicament  que vous souhaitez ajouter : \n");
				scanf("%d",&n);
				
	     	for(i=0;i<n;i++)
	    	{
	      		ajouterMedicament();
	    	}
	    }
		//		*********************************************************************************
		//AFFICHER
		   void afficher()
		   {
		  	int i ;
		    
		    for(i=0;i<nm;i++)
		       {
			    	printf("   le nom      |             code                  |       quantite\n");
			    	printf("--------- -----|-----------------------------------|-------------------\n");
			    	
			     	printf("      %s       |                %d                 |      %d          \n",mdc[i].nom,mdc[i].code,mdc[i].quantite);
			       
			       		                    	printf("  le prix  \n ");
                    printf("--------- -------------------------------------------------------------\n");
			       	                              printf(" %.2f\n ",mdc[i].prix);
			        printf("--------- -------------------------------------------------------------\n");
			       	printf("--------- -------------------------------------------------------------\n");
			    	mdc[i].prix_TTC = mdc[i].prix + (mdc[i].prix * 0.15);
					                       	printf("  le prix_TTC  \n ");
                    printf("--------- -------------------------------------------------------------\n");
			       	                            printf(" %.2f\n ",mdc[i].prix_TTC);
			        printf("--------- -------------------------------------------------------------\n");
		       }
		   }
		
		//Lister tous les produits (Nom, prix, prix TTC):
		//lister tous les produits selon l'ordre alphabetique  croissant du nom.
		
		//  STRCMP Cette fonction permet de comparer deux chaînes de caractères et de savoir
		// si la première est inférieure, égale ou supérieure à la seconde
		//fonctionlisterSelonL'ordreAlphabetique
		
		//		*********************************************************************************
		
		void listerSelonLordreAlphabetique(){
		
		int i,j;
		j=i+1;
		
		for(i=0;i<nm;i++)
			{
				for(j=i+1;j<nm;j++)
				{
					if(strcmp(mdc[i].nom,mdc[j].nom)>0)
					{
						medicament k;
					       k=mdc[i];
					       mdc[i]=mdc[j];
					       mdc[j]=k;
					}
				}
			}
			afficher();
		}
		
		//Lister tous les produits (Nom, prix, prix TTC):
		//lister tous les produits selon l'ordre  de croissant du prix.
		//fonctionlisterSelonDecroissantPrix
		//		*********************************************************************************
	void listerSelonDecroissantPrix()
	{
	        	int i, j;
		
		j=i+1;
		for(i=0;i<nm;i++)
		{
			for(j=i+1;j<nm;j++)
			{
					if(mdc[i].prix>mdc[j].prix)
					{
				    	medicament q;
						      q=mdc[i];
						      mdc[i]=mdc[j];
						      mdc[j]=q;
					}
			}
		}
			afficher();
	}
		
		
		
		
	
		
		//		*********************************************************************************
		// MUNEU
		void menu(){
		    printf("___________Bonjour___________ ");
		    
	     	printf("\n");
	     	
	        printf("________bienvenu sur votre système_______ ");
	        
	    	printf("\n");
	   
	   
		    printf("1==>ajouter un nouveau medicament\n");
		    
		    printf("\n");
		    
		    printf("2 ==> ajouter plusieurs medicaments \n");
		    
		    printf("\n");
		    
		    printf("3 ==> afficher medicament\n");
		    
		    printf("\n");
		    
		    printf("4 ==> tri les medicaments selon L\'ordreAlphabetique\n");
		    
		    printf("\n");
		    
		    printf("5 ==> tri les medicaments Selon Decroissant Prix \n");
		    
		    printf("\n");
		    
		    printf("6 ==> recherche par code \n");
		    
		    printf("\n");
		    
		    printf("7 ==> Acheter un medicament \n");
		    
		    printf("\n");
		    
		    printf("8 ==> Etat de stock \n");
		    
		    printf("\n");  
		    
		    printf("9 ==>alimenter Le stock \n");
		    
		   printf("\n");
		   
		   printf("10 ==>Supprimer les medicaments par code \n");
		    
		   printf("\n");
		}
		//		*********************************************************************************
		//RECHERCHE un medicament par code
 void rechercheMedicamentParCode()
    
	{
		int i , c;
		
		printf("entre un code de medicament : \n");
		scanf("%d",&c);
		for(i=0;i<nm;i++)
		{
		if(mdc[i].code==c){
		
		
		printf("le medicament est en stock ");
		}
		else{
		
		printf("le medicament est introvable en stock ");
		}
		}
		
}
		   //RECHERCHE un medicament par  Quantite
		void rechercheMedicamentParQuantite(){
			
			int i,Q;
			
			
		   printf("Entrer la quantite de medicament : \n");
		   scanf("%d",&Q); 
		   
		   for(i=0; i < nm; i++)
		   {
		   		if(mdc[i].quantite>=Q)
				   {
		   			
		   			printf("le medicament est en stock ");
		   							   
				   }
				   else
				   
				   printf("le medicament est introvable ");
		   }
		   
}
		
//		*********************************************************************************

     void etatDeStock()
	 {
	
    	int i;
   	        printf(" les produits dont la quantité est inférieure à 3 son\n ");
    	for(i=0;i<nm;i++)
	   {
        	 if(mdc[i].quantite<=3)
			{
			   		printf("nom=>  %s  \n",mdc[i].nom);
			   		printf("code=> %d  \n",mdc[i].code);
		  	   		printf("quantite=> %d\n",mdc[i].quantite);
			   		printf("prix=> %.2f\n",mdc[i].prix);
	        }
        }
      }
//		*********************************************************************************
   void alimenterStock()
   {
   	
		int i,c,Q;
			
			printf("entre le code de medicament :");
			scanf("%d",&c);
			
			printf("entre la quantite de medicament :");
			scanf("%d",&Q);
			
			
			for(i=0;i<nm;i++)
			{
			 if(mdc[i].code==c)
				{
			    mdc[i].quantite += Q; //medicament[i].quantite =medicament[i].quantite + Q
			    }
			 break;
		   }
   }  
		   

//		*********************************************************************************
          void supprimerMedicament()
 		{
	            int i ,c,j;
                    printf("supprimer un medicament \n");
                    
                    printf("entre le code de medicament que tu vous supprimer : \n");
                      scanf ("%d",&c);

                      for(i=0;i<nm;i++){
                       if(c == mdc[i].code ){
                           printf("%d",i);
                         j = i;
                       for (i=j;i<nm;i++){
                           mdc[i]=mdc[i+1];
                           nm--;
                          break;
                      }
                     }
                   }
          }
		
		
	

//		*********************************************************************************
		void acheterMedicament()
		{
		   
		     int i, C, Q,jFin=0;
		     
		    printf("entrer le code de produit : ");
		    scanf("%d", &C);
		
		    printf("entrer la quantite de produit :");
		    scanf("%d", &Q);
		    for (i = 0; i < nm; i++)
		    {
		        if (mdc[i].code == C)
		        {
		            if (mdc[i].quantite >= Q)
		            {
		                mdc[i].quantite -= Q;
		   
		            }
		            else
		            {
		                printf("introvable!!\n");
		            }
		            break;
		        }
		        else{
		            jFin++;//pour chercher si le code existe et refaire condition jusqua la derniere case du tableau 
		        }
		    }
		    if(jFin==nm){
		                printf("produit introuvable\n");
		    }
		}
//		*********************************************************************************

		
		//    MAIN
		
		int main(){
			
			int choix;
		    debut:
		    menu();
		    printf("entrer votre choix:\n");
		    printf("-----------_-\n");
		    scanf("%d", &choix);
		    switch(choix){
		        case 1: 
		        printf("*****ajouter un nouveau medicament******\n");
		        ajouterMedicament();
		        break;
		        case 2: 
		        printf("*******ajouter plusieurs medicaments******\n");
		        ajouterPlusieursMedicaments();
		        case 3: 
		        printf("*******afficher medicament********\n");
		        afficher();
		        break;
		        case 4: 
		        printf("***tri les medicaments selon L\'ordreAlphabetique***\n");
		        listerSelonLordreAlphabetique();
		        break;
		        case 5: 
		        printf("***tri les medicaments Selon Decroissant Prix***\n");
		        listerSelonDecroissantPrix();
		        break;
		         case 6: 
		        printf("**************recherche par code****************\n");
		        rechercheMedicamentParCode();
		        break;
		         
		         case 7: 
		        printf("**************Acheter produit\n**************");
		        acheterMedicament();
		        break;
		         case 8: 
		        printf("**************Etat De Stock\n**************");
		        etatDeStock();
		        break;
		         case 9: 
		        printf("**************alimenter Le stock\n**************");
		        alimenterStock();
		        break;
                case 10: 
		        printf("**************Supprimer les medicaments par code t\n**************");
		        supprimerMedicament();
		       
		        break;
		    }
		    goto debut;
		}
