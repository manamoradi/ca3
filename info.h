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
void info(Usr* curruntnode){
    int i=0;
    printf("username:%s, ",curruntnode->usrname);
    printf("password:%s\n",curruntnode->pass);
    Pst* temp=(Pst*)malloc(sizeof(Pst));
    temp=curruntnode->firstpost;
    temp=temp->next;
    while(temp->next!=NULL){
        i++;
        temp=temp->next;
        printf("post: %s\n",temp->line);
        printf("id: %d, ",temp->post_id[0]);
        printf("%d likes\n",temp->like[0]);
    }
    if(i==0)
       printf("no post\n");
}