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
int numofposts(Usr* currunt){
    int i=0;
    int postnum;
    Pst* temp=(Pst*)malloc(sizeof(Pst));
    temp=currunt->firstpost;
    temp=temp->next;
    while(temp->next!=NULL){
        temp=temp->next;
        i++;
    }
    if(i==0)
       return 0;//there's no posts in this account
    postnum=temp->post_id[0];
    return postnum;
}