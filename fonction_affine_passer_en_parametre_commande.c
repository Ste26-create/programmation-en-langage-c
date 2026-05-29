#include <stdio.h>
#include <stdlib.h>
/*le programme evalue la valeur d'une fonction f(x)( fonction affine quelque soit les valeurs ) passer en parametre de la commande dont la valeur de x est donner*/
int main(int n,char *tab[])
{
	char a[10],b[10],xx[10];
	int aa,bb,j=0,k=0,sg,x,y;
	if (n == 4)
	{
		while (*(tab[1]+j) != 'x')
		{
			a[j]=*(tab[1]+j);
			j++;
		}
		sg=j+1;
		aa=atoi(a);j=j+2;
		while (*(tab[1]+j) != '\0' && *(tab[1]+j) != '\n')
		{
			b[k]=*(tab[1]+j);
			k++;
			j++;
		}
		bb=atoi(b);
		
		j=0;k=0;
		while(*(tab[3]+j) != '\0')
		{
			if(*(tab[3]+j)== 'x' || *(tab[3]+j) == '=')
			{
				j++;
			}
			else
			{
				xx[k]=*(tab[3]+j);
				j++;k++;
			}
		}
		x=atoi(xx);
		if (tab[1][sg] == '-')
		{
			y = (aa * x) -bb;
		}
		else if (tab[1][sg] == '+')
		{
			y = (aa * x) + bb;
		}
		
		printf("f(%d) = %d * %d %c %d \nf(%d) = %d \n",x,aa,x,tab[1][sg],bb,x,y);
	}
	else
	{
	  printf("mauvais syntaxe de commande\nutilisation : \nfonction_commande <f(x)> pour x=<nombre>\n");
	}
}
