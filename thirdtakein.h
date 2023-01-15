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
char* thirdtakein(char* thirdtaken){
    thirdtaken=(char*)malloc(sizeof(char)*20);
    int i=0;
    char c=getchar();
    while(c!=' '&&c!='\n'){
        *(thirdtaken+i)=c;
        thirdtaken=(char*)realloc(thirdtaken,sizeof(char)*(i+1));
        i++;
        c=getchar();
    }
    return thirdtaken;
}