#include <stdio.h>
#define MAX 100
void triangle_Pascal(int N)
{
  int i,j,k;
  unsigned long long tab[MAX][MAX];
  for (i=0;i<=N;++i)
  {
    for (j=0;j<=i;j++)
    {
      if (j==0 || j==i)
      {
        tab[i][j]=1;
      }
      else
      {
        tab[i][j]=tab[i-1][j-1]+tab[i-1][j];
      }
      printf("%lld ",tab[i][j]);
    }
    printf("\n");
  }
}
int main()
{
  int N;
  printf("entrer la taille du triangle : ");scanf("%d",&N);
  printf("voila le triangle de pascal de taille N \n");
  triangle_Pascal(N);
}
