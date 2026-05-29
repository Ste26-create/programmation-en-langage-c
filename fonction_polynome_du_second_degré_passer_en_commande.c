#include <stdio.h>
#include <stdlib.h>
/*le programme evalue la valeur d'une fonction f(x)( polynome du second degré quelque soit les valeurs ) passer en parametre de la commande dont la valeur de x est donner*/
int main(int n,char *tab[])
{
	char a[10],b[10],c[10],xx[10];
	int aa,bb,cc,j=0,k=0,sg1,sg2,x,y;
	if (n == 4)
	{
		while (*(tab[1]+j) != 'x')
		{
			a[j]=*(tab[1]+j);
			j++;
		}
		sg1=j+3;
		aa=atoi(a);j=j+2;
		while (*(tab[1]+j) != 'x')
		{
			b[k]=*(tab[1]+j);
			k++;
			j++;
		}
		sg2=j+1;
		bb=atoi(b);
		j=j+2;
		k=0;
		while (*(tab[1]+j) != '\0' && *(tab[1]+j) != '\n')
		{
			c[k]=*(tab[1]+j);
			k++;
			j++;
		}
		cc=atoi(c);
		j=0;k=0;
		while(*(tab[3]+j) != '\0')
		{
			if(*(tab[3]+j)== 'x' || *(tab[3]+j) == '=')
			{
				j++;
			}
			else
			{
				xx[k] = *(tab[3]+j);
				j++;k++;
			}
		}
		x=atoi(xx);
		if (tab[1][sg1] == '-' )
		{
		  if (tab[1][sg2] == '+')
		  {
			y = (aa * x * x) - ( bb * x ) + cc ;
		  }
		  else if (tab[1][sg2] == '-')
		  {
		        y = (aa * x * x) - ( bb * x ) - cc ;
		  }
		}
		else if (tab[1][sg1] == '+')
		{
		  if (tab[1][sg2] == '+')
		  {
			y = (aa * x * x) + ( bb * x ) + cc ;
		  }
		  else if (tab[1][sg2] == '-')
		  {
		        y = (aa * x * x) + ( bb * x ) - cc ;
		  }	
		}
		
		printf("f(%d) = %d (%d)² %c %d (%d) %c %d\nf(%d) = %d \n",x,aa,x,tab[1][sg1],bb,x,tab[1][sg2],cc,x,y);
	}
	else
	{
	  printf("mauvais syntaxe de commande\nutilisation : \nfonction_commande <f(x)> pour x=<nombre>\n");
	}
}
