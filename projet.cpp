#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
		
		typedef struct produitAchete{
			int  date;
			float prix_TTC;
			float prix;
		}achete;
	achete mdcv[100];
	 int nmv=0;
		
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
					
					mdc[nm].prix_TTC = mdc[nm].prix + (mdc[nm].prix*0.15);
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
			
		    printf("___________Bonjour___________ \n");
		    
	     	printf("\n");
	     	
	        printf("________bienvenu sur votre système_______\n");
	        
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
		   printf("11 ==>Statistique De Vente \n");
		    
		   printf("\n");
		}
		//		*********************************************************************************
		//RECHERCHE un medicament par code
     void rechercherParCode(){
	   int i,n;

       bool trouver = true;
       printf("Entrer le code  :");
          scanf("%d",&nm); 
   
           for(i=0; i < nm; i++)
		   {
   	   			if(mdc[i].code==n)
		         {
   			trouver = false;
   			
		          }
   			}
		   
		   if(trouver)
		   printf("ce medicament en stock");
			   else
			   printf("introuvable");
}



		   //RECHERCHE un medicament par  Quantite
		void rechercheMedicamentParQuantite(){
			
			int i,Q;
			bool trouver=false;
			
		   printf("Entrer la quantite de medicament : \n");
		   scanf("%d",&Q); 
		   
		   for(i=0; i < nm; i++)
		   {
		   		if(mdc[i].quantite>=Q)
				   {
		   			trouver=true;
		   							   
				   }
		   }	
		   if(trouver)   
             printf("ce medicament en stock");
            else
             printf("introuvable");
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
		     int now;
		     
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
		    time(NULL);  
//			 
             	time_t tt = time(NULL);
    			struct tm* dt = localtime(&tt);
             printf(" jour    |     mois    |     ans\n");
             printf("    %d   |      %d      |     %d  \n",dt->tm_mday,dt->tm_mon+1,dt->tm_year+1900);
		    mdcv[nmv].prix=mdc[nm].prix;
		    printf("le prix : %.2f",mdcv[nmv].prix);
		    
		    mdcv[nmv].prix_TTC=mdc[nm].prix_TTC;
		    printf("le prix_TTC : %.2f",mdcv[nmv].prix_TTC);
		    nmv++;
		}
		
						  
//		*********************************************************************************
				void totalPrix()
				{
				
				int i;
			    float S=0;
						 
				for(i=0;i<nmv;i++){
					
					S+=mdcv[i].prix;
				}
				printf("le prix total : %.2f \n",S);
					
					
			    }
//		*********************************************************************************
		void moyenneDesPrix()
			{
				
				int   i;
				float moyen , S;
				for(i=0;i<nmv;i++)
				{
				
					S+=mdcv[i].prix;
					printf("le prix total : %.2f\n",S);
					moyen = S/nmv;
					printf("moyenne : %.2f \n",moyen);
		     	}
			
			}
//		*********************************************************************************
     maxprixMedicamentVendus(){
     	int i ;
     	float  max=mdcv[0].prix;
     	for(i=0;i<nmv;i++){
     	if(mdcv[i].prix >max){
		 
		 	max=mdcv[i].prix;
		printf("le max prix : %.2f",max);
		 }	
		 }
	 }
	 //		*********************************************************************************
     minprixMedicamentVendus(){
     	int i ;
     	float  min=mdcv[0].prix;
     	for(i=0;i<nmv;i++){
     	if(mdcv[i].prix <min){
		 
		 	min=mdcv[i].prix;
		printf("le min prix  : %.2f",min);
		 }	
		 }
	 }
//		*********************************************************************************
void menuStatistique(){
	
	printf("1=> Afficher le total des prix des produits vendus en journee courante \n");
	printf("2=> Afficher la moyenne des prix des produits vendus en journée courante \n");
	printf("3=> Afficher le Max des prix des produits vendus en journée courante \n");
	printf("4=> Afficher le Min des prix des produits vendus en journée courante \n");

}
//		*********************************************************************************

              	void StatistiqueDeVente(){
              		
              		int choixS;
              		menuStatistique();
              		printf("entre votre choix\n ");
              		scanf("  %d",&choixS);
              		
              		switch(choixS){
              		 		case 1 :printf("le total des prix des medicament \n");
              								totalPrix();
              			break;
              				case 2 :printf("la moyenne des prix des medicament \n");
              				            moyenneDesPrix();
              			break;
						 
              				case 3 :printf("le Max des prix des medicament vendus \n ");
              				 maxprixMedicamentVendus();
              		    break;
              				case 4 :printf("Min des prix des medicament vendus \n");
              				 minprixMedicamentVendus();
              			break;		
              				default: printf("entre un choix entre 1 et 4 \n");
              			break;
              			
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
		        printf("***tri des medicaments selon L'ordre Alphabetique***\n");
		        listerSelonLordreAlphabetique();
		        break;
		        case 5: 
		        printf("***tri des medicaments Selon L'ordre Du Prix***\n");
		        listerSelonDecroissantPrix();
		        break;
		         case 6: 
		        printf("**************recherche par code****************\n");
		        rechercherParCode();
		        break;
		         
		         case 7: 
		        printf("**************Acheter produit\n**************");
		        acheterMedicament();
		        break;
		         case 8: 
		        printf("**************Etat Du Stock\n**************");
		        etatDeStock();
		        break;
		         case 9: 
		        printf("**************alimenter Le stock\n**************");
		        alimenterStock();
		        break;
                case 10: 
		        printf("**************Supprimer les medicaments par code t\n**************");
		        supprimerMedicament();
		        case 11: 
		        printf("************** Statistique de vente t\n**************");
		        StatistiqueDeVente();
		       
		        break;
		    }
		    goto debut;
		}
