#include <stdio.h>

typedef struct user user;
typedef struct post post;

struct user
{
char username[100];
char pass[100];
post* posts;
user* next;
};

struct post
{
	char content[100];
	int id;
    int likes;
	post* next;
};