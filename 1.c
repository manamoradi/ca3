#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "delete.h"
#include "finduser.h"
#include "firsttakein.h"
#include "secondtakein.h"
#include "secondtakeinpost.h"
#include "thirdtakein.h"
#include "info.h"
#include "like.h"
#include "login.h"
#include "logout.h"
#include "numofposts.h"
#include "post.h"
#include "signup.h"
#include "finduser.h"
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
int main(){
    FILE* account=fopen("accounts.txt","w");
    FILE* pst=fopen("posts.txt","w");
    Usr* head;
    Usr* store=(Usr*)malloc(sizeof(Usr));//this node presents the last node 
    head=(Usr*)malloc(sizeof(Usr));
    Usr* currunt=(Usr*)malloc(sizeof(Usr));
    head->next=store;
    store->next=NULL;
    currunt=head;
    char* firstin;
    char* secondin;
    char* secondin3;
    char* thirdin;
    char c;
    int postnum2;
    secondin=(char*)malloc(sizeof(char)*20);
    thirdin=(char*)malloc(sizeof(char)*20);
    firstin=(char*)malloc(sizeof(char)*20);
    store->usrname=(char*)malloc(sizeof(secondin));
    store->pass=(char*)malloc(sizeof(thirdin));
    int revaluesign=7;
    int revaluelogi=7;
    int revaluelogo=7;
    int revalueinfo=7;
    int revaluefind=7;
    int revaluepost=7;
    int revaluelike=7;
    int revaluedel=7;
    int revalueend=7;
    int i=0;
    int postnum;
    printf("this program has been stared\n");
    while(1){
        firstin=firsttakein(firstin);
        revaluesign=strcmp(firstin,"signup");
        revaluelogi=strcmp(firstin,"login");
        revaluelogo=strcmp(firstin,"logout");
        revalueinfo=strcmp(firstin,"info");
        revaluepost=strcmp(firstin,"post");
        revaluefind=strcmp(firstin,"find_user");
        revaluelike=strcmp(firstin,"like");
        revaluedel=strcmp(firstin,"delete");
        revalueend=strcmp(firstin,"end");
        if(revaluesign==0){
            if(currunt==head){
                secondin=secondtakein(secondin);
                thirdin=thirdtakein(thirdin);
                currunt=signup(head,store, secondin,thirdin);
                store=currunt;
            }
            else 
                printf("first logout, then try signing up\n");
        }
        else if(revaluelogi==0){//if currunt=head: not into any acount,if currunt!=head: into the currunt acount
            if(currunt==head){
                secondin=secondtakein(secondin);
                thirdin=thirdtakein(thirdin);
                currunt=login(head,store, secondin,thirdin);
            }
            else{
                printf("first logout, then try logging in\n");
            }
        }
        else if(revaluelogo==0){
            if(currunt!=head)
                currunt=logout(head,currunt);
        }
        else if(revalueinfo==0){
            if(currunt!=head)
                info(currunt);
            if(currunt==head)
               printf("try logging in first\n");
        }
        else if(revaluepost==0){
            if(currunt!=head){
               secondin=secondtakeinpost(secondin);
               post(currunt,secondin);
            }
            if(currunt==head)
               printf("you have to be logged in in order to post something\n");
        }
        else if(revaluelike==0){
            if(currunt!=head){
                secondin=secondtakein(secondin);
                scanf("%d",&postnum);
                printf("%d",postnum);
                like(head,store,secondin,postnum);
            }
            else
               printf("first login\n");
        }
        else if(revaluefind==0){
            if(currunt!=head){
                secondin=secondtakeinpost(secondin);
                finduser(head,store,secondin);
            }
        }
        else if(revaluedel==0){
            if(currunt!=head){
                scanf("%d",&postnum2);
                delete(currunt,postnum2);
            }
        }
        else if(revalueend==0)//end of the program 
            break;
        else{
            printf("this command does not exist in this program\n");
        }
    }
    Usr* temp=(Usr*)malloc(sizeof(Usr));//at the end in accounts.txt file every accounts are printed
    Pst* temppost=(Pst*)malloc(sizeof(Pst));
    temp=head->next;
    temp=temp->next;
    while(temp!=NULL){
        temppost=temp->firstpost;
        temppost=temppost->next;
        while(temppost->next!=NULL){
            temppost=temppost->next;
            fprintf(pst,"%s %s %d\n",temppost->line,temp->usrname,temppost->like[0]);
        }
        postnum=numofposts(temp);
        fprintf(account,"%s %s %d\n",temp->usrname,temp->pass,postnum);
        temp=temp->next;
    }
}