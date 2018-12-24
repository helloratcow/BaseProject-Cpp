#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <string.h>

struct userinf {
	char name[10];
	char account[20];
	char passward[20];
	struct userinf *next;
};

userinf *newUser(char name[10],char account[20],char passward[20]);
userinf *head=NULL;
void printList();
int insert_list();
int landing();
int search_list();
//-------------------------------//
void add_friend();
void chat_friend();
void delete_friend();
int chatroom();
//-------------------------------//
struct olineUser {
	char name[10];
	struct olineUser *next;
};

olineUser *newoluser(char name[10]);
olineUser *ohead=NULL;

struct ynf {
	char name[10];
	char fname[10];
	int open_close;
	int count;
	struct ynf *fnext;
};
ynf *newfriend(char name[10],char fname[10],int open_close,int count);
ynf *fhead=NULL;

struct message { //把聊天的訊息塞進去
	char name[10];
	//int online;
	int line;
	char content[200];
	struct message *next;
};

message *newmsg(char name[10],int line,char content[200]);
message *mhead=NULL;
int main(void) {
	int select=3;
	while(select!=0) {
		printf("\n============================\n");
		printf("請選擇:\n1.新增帳戶\n2.登入用戶\n0.離開\n\n") ;
		scanf("%d",&select);
		switch(select) {
			case(1):
				insert_list();
				break;
			case(2):
				landing();
				break;
			default:
				printf("無效的指令");
				select=3;
				break;
			case(0):
				return 0;
		
		}
	}
}

int chatroom() {
	int enter=0,select=1,reback=1;
	char content[200];
	char exit[]= "exit";

	printf("\n============================\n");
	while(select!=0) {
		printf("請選擇:\n1.查找好友\n2.聊天\n3.刪除\n0.離開(輸入數字以執行)\n\n") ;
		scanf(" %d",&select);
		switch(select) {
			case(1):
				add_friend();
				break;
			case(2):
				chat_friend();
				break;
			case(3):
				delete_friend();
				break;
			case(0):
				return 0;
			default:
				printf("無效的指令");
		}
	}
}

userinf *newUser(char account[20],char passward[20],char name[10]) {
	userinf *temp;
	temp=(userinf*)malloc(sizeof(userinf));
	strcpy(temp->account,account);
	strcpy(temp->passward,passward);
	strcpy(temp->name,name);
	temp->next=NULL;

	return temp;
}

olineUser *newoluser(char name[10]) {
	olineUser *temp;
	temp=(olineUser*)malloc(sizeof(olineUser));
	strcpy(temp->name,name);
	temp->next=NULL;

	return temp;
}

ynf *newfriend(char name[10],char fname[10],int open_close,int count) {
	ynf *temp;
	temp=(ynf*)malloc(sizeof(ynf));
	strcpy(temp->name,name);
	strcpy(temp->fname,fname);
	temp->open_close=open_close;
	temp->count=count;
	temp->fnext=NULL;

	return temp;
}
message *newmsg(char name[10],int line,char content[200]) {
	message *temp;
	temp=(message*)malloc(sizeof(message));
	strcpy(temp->name,name);
	temp->line=line;
	strcpy(temp->content,content);
	temp->next=NULL;

	return temp;
}

void printList() {
	userinf *ptr;
	ptr=head;
	printf("\n============================\n");
	while(ptr!=NULL) {
		printf("帳號:%s 名稱:%s \n",ptr->account,ptr->name);//
		ptr=ptr->next;
	}
	printf("\n============================\n");
}

int insert_list() {//可以重複帳密是一個問題 
	int inselect = 0,exit=0;
	while(inselect!=1) {

		char name[10];
		char account[20];
		char passward[20];

		userinf *ptr;
		printf("\n============================\n");
		printf("帳號:");
		scanf("%s",&account);
		printf("密碼:");
		scanf("%s",&passward);
		printf("用戶名稱:");
		scanf("%s",&name);
		if(head==NULL) {
			head=newUser(account,passward,name);
		}

		else {
			ptr=head;
			while(ptr->next!=NULL) {
				ptr=ptr->next;
			}
			ptr->next=newUser(account,passward,name);
			ptr->next==NULL;
		}
		printList();
		return 1;
	}
}

