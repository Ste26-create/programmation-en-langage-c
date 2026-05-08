#include <stdio.h>
#include <string.h>
char check_palindrome(char *ch)
{
  printf("entrer la chaine a verifier : ");
  scanf("%s",ch);
  int i,fin;
  fin=strlen(ch)-1;
  for (i=0;i<fin/2;i++)
  {
	if (ch[i]==ch[fin])
	{
		fin--;
	}
	else
	{
		printf("la chaine '%s' n'est pas palindrome \n",ch);
		return 0;
	}
  }
  printf("la chaine '%s' est palindrome\n ",ch);

}
int main()
{
  char *chaine;
  check_palindrome(chaine);
  return 0;
}

