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
char* firsttakein(char* firsttaken){
     int i=0;
     firsttaken=(char*)malloc(sizeof(char)*20);
     char c=getchar();
     while(c!=' '&&c!='\n'){
            *(firsttaken+i)=c;
            firsttaken=(char*)realloc(firsttaken,sizeof(char)*(i+1));
            i++;
            c=getchar();
    }
    return firsttaken;
}