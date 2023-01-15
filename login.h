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
Usr* login(Usr* firstnode,Usr* storenode,char* secondin,char* thirdin){
    int val2,val3;
    Usr* temp=(Usr*)malloc(sizeof(Usr));
    temp->usrname=(char*)malloc(sizeof(secondin));
    temp->pass=(char*)malloc(sizeof(thirdin));
    temp=firstnode->next;
    while(temp!=storenode->next){
        val3=strcmp(temp->pass,thirdin);
        val2=strcmp(temp->usrname,secondin);
        if(val2==0){
            if(val3==0){
                return temp;
            }
            printf("your password in wrong");
            return firstnode;
        }
        temp=temp->next;
    }
    /*free(temp->pass);
    free(temp->usrname);
    free(temp);*/
    printf("this acount doesn't exists");
    return firstnode;
}