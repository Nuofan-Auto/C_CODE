#pragma once

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
//类型的声明
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

typedef struct Contact
{
	PeoInfo data[MAX];//存放人的信息
	int count;//记录当前通讯录中人的个数
}Contact;

//初始化通讯录
void InitContact(Contact* pc);

//增加联系人到通讯录
void AddContact(Contact* pc);

//打印通讯录信息
void ShowContact(Contact* pc);

//删除指定联系人
void DelContact(Contact* pc);

//查找指定联系人
void SearchContact(Contact* pc);

//修改通讯录信息
void ModifyContact(Contact* pc);

//排序通讯录中的内容
void SortContact(Contact* pc);

