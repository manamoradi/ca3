#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct post{
    char* line;
    int like[1];
    int post_id[1];
    struct post* next;
}Pst;
typedef struct user{
    char* usrname;
    char* pass;
    struct user* next;
    Pst* firstpost;
}Usr;
int post(Usr* currunt,char* secondin){
    int i=1;
    Pst* firstpst;
    firstpst=currunt->firstpost;
    Pst* temp;
    Pst* new=(Pst*)malloc(sizeof(Pst));
    if(new==NULL){
        printf("memory allocation failed\n");
        return 0;
    }
    new->line=(char*)malloc(sizeof(secondin));
    strcpy(new->line,secondin);
    temp=firstpst->next;
    while(temp->next!=NULL){
         temp=temp->next;
        i++;
    }
    new->post_id[0]=i;
    new->like[0]=0;
    temp->next=new;
    new->next=NULL;
    return 1;
}