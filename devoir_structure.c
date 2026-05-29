#include <stdio.h>
#include <stdlib.h>

struct infopersonnel {
    char nom[30];
    char prenom[60];
    char niveau[15];
    char filiere[20];
    char adresse[100];
    char date_de_naissance[12];
    int date;
};

void inscription(struct infopersonnel etudiant[]);
int nb_eleveL1 = 0, nb_eleveL2 = 0, nb_eleveL3 = 0, nb_eleveM1 = 0, nb_eleveM2 = 0, nb_eleveD1 = 0, nb_eleveD2 = 0;
struct infopersonnel etudiantL1[60], etudiantL2[60], etudiantL3[60], etudiantM1[60], etudiantM2[60], etudiantD1[60], etudiantD2[60];

void inscription(struct infopersonnel etudiant[]) {
    char Niveau[7][20] = {"L1", "L2", "L3", "M1", "M2", "D1", "D2"};
    int classe = -1;
    char lesinfo[][50] = {
        "entrer votre nom : ", 
        "entrer votre prenoms : ", 
        "votre date de naissance jj/mm/aaaa : ", 
        "votre adresse : ", 
        "votre niveau : ", 
        "votre filiere : "
    };
    
    FILE *niveau_file;
    int j = 0;
    char reponse;

    do {
        printf("\n--------------------------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < 6; i++) {
            printf("\n%s\t", lesinfo[i]);
            switch (i) {
                case 0: 
                      scanf("%s", etudiant[j].nom); 
                      break;
                case 1: 
                      scanf(" %[^\n]", etudiant[j].prenom); 
                      break;
                case 2: 
                      scanf("%s", etudiant[j].date_de_naissance); 
                      break;
                case 3: 
                      scanf(" %[^\n]", etudiant[j].adresse); 
                      break;
                case 4: 
                      scanf(" %[^\n]", etudiant[j].niveau); 
                      break;
                case 5: 
                      scanf(" %[^\n]", etudiant[j].filiere); 
                      break;
            }
        }

        
        char c = etudiant[j].niveau[0];
        char num = etudiant[j].niveau[1];

        if (c == 'L' || c == 'l') {
            if (num == '1') 
            { 
              etudiantL1[nb_eleveL1] = etudiant[j]; 
              classe = 0;
              nb_eleveL1++; 
            }
            else if (num == '2') 
            { 
              etudiantL2[nb_eleveL2] = etudiant[j];
              classe = 1; nb_eleveL2++; 
            }
            else if (num == '3') 
            { 
              etudiantL3[nb_eleveL3] = etudiant[j]; 
              classe = 2; nb_eleveL3++; 
            }
        } 
        else if (c == 'M' || c == 'm') 
        {
            if (num == '1') 
            { 
              etudiantM1[nb_eleveM1] = etudiant[j]; 
              classe = 3;
              nb_eleveM1++; 
            }
            else if (num == '2') 
            { 
              etudiantM2[nb_eleveM2] = etudiant[j]; 
              classe = 4; 
              nb_eleveM2++; 
            }
        } 
        else if (c == 'D' || c == 'd') 
        {
            if (num == '1') 
            { 
              etudiantD1[nb_eleveD1] = etudiant[j]; 
              classe = 5; 
              nb_eleveD1++; 
            }
            else if (num == '2') 
            { 
              etudiantD2[nb_eleveD2] = etudiant[j]; 
              classe = 6; 
              nb_eleveD2++;
            }
        }

        
        if (classe != -1) 
        {
            niveau_file = fopen(Niveau[classe], "a+");
            if (niveau_file == NULL) {
                printf("impossible d'ouvrir le fichier\n");
                exit(0);
        }
        fprintf(niveau_file, "%-20s %-25s %-20s %-20s %-20s\n", 
                etudiant[j].nom, etudiant[j].prenom, etudiant[j].date_de_naissance, etudiant[j].niveau, etudiant[j].filiere);
            fclose(niveau_file);
        printf("\nInscription terminee\n");
        } 
        else 
        {
            printf("\nNiveau invalide. Etudiant non enregistre dans un fichier.\n");
        }

        printf("\n--------------------------------------------------------------------------------------------------------------------\n");
        j++;

        
        printf("Voulez-vous inscrire un autre etudiant ? (o/n) : ");
        scanf(" %c", &reponse);

    }
    while (reponse == 'o' || reponse == 'O');
}

int main() {
    struct infopersonnel etudiant[500]; 
    inscription(etudiant);
    return 0;
}
