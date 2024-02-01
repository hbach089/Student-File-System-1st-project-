#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedLists.h"
#define BUFF_SIZE 1024

/*
//int i=0; //represente l'etudiant a quel # dans la liste
//struct Node*head=NULL;
char c[1];


typedef struct Node{
    int data;
    struct Node *next;
}node;
*/
void write_file(FILE*);
void search_file(FILE*,char*);
void remove_student(FILE*,char*);
//int start_index(char*);

/*
//check if student number is in the linked list (for searching and removing)
bool check_sn(node**,int,char);

//add student numbers to linked list as node
void add_sn(node**,int);

//free the student numbers linked list nodes 1 by 1
void clear_linked_list(node**);

//remove student number node from linked list
void remove_sn(node**,int);
*/

void main(){
        FILE *fptr;
        fptr=fopen("STUDENTS.txt","w+");
        char c[1];
        int init=0;
        if(fptr==NULL){
            printf("PTR IS NULL");
            fflush(stdout);
        }


        //USE MEMORY MANAGEMENT/linked lists POUR AFFICHER TOUTES LES VALEURS:
        //PRENOM ET NOM, OU STUDENT NUMBER, DEPENDANT DE CE QUE
        //L'UTILISATEUR CHOISI COMME ENTREE.

        printf("Shall we start?(y/n) ");
        scanf(" %s",&c);
        while(1){
            if(c[0]!='y' && c[0]!='n' || strlen(c)>1){
                printf("Wrong input man!!!!!\n");
                while ((getchar()) != '\n');
            }
            else if(c[0]=='y'){
                while(1){
                            //À implémenter: rendre le op array en char
                    char op[BUFF_SIZE];
                    printf("Do you want to search(s) or write(w) or remove(r)? ");
                    scanf(" %s",op);

                    if (op[0]!='s' && op[0]!='w' && op[0]!='r' || strlen(op)>1){
                        printf("Wrong input! ");
                        fflush(stdout);
                        continue;
                    }
                    else if(op[0]=='w'){
                        write_file(fptr);
                    }
                    else if(op[0]=='s'){
                        if(i==0){
                            printf("No students in the file yet!\n");
                            fflush(stdout);
                        }
                        else{
                            bool bo=true;
                            char*sn=(char*)malloc(sizeof(char)*9);
                            while(1){
                                printf("Enter a student number: ");
                                scanf(" %s",sn);
                                bo=check_sn(&head,atoi(sn),op[0]);
                                bo=true;
                                if(bo==false){
                                    printf("Number does not exist, enter another one! ");
                                    fflush(stdout);
                                }
                                else{
                                    search_file(fptr,sn);
                                    break;
                                }
                            }
                        }

                    }
                    else if(op[0]=='r'){
                        char*sn=(char*)malloc(sizeof(char)*9);
                        if(i==0){
                            printf("No students in the file yet!\n");
                            fflush(stdout);
                        }
                        else{
                            bool bo=true;
                            char*sn=(char*)malloc(sizeof(char)*9);
                            while(1){
                                printf("Enter a student number: ");
                                scanf(" %s",sn);
                                bo=check_sn(&head,atoi(sn),op[0]);
                                if(bo==false){
                                    printf("Number does not exist, enter another one! ");
                                    fflush(stdout);
                                }
                                else{
                                    remove_student(fptr,sn);
                                    free(sn);
                                    break;
                                }
                            }
                        }
                    }
                    while ((getchar()) != '\n');
                    printf("\n");
                    break;
                }
            }
            else if(c[0]=='n'){
                printf("LOOOOL");
                printf("Exiting");
                clear_linked_list(&head);
                fclose(fptr);
                exit(EXIT_SUCCESS);
            }

            printf("Do you want to continue?(y/n) ");
            scanf(" %c",&c[0]);

    }
}

