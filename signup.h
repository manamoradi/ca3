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
Usr* signup(Usr* firstnode,Usr* storenode,char* secondin,char* thirdin){
    Usr* nextst=(Usr*)malloc(sizeof(Usr));
    Usr* temp=(Usr*)malloc(sizeof(Usr));
    temp->usrname=(char*)malloc(sizeof(secondin));
    temp->pass=(char*)malloc(sizeof(thirdin));
    temp=firstnode->next;
    int val2;
    while(temp!=storenode->next){
        val2=strcmp(temp->usrname, secondin);
        if(val2==0){
            printf("this account already exists, try logging in\n");
            return firstnode;
        }
        temp=temp->next;
    }
    nextst->usrname=(char*)malloc(sizeof(secondin));
    strcpy(nextst->usrname, secondin);
    nextst->pass=(char*)malloc(sizeof(thirdin));
    strcpy(nextst->pass, thirdin);
    storenode->next=nextst;
    nextst->next=NULL;
    Pst* firstpst=(Pst*)malloc(sizeof(Pst));
    nextst->firstpost=firstpst;
    Pst* dummy=(Pst*)malloc(sizeof(Pst));
    firstpst->next=dummy;
    dummy->next=NULL;
    return nextst;
}