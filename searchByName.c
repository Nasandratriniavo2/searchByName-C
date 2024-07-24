#include <stdio.h>
#include <string.h>
//#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "presence.h"

void searchByName(FILE* file,data* students)
{
    int i;
    char name[100]; 
    printf("Enter the name of the student that you wanna check:");
    fgets(name,100,stdin);
    name[strcspn(name, "\n")] = '\0'; // Supprime le caractère de nouvelle ligne s'il existe

    for(i=1;i<75;i++)
    {
        if(strstr(students[i].name,name)!=NULL||strstr(students[i].surname,name)!=NULL)
            printf("%s %s\n",students[i].name,students[i].surname);
    }
} 
/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    char surname[50];
} data;

void searchByName(FILE* file, data* students) {
    int i;
    char name[100]; 
    printf("Enter the name of the student that you want to check: ");
    fgets(name, sizeof(name), stdin);

    // Supprimer le caractère de nouvelle ligne s'il existe
    name[strcspn(name, "\n")] = '\0';

    // Convertir la chaîne de recherche en minuscules
    char clean_name[100];
    for (i = 0; name[i] != '\0'; i++) {
        clean_name[i] = tolower(name[i]);
    }
    clean_name[i] = '\0'; // Ajouter le terminateur de chaîne

    // Rechercher et afficher les étudiants correspondants (insensible à la casse)
    int found = 0;
    for (i = 0; i < 75; i++) {
        // Convertir les noms d'étudiants en minuscules pour la comparaison
        char student_name_lower[50];
        char student_surname_lower[50];
        for (int j = 0; students[i].name[j] != '\0'; j++) {
            student_name_lower[j] = tolower(students[i].name[j]);
        }
        student_name_lower[strlen(students[i].name)] = '\0'; // Ajouter le terminateur de chaîne
        for (int j = 0; students[i].surname[j] != '\0'; j++) {
            student_surname_lower[j] = tolower(students[i].surname[j]);
        }
        student_surname_lower[strlen(students[i].surname)] = '\0'; // Ajouter le terminateur de chaîne

        // Comparer les noms d'étudiants en minuscules avec la chaîne de recherche
        if (strcmp(student_name_lower, clean_name) == 0 || strcmp(student_surname_lower, clean_name) == 0) {
            printf("%s %s\n", students[i].name, students[i].surname);
            found = 1;
        }
    }

    // Si aucun étudiant correspondant n'est trouvé, afficher un message
    if (!found) {
        printf("No student found with the name '%s'.\n", name);
    }
}*///Code de chatGpt