void write_file(FILE *fptr){
    char f_name[BUFF_SIZE],l_name[BUFF_SIZE],fy[BUFF_SIZE];
    int sn;
    bool bo=true;
    char op='w';
    // A IMPLEMENTE: verifies si l'entree correspond au type de donnee/data type

    //Utilise toujours fflush pour etre sur que le ouput ne reste pas dans le buffer
    // et apparait dans le file.
    i++;
    printf("\n");
    fprintf(fptr,"STUDENT %d:",i);
    fflush(fptr);
    printf("STUDENT %d\n",i);

    //IL RESTE A IMPLEMENTER LE ERROR HANDLING DANS LE WRITE_FILE
    printf("Enter first name: ");
    scanf("%s",f_name);
    fprintf(fptr," %s,",f_name);
    fflush(fptr);

    printf("Enter last name: ");
    scanf("%s",l_name);
    fprintf(fptr," %s,",l_name);
    fflush(fptr);

    while(bo){
        printf("Enter 9 digit student number: ");
        scanf(" %d",&sn);

        bo=check_sn(&head,sn,op);
        // if sn n'est pas un int , "continue"?????
        if(bo==true){
            printf("Number is already in use! ");
            fflush(stdout);
        }
        else{
            add_sn(&head,sn);
            fprintf(fptr,"%d,",sn);
            fflush(fptr);
        }
    }

    printf("Enter faculty: ");
    scanf("%s",fy);
    fprintf(fptr," %s",fy);
    fflush(fptr);

    fputc('\n',fptr);
    fflush(fptr);
    return;
}

//Peut etre retourne un string?????
void search_file(FILE*fptr,char*sn){
    //remet le pointer au debut du file

    char buffer[BUFF_SIZE],temp[8];
    int j=0,t=0;
    char c;
    bool lol;

    rewind(fptr);
    if(i==0){
        printf("No students in the file yet!\n");
        fflush(stdout);
        return;
    }

    while(j<i){
        fgets(buffer,BUFF_SIZE,fptr);
        t=0;
        lol=true;
        for(int k=(int)(strchr(buffer,':')-buffer);k<strlen(buffer);k++){
            //filtre pour obtenir un nombre complet
            if(buffer[k]<='9' && buffer[k]>='0' && buffer[k]!=',' && buffer[k]!=' ' && buffer[k]!='\0'){
                if(sn[t]==buffer[k]){
                    temp[t]=buffer[k];
                    //printf("sn=%c and buff=%c\n",sn[t],temp[t]);
                    fflush(stdout);
                }
                else{
                    lol=false;
                    break;
                }
                t++;
            }
        }
        //printf("%s",c);
        if(lol==true){
            //STUDENT 1: hadi, bach, 3001, eng
            //On retourne une chaine avec la premiere occurence de :
            //Le +2 c'est pour boujer le pointer de deux pas vers la droite
            char*c=strchr(buffer,':')+2;
            printf("%s",c);
            fflush(stdout);
            return;
        }
        memset(temp, '\0', sizeof(temp));
        j++;
    }

}

void remove_student(FILE*fptr,char*sn){
    int j=0,t=0;
    char buffer[BUFF_SIZE],temp[BUFF_SIZE];
    rewind(fptr);

    FILE*fptr2=fopen("REMOVED.txt","w+");


    //C'EST UN PROBLEME AVEC LE fptr cursor. DONC UTILISE fseek() ou rewind()
    //dans le if statement je veux dire.
    while(j<i){
        fgets(buffer,BUFF_SIZE,fptr);
        int t=0;
        bool lol=true;
        for(int k=(int)(strchr(buffer,':')-buffer);k<strlen(buffer);k++){
            if(buffer[k]<='9' && buffer[k]>='0' && buffer[k]!=',' && buffer[k]!=' ' && buffer[k]!='\0'){
                if(sn[t]==buffer[k]){
                    temp[t]=buffer[k];
                    printf("sn=%c and buff=%c\n",sn[t],temp[t]);
                    fflush(stdout);
                }
                else{
                    lol=false;
                    break;
                }
                t++;
            }
        }
        if(lol==false){
            fprintf(fptr2,"%s",buffer);
            fflush(fptr2);
        }
        memset(buffer,'\0',sizeof(buffer));
        memset(temp,'\0',sizeof(temp));
        j++;
    }

    remove_sn(&head,atoi(sn));
    // [DONE] create temp file
    // [DONE] copy everything into temp file (fptr2) except for line you want to delete (check student number)
    //delete original file and recreate it with same fptr and same name, recopy everything into original file
    //delete temp file;

    //CREE UNE FONCTION QUI SUPPRIME LE NODE DANS LA LINKEDLIST POUR sn et cast en (int)
    fptr=fopen("STUDENTS.txt","w+");

    rewind(fptr2);
    while(fgets(buffer,BUFF_SIZE,fptr2)!=NULL){
        fprintf(fptr,"%s",buffer);
        fflush(fptr);
    }

    fclose(fptr2);
    fclose(fptr);
}


