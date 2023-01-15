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
Usr* logout(Usr* firstnode,Usr* curruntnode){
    if(curruntnode!=firstnode)
        return firstnode;
    printf("first you have to login into your account");
    return curruntnode;
}