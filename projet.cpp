#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
		
	    typedef struct Date 
        {
	      int day ,month ,year;
        }date;
		
		
		typedef struct produitAchete
        {
			date  d;
			float prix_TTC;
			float prix_Total;
			char nom[20];
		    int code;
	    	int quantite ; 
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
			     	printf("      %s       |                %d                 |      %d          \n",
                    mdc[i].nom,mdc[i].code,mdc[i].quantite);
			       
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
		
	
		
		
		
		//		*********************************************************************************
		//  STRCMP Cette fonction permet de comparer deux cha�nes de caract�res et de savoir
		// si la premi�re est inf�rieure, �gale ou sup�rieure � la seconde
		//fonctionlisterSelonL'ordreAlphabetique

		void listerSelonLordreAlphabetique()
        {
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
	     	
	        printf("________bienvenu sur votre syst�me_______\n");
	        
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
            printf("Entrer le code  :\n");
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
                    printf(" les produits dont la quantit� est inf�rieure � 3 son\n ");
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
                    printf("entre le code de medicament :\n");
                      scanf("%d",&c);
                    printf("entre la quantite de medicament :\n");
                      scanf("%d",&Q);
                    
                     for(i=0;i<nm;i++)
                     {
                        if(mdc[i].code==c)
                        {
                           mdc[i].quantite += Q; //medicament[i].quantite =medicament[i].quantite + Q
                        }
                      
                    }
        }  
                

//		*********************************************************************************
          void supprimerMedicament()
 		{
	            int i ,c,j;
                   
                    printf("entre le code de medicament que tu vous supprimer : \n");
                      scanf ("%d",&c);

                      for(i=0;i<nm;i++)
                      {
                       if(c == mdc[i].code )
                      {
                         printf("%d",i);
                            j = i;
                         for (i=j;i<nm;i++)
                         {
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
            // float prixproduits;
            time_t t = time(NULL);
            struct tm* datee = localtime(&t);
            int i, code, quantite,count=0;

                    printf("entrer le code du medicament : ");
                    scanf("%d", &code);

                    printf("entrer la quantite du medicament :");
                    scanf("%d", &quantite);
            for (i = 0; i < nm; i++)
            {
                if (mdc[i].code == code)
                {
                    if (mdc[i].quantite >= quantite)
                    {
                        mdc[i].quantite -= quantite;
                        mdcv[nmv].code = mdc[i].code;
                        strcpy(mdcv[nmv].nom,mdc[i].nom);
                        mdcv[nmv].prix_TTC = mdc[i].prix_TTC;
                        mdcv[nmv].quantite = quantite;
                        mdcv[nmv].prix_Total = quantite * mdc[i].prix_TTC;
                        mdcv[nmv].d.day =datee->tm_mday ;
                        mdcv[nmv].d.month =datee->tm_mon+1 ;
                        mdcv[nmv].d.year =datee->tm_year+1900 ;

                        nmv++;
                    }
                    else
                    {
                        printf("quantite insuffisante\n");
                    }
                    break;
                }
                else{
                    count++;//pour chercher si le code existe et refaire condition jusqua la derniere case du tableau 
                }
            }
            if(count==nm){
                        printf("produit introuvable\n");
            }

            for( i = 0 ; i < nmv ; i++){
                printf("%d          %f         %d \n",mdcv[i].code, mdcv[i].prix_TTC , mdcv[i].quantite);
            }
        } 
//		*********************************************************************************
		 void statistiques(){
            time_t t = time(NULL);
            struct tm* datee = localtime(&t);
            int jour = datee->tm_mday;
            int mois = datee->tm_mon + 1;
            int annee = datee->tm_year + 1900;
            float prixT = 0 , moyenne = 0 ;
            int i , Totalquantite=0;
            float min, max;
            //&&produitvendu[i].d.month==mois&&produitvendu[i].d.year==annee
            min = mdcv[0].prix_Total;
            max = mdcv[0].prix_Total;
            
            for(i=0;i<nmv ;i++)
            {
                if(mdcv[i].d.day==jour&&mdcv[i].d.month==mois&&mdcv[i].d.year==annee)
                {
                    prixT += mdcv[i].prix_Total ; //somme prix produit vendu
                    Totalquantite+=mdcv[i].quantite;
                }
                if(max < mdcv[i].prix_Total)
                {
                    max = mdcv[i].prix_Total;
                }
                if(min > mdcv[i].prix_Total)
                {
                    min = mdcv[i].prix_Total;
                }
            }
            moyenne = prixT/(float)Totalquantite ;
                    // printf("la somme des prix de votre produits vendus est -----> %.3f DH\n",);
            // printf("le nombres de votre produits vendus est ----->%d PRODUITS\n\n\n",totalquantite);
            printf("le total des prix des medicament vendus est = %.2f\n",prixT);
            printf("la moyenne des prix des medicament vendus est = %.2f\n",moyenne);
            printf("le max des prix des medicament vendus aujourd'hui  : %f\n",max);
            printf("le min des prix des medicament vendus aujourd'hui  : %f\n",min);
        }
//		*********************************************************************************
 

		//    MAIN
		
		int main(){
			
			int choix;
		    debut:
		    menu();
                printf("entrer votre choix:\n");
                printf("_-_*-_-_*-_-_*-_-*_-_-*_-_-*_\n");
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
		        printf("**************Acheter produit************** \n");
		        acheterMedicament();
		        break;
		         case 8: 
		        printf("**************Etat Du Stock************** \n");
		        etatDeStock();
		        break;
		         case 9: 
		        printf("**************alimenter Le stock************** \n");
		        alimenterStock();
		        break;
                case 10: 
		        printf("**************Supprimer les medicaments par code **************\n");
		        supprimerMedicament();
		        case 11: 
		        printf("************** Statistique de vente **************\n");
		        statistiques();
		       
		        break;
		    }
		    goto debut;
		}