int landing() {
	printf("\n============================\n");
	///int	enter=0;
	///while(enter!=1){
	char temp[10];
	char account[20];
	char passward[20];
	userinf *ptr;
	ptr=head;
	olineUser *optr;
	optr=ohead;
	printf("輸入帳號:");
	scanf(" %s",account);
	printf("輸入密碼:");
	scanf(" %s",passward);
	if(ptr==NULL) {
		printf("目前沒有任何用戶註冊此程式...qq\n");
		printf("即將返回初始頁面...");
		return 1;
		///	enter=1;
	}
	while(strcmp(account,ptr->account) != 0 &&ptr->next!=NULL) {
		ptr=ptr->next;
	}
	if(ptr->next==NULL&&strcmp(account,ptr->account) != 0) {
		printf("帳號或密碼輸入錯誤\n");
		/*/printf("如要離開請輸入 1");
		scanf("%d",&enter);/*/
	}
	if(strcmp(account,ptr->account) == 0) {
		if(strcmp(passward,ptr->passward) == 0) {
			printf("welcome %s\n",ptr->name);
			strcpy(temp,ptr->name);
			//printf("測試%s",temp);
			
			if(ohead==NULL) {
				ohead=newoluser(temp);
				//printf("測試%s",ohead->name);
			} else {//型式 
				optr=ohead;
				while(optr->next!=NULL) {
					optr=optr->next;
				}
				optr->next=newoluser(temp);
				optr->next==NULL;
			}
			chatroom();
			///	enter=1;
		} else {
			printf("帳號或密碼輸入錯誤\n");
			return 1;
			/*/	printf("如要離開請輸入 1");
				scanf("%d",&enter);/*/
		}
	}


}



void add_friend() {
	printf("\n============================\n");
	printf("建築中...\n");
	olineUser *optr;
	optr=ohead;
	userinf *ptr;
	ptr=head;
	char fname[10];//此要好友名稱 
	char name[10];//是誰要登入好友 
	int oc=0,c=0;
	printf("\n----------------------------\n");
	printf("您是%s\n",optr->name);
	strcpy(name,optr->name);
	printf("可加入名單");
	while(ptr!=NULL) {
		if(strcmp(optr->name,ptr->name)==0){
			
		}else{
			printf("帳號:%s 名稱:%s \n",ptr->account,ptr->name);
		}
		ptr=ptr->next;
	}
	printf("\n----------------------------\n");

	scanf("%s",&fname);
	
	
	
	
	/*if(fhead==NULL){
		oc++;
		c++;
		fhead=newfriend(name,fname,oc,c);
	} else{
		yptr=fhead;
		while(yptr->fnext!=NULL){
			yptr=yptr->fnext;
		}
		oc++;
		c++;
		yptr->fnext=newfriend(temp,name,oc,c);
		yptr->fnext==NULL;
	}*/
	

}
void chat_friend() {
	int meslock = 1;//1可以傳輸0不可以傳輸
	char content[200];
	char exit[]="exit";
	int reback=1;
	userinf *ptr;
	//history 要設計 使用者名稱的導入
	printf("進入聊天室...(簡易版)");
	printf("\n============================\n");
	printf("如果要離開聊天室 請輸入'exit'\n");
	while(reback) {

		gets(content);
		if(strcmp(exit, content) == 0) {
			printf("\n");
			printf("即將離開聊天室...");
			reback=0;
			printf("\n============================\n");
		} else {
			if(meslock=1) {
				//	loadmeg(content);
			}
			printf("%s:%s\n",ptr->name,content);
			//printf("%s:%s\n",name,content);
		}
	}
}


void delete_friend() {
	//資料沒抓到
	int friendID[7];
	int reback=1,wearefd=0;
	userinf *ptr;
	ptr=head;

	printf("\n----------------------------\n");
	printf("您的好友目錄");
	while(ptr!=NULL) {

		printf("帳號:%s 名稱:%s \n",ptr->account,ptr->name);//
		ptr=ptr->next;
	}
	printf("\n-----------------------------\n");
	/*	userinf user1 = {"Hoby", "d001", "0001", 1234567};
		userinf user2 = {"Alice", "d002", "0002", 6666677};
		printf("搜尋可黑單的好友中...");
		printf("\n============================\n");
		while(reback){
			if(acc==user1.account||pass==user1.passward){
				printf("可黑單...");
				if(wearefd!=0){
					printf("ID:%d 名稱:%s",user2.id,user2.name);
					printf("輸入要加入好友的ID");
					scanf("%d",friendID);
					if(friendID==user2.id){
						wearefd=1;
						printf("你們可以聊天了");
					}else if(friendID==user1.id){
						printf("此為你本人ID無效");
					}else{
						printf("查無此號");
					}
				}else{
					printf("沒有其他使用者了...");
				}



			}else if(acc==user2.account||pass==user2.passward){
				printf("可黑單...");
				if(wearefd!=0){
					printf("ID:%d 名稱:%s",user2.id,user2.name);
				}else{
					printf("沒有其他使用者了...");
				}

				if(friendID==user1.id){
				wearefd=1;

				}else if(friendID==user2.id){
					printf("此為你本人ID無效");
				}else{
					printf("查無此號");
				}
			}
			printf("如要離開請輸入'0'，否則隨意輸入繼續執行\n");
			scanf("%d",&reback);
		}*/




}
