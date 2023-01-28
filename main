#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "structs.h"

user* signup(char username[100], char password[100],user* usersHead);
void search(user *usersHead, char username[100]);
void printlist(user* usersHead);
void login(user* usersHead , char username[100] , char password[100]);
void posting(char content[100] , char username[100] , user* usersHead);
void like(int id , user* usersHead , char username[100]);
void logout(user* usersHead , char username[100]);
void info(user* usersHead , char username[100]);
void delete(user* usersHead , char username[100] , int id);
int log_flag = 0;
int main()
{
    char choice[20];
    char username_str[100];
    char login_str[100];
    char password_str[100];
    char username_like[100];
    int postid=0;
    char text[100];
    char search_str[100];
    user* usersHead = NULL;
    printf("Welcome to 'UT TOOTI'\n");
	printf("'UT TOOTI' is a social networking program where users broadcast short posts.\n");
	printf("Press any key to contiue\n");
	getch();
	printf("signup <username> <password>\n");
	printf("login <user name> <password>\n");
	printf("post <text>\n");
	printf("like <user name> <postid>\n");
	printf("logout\n");
	printf("delete <postid>\n");
	printf("info\n");
	printf("find_user <username>\n");
    do
    {
    scanf("%s" , choice);
    if(strcmp(choice,"signup")==0)
    {
    scanf("%s" , username_str);
    scanf("%s" , password_str);
    usersHead = signup(username_str, password_str,usersHead);
    }
    else if(strcmp(choice,"find_user")==0)
    {
    scanf("%s" , search_str);
    search(usersHead , search_str);
    }
    else if(strcmp(choice,"printlist")==0)
    printlist(usersHead);
    else if(strcmp(choice , "login")==0)
    {
    scanf("%s" , login_str);
    scanf("%s" , password_str);
    login(usersHead , username_str , password_str);
    }
    else if(strcmp(choice , "post")==0)
    {
    if(log_flag==1)
    {
    scanf("%s" , text);
    posting(text,login_str,usersHead);
    }
    else printf("You need to login in order to post\n");
    }
    else if(strcmp(choice , "like")==0)
    {
           if(log_flag==1)
    {
        scanf("%s" , username_like);
    scanf("%d" , &postid);
    like(postid , usersHead , username_like);
    }
    else printf("You need to login in order to like\n");
    }
    
    else if(strcmp(choice , "delete")==0)
    {
    if(log_flag==1)
    {
    scanf("%d" , &postid);
    delete(usersHead , login_str , postid);
    }
    else printf("You need to login in order to delete a post\n");
    }
    else if(strcmp(choice , "logout")==0)
    {
         if(log_flag==1)
    {
    logout(usersHead , login_str);
    }
    else printf("You need to login in order to logout\n");
    }
    else if(strcmp(choice , "info")==0)
    {
         if(log_flag==1)
    {
    info(usersHead , login_str);
    }
    else printf("You need to login in order to view info\n");
    }
    }
while(strcmp(choice,"quit")!=0);

}


void printlist(user* usersHead)
{
    user* temp = usersHead;
    while(temp!=NULL)
    {
    printf("%s %s\n" , temp->username , temp->pass);
    temp = temp->next;
    }

}

user* signup(char username[100], char password[100],user* usersHead){
	
user* temp = usersHead;
int flag = 0;
    user* current;
    while(temp!= NULL){
        if(strcmp((temp->username),username)==0){
                      current = temp;
                      printf("Username taken\n");
                      flag = 1;
                        break;
        }
        temp = temp->next;
    }
    if (flag == 0)
    {
    user* newUser = (user*)malloc(sizeof(user));
	strcpy(newUser->username,username);
	strcpy(newUser->pass,password);
	newUser->next = NULL;
	/*adding to users*/
    if(usersHead == NULL)
    usersHead = newUser;
    else
    {
        newUser->next = usersHead;
        usersHead = newUser;

    }
	printf("Successfully signed up\n");
    usersHead->posts = NULL;
	return usersHead;
    }
}

