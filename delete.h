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
int delete(Usr* curruntnode,int postnum){
    Pst* temp=(Pst*)malloc(sizeof(Pst));
    Pst* new=(Pst*)malloc(sizeof(Pst));
    temp=curruntnode->firstpost;
    temp=temp->next;
    new=temp;
    while(temp->next!=NULL){
        new=temp;
        temp=temp->next;
        if(temp->post_id[0]==postnum){
           new->next=temp->next;
           while(new->next!=NULL){
              new->next->post_id[0]--;
              new=new->next;
           }
           free(temp);
           return 1;//1: if successfull
        }
    }
    printf("you don't have this post");
    return 0;//0: if unsuccessfull
}