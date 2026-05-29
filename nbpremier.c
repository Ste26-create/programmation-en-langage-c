#include <stdio.h>
#include <stdlib.h>
int tab[50];

void nbpremier(char *fichier);
void affichage(char *fichier);
void trier(char *fichier);
void changement(char *fichier);

void nbpremier(char *fichier)
{
  FILE *fi=fopen(fichier,"w+");
  if (fi==NULL)
  {
    printf("impossible d'ouvrir le fichier ");
    exit(0);
  }
  int compte = 0;
  int nombre = 2;

    printf("Les 50 premiers nombres premiers sont :\n");

    while (compte < 50) 
	{
        int estPremier = 1; // On suppose que le nombre est premier

        // Vérification si le nombre actuel est premier
        for (int i = 2; i * i <= nombre; i++) 
		{
            if (nombre % i == 0) 
			{
                estPremier = 0;
                break;          
            }
        }

      i++;
      fprintf(fi,"%d\n",nbv);
    }
    nbv++;
  }
  fclose(fi);
}
void affichage(char *fichier)
{
  int affiche=50,compteur=1,vu,N=3;
  FILE *fil=fopen(fichier,"r");
  if (fil==NULL)
  {
    printf("ouverture du fichier impossible ");
    exit(0);
  }
  nbpremier(fichier);
  while(compteur<=affiche)
  {
    fscanf(fil,"%d\n",&vu);
    compteur++;
    if (compteur%N==0)
    {
      printf("%d:%d\n",compteur,vu);
    }
  }
  fclose(fil);
}
void trier(char *fichier)
{
	int i,N=50;
	FILE *f=fopen(fichier,"a");
	fprintf(f,"trie par ordre décroissant des nombres \n"); 
	for(i=0;i<N;i++)
	{
		fprintf(f,"%d\n",tab[N-i-1]);
	}
	fclose(f);
}
void changement(char *fichier)
{
  FILE *f=fopen(fichier,"a");
  fprintf(f,"changement de 5 en V \n");
  int i,j,a,k;
  char ch[52][52],cr[52][10],tp;
  for (i=0;i<50;i++)
  {
    sprintf(ch[i],"%d",tab[i]);
    j=0;
    while (ch[i][j] != '\0')
    {
      if (ch[i][j] == '5')
      {
        ch[i][j]='V';
      }
      j++;
    }
    fprintf(f,"%s\n",ch[i]);
  }
  fprintf(f,"les nombre dont leur places sont échangées de place \n");
  for (i=0;i<50;i++)
  {
    sprintf(cr[i],"%d",tab[i]);
    k=0;
    while (cr[i][k] != '\0')
    {
      k++;
    }
    if (k>1)
    {
      for(a=0;a<(k/2);a++)
      {
        tp=cr[i][a];
        cr[i][a]=cr[i][k-a-1];
        cr[i][k-a-1]=tp;
      }
    }
  }
  for (i=0;i<50;i++)
  {
    fprintf(f,"%s\n",cr[50-i-1]);
  }
  fclose(f);
}
int main()
{
  char *fichier="npremier.txt";
  affichage(fichier);
  trier(fichier);
  changement(fichier);
  return 0;
}