void search(user* usersHead, char username[100])
{
   user* temp = usersHead;
    user* current;
    while(temp!= NULL){
        if(strcmp((temp->username),username)==0){
                      current = temp;
                      printf("Username found\n");
                        break;
        }
        temp = temp->next;
    }
    if(temp == NULL)
    printf("Username not found\n");
    post* tmp = current->posts;
    while(tmp!= NULL){
        printf("id:%d\n" , tmp->id);
		printf("text:%s\n" , tmp->content);
		printf("likes:%d\n" , tmp->likes);
        tmp = tmp->next;
        }

}


void login(user* usersHead , char username[100] , char password[100])
{
user* temp = usersHead;
    while(temp!= NULL){
        if(strcmp((temp->username),username)==0){
            printf("Username found\n");
            if(strcmp((temp->pass),password)==0)
            {
            printf("Sucssessfully logged in\n");
            log_flag=1;
            }
            else printf("Wrong password\n");
            break;
            }
        temp = temp->next;
    }
    if( temp == NULL)
    printf("Username not found\n");
}

void posting(char content[100] , char username[100] , user* usersHead)
{
    user* temp = usersHead;
    user* current;
    while(temp!= NULL){
        if(strcmp((temp->username),username)==0){
                      current = temp;
                        break;
        }
        temp = temp->next;
    }
post* newPost = (post*)malloc(sizeof(post));
newPost->next = NULL;
strcpy(newPost->content,content);
if (current->posts == NULL)
{
    current->posts = newPost;
    newPost->id = 1;
    newPost->likes=0;
}    
else
{
   newPost->next =  current->posts;
   post* temp = current->posts;
   newPost->id = temp->id + 1;
    newPost->likes=0;
   current->posts = newPost;

}
	printf("Successfully Posted\n");

}
void like(int id , user* usersHead , char username[100])
{
    user* temp = usersHead;
    user* current;
    while(temp!= NULL){
        if(strcmp((temp->username),username)==0){
                      current = temp;
                        break;
        }
        temp = temp->next;
    }

    if( temp == NULL)
    printf("Username not found\n");
    else
    {
    post* tmp = current->posts;
    while(tmp!= NULL){
        if((tmp->id)==id){
                       (tmp->likes)++;
                       printf("Successfully liked\n");
                        break;
        }
        tmp = tmp->next;
    }
    if( tmp == NULL)
    printf("Post not found\n");
    }

}

void logout(user* usersHead , char username[100])
{
user* temp = usersHead;
    while(temp!= NULL){
        if(strcmp((temp->username),username)==0){
            printf("Sucssessfully logged out\n");
            log_flag=0;
            }
        temp = temp->next;
    }
   
}

void info(user* usersHead , char username[100])
{
    user* temp = usersHead;
    user* current;
    while(temp!= NULL){
        if(strcmp((temp->username),username)==0){
                      current = temp;
                      printf("username:%s\n" , temp->username);
                      printf("password:%s\n" , temp->pass);
                        break;
        }
        temp = temp->next;
    }
    
    post* tmp = current->posts;
    while(tmp!= NULL){
        
        printf("id:%d\n" , tmp->id);
		printf("text:%s\n" , tmp->content);
		printf("likes:%d\n" , tmp->likes);
        tmp = tmp->next;
    }
    
}

void delete(user* usersHead , char username[100] , int id)
{
    user* temp = usersHead;
    user* current;
    while(temp!= NULL){
        if(strcmp((temp->username),username)==0){
                      current = temp;
                        break;
        }
        temp = temp->next;
    }
    
    post* temp1 = current->posts;
    post* temp2 = current->posts; 

    while(temp1!=NULL){
        
        if(temp1->id==id){
            
            
            if(temp1==temp2){
                current->posts = current->posts->next;
                free(temp1);
                break;
            }
            else{
                temp2->next = temp1->next;
                free(temp1);
                printf("Sucssessfully deleted\n");
                break;
            }
            
        }
        temp2 = temp1;
        temp1 = temp1->next;
        
    }

}










