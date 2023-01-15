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
int like(Usr* firstnode,Usr* storenode,char* secondin,int postnumber){
    Usr* nextlike=(Usr*)malloc(sizeof(Usr));
    Usr* curpost;
    int val2;
    Usr* temp=(Usr*)malloc(sizeof(Usr));
    Pst* temppost=(Pst*)malloc(sizeof(Pst));
    temp->usrname=(char*)malloc(sizeof(secondin));
    temp=firstnode->next;
    while(temp!=storenode->next){
        val2=strcmp(temp->usrname,secondin);
        if(val2==0){
            curpost=temp;
            break;
        }
        temp=temp->next;
    }
    if(temp==NULL){
       printf("there is no shuch a username\n");
       return 0;//0: if unsuccessfull
    }
    temppost=curpost->firstpost;
    while(temppost!=NULL){
        if(temppost->post_id[0]==postnumber){
           temppost->like[0]++;
           printf("%d\n",temppost->like[0]);
           return 1;//1: if successfull
        }
        temppost=temppost->next;
    }
    printf("this acount hasn't post this\n");
    return 0;
}