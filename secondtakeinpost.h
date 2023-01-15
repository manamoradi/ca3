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
char* secondtakeinpost(char* secondtaken){//diffrence between secontakein and thi function: user is not soppose to enter tab in secontakein but in here he can
    int i=0;
    secondtaken=(char*)malloc(sizeof(char)*20);
    char c=getchar();
    while(c!='\n'){
        *(secondtaken+i)=c;
        secondtaken=(char*)realloc(secondtaken,sizeof(char)*(i+1));
        i++;
        c=getchar();
    }
    return secondtaken;
}