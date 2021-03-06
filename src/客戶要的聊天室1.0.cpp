#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <string.h>

struct userinf {//註冊者資料(庫?) 
	char name[10];
	char account[20];
	char passward[20];
	struct userinf *next;
};

userinf *newUser(char name[10],char account[20],char passward[20]);
userinf *head=NULL;
void printList();
int insert_list();//註冊 有不能重複帳號 名稱 問題 
int landing();//登陸  有 換人登陸 olineUser沒有寫完善的問題
//-------------------------------//
int chatroom();
int add_friend();//好友列表 不應該能重複的判斷式問題 
int chat_friend();//還不清楚現有問題  但還沒加入 黑單or好友 狀態的判斷 
int delete_friend();// 
int off_line();
//-------------------------------//
struct olineUser {//上線的登錄者資料(庫) 
	char name[10];
	char account[10];
	int onoff; //1 online, 0 offline 
	struct olineUser *next;
};
olineUser *newoluser(char name[10],char account[10],int onoff);
olineUser *ohead=NULL;

struct localinfo{//單純只紀錄當前用戶端的資料? 
	char name[10];
	struct localinfo *lnext;
};
localinfo *templocalinfo(char name[10]);
localinfo *lhead=NULL;

struct ynf {//所有登錄者的好友資料(庫?) 你需要有人可以聊天  好友的table 
	char name[10];
	char fname[10];//你朋友的名字 
	int open_close;//1可聊天 0不可聊天 //尚未加入 
	int count;//好友編號?順序 
	struct ynf *fnext;
};
ynf *newfriend(char name[10],char fname[10],int open_close,int count);
ynf *fhead=NULL;

struct message { //所有的登錄者對好友的聊天的訊息 資料(庫?) 
	char name[10];//誰留的訊息 
	int line;
	char content[200];
	char fname[10];//與誰聊天的訊息 
	int nf; 
	int fn;
	struct message *next;
};
message *newmsg(char name[10],char fname[10],int line,char content[200],int nf,int fn);
message *mhead=NULL;

int main(void) {
	int select=0;
	printf("感謝使用此系統");
	for(int k=0;;k++) {
		
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
				break;
			case(0):
				return 0;
		}
	}
}

int chatroom() {
	int select=1;
	
	for(int k=0;;k++) {
		printf("\n===============================================\n");
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
				off_line();
				return 1;
			default:
				printf("無效的指令");
				break;
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
olineUser *newoluser(char name[10],char account[10],int onoff) {
	olineUser *temp;
	temp=(olineUser*)malloc(sizeof(olineUser));
	strcpy(temp->name,name);
	strcpy(temp->account,account);
	temp->onoff=onoff;
	temp->next=NULL;

	return temp;
}
localinfo *templocalinfo(char name[10]){//本地端存取方式測試中... 
	localinfo *temp;
	temp=(localinfo*)malloc(sizeof(localinfo));
	strcpy(temp->name,name);
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
message *newmsg(char name[10],char fname[10],int line,char content[200],int nf,int fn) {
	message *temp;
	temp=(message*)malloc(sizeof(message));
	strcpy(temp->name,name);
	temp->line=line;
	strcpy(temp->fname,fname);
	strcpy(temp->content,content);
	temp->nf=nf;
	temp->fn=fn;
	temp->next=NULL;

	return temp;
}

void printList() {//印出可加入好友用 //中間測試用的不用理 
	userinf *ptr;
	ptr=head;
//	printf("\n============================\n");
	while(ptr!=NULL) {
		printf("帳號:%s 名稱:%s \n",ptr->account,ptr->name);//
		ptr=ptr->next;
	}
//	printf("\n============================\n");
}

int insert_list() {//可以重複帳密是一個問題  迴圈好像可以再修改 
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
		//printList();
		return 1;
	}
}
int landing() {
	printf("\n============================\n");
	char temp[10];
	char account[20];
	char passward[20];
	userinf *ptr;
	ptr=head;
	olineUser *optr;
	optr=ohead;
	localinfo *lptr;
	lptr=lhead;
	printf("輸入帳號:");
	scanf(" %s",account);
	printf("輸入密碼:");
	scanf(" %s",passward);
	if(ptr==NULL) {
		printf("目前沒有任何用戶註冊此程式...qq\n");
		printf("即將返回登陸頁面...");
		return 1;
	}
	while(strcmp(account,ptr->account) != 0 &&ptr->next!=NULL) {
		ptr=ptr->next;
	}
	if(ptr->next==NULL&&strcmp(account,ptr->account) != 0) {//如果判斷帳號錯誤會先跳這個 
		printf("帳號或密碼輸入錯誤\n");
		printf("即將返回登陸頁面...");
	}
	if(strcmp(account,ptr->account) == 0) {
		if(strcmp(passward,ptr->passward) == 0) {
			printf("\n----------------\n");
			printf("Welcome %s\n",ptr->name);
			strcpy(temp,ptr->name);//登陸 本地端使用者 
			//printf("temp測試%s\n",temp);
			printf("\n----------------\n");
			
			if(lhead==NULL){
				lhead=templocalinfo(ptr->name);
				//printf("實際測試%s",lhead->name);
			}else{
				lptr=lhead;
				lhead=templocalinfo(ptr->name);
				//printf("實際測試%s",lhead->name);
			}	
			if(ohead==NULL) {
				ohead=newoluser(temp,ptr->account,1);
				//printf("測試%s",ohead->name);
			} else {//型式 
				optr=ohead;
				while(optr->next!=NULL) {
					optr=optr->next;
				}
				optr->next=newoluser(temp,ptr->account,1);
				optr->next==NULL;
			}
			chatroom();
		} else {
			printf("帳號或密碼輸入錯誤\n");
			printf("即將返回登陸頁面...");
			return 1;
		}
	}
}
int add_friend() {
	printf("\n===============================================\n");

	olineUser *optr;
	optr=ohead;
	
	ynf *yptr;
	yptr=fhead;
	
	userinf *ptr;
	ptr=head;
	
	char name[10];//是誰要登入好友 
	char account[10];
	int oc=0,c=0;
	printf("您是%s\n",optr->name);//登錄者才能加好友 還要修一下邏輯 此為定數 
	strcpy(name,optr->name);
	//printf(" %s",name);
	printf("可加入名單:");
	printf("\n-----------------------------------------------\n");
	while(ptr!=NULL) {
		if(strcmp(name,ptr->name)==0){//這是登錄者本身的資訊不因該出現 
			ptr=ptr->next;
		}else{
			printf("帳號:%s 名稱:%s \n",ptr->account,ptr->name);
			if(ptr->next==NULL){
				printf("\n以上結果");
			break;
			}
			ptr=ptr->next;	
		}
	}
	printf("\n-----------------------------------------------\n");
	
	printf("請輸入您想加入的好友'帳號'!: ");
	scanf("%s",account);
	
	ptr=head;
	while(ptr!=NULL) {//判斷輸入的有沒有在清單內 
		if(strcmp(account,ptr->account)!=0&&ptr->next!=NULL){
		ptr=ptr->next;
		}
		if(ptr->next==NULL&&strcmp(account,ptr->account)!=0){
		printf("查無此人\n");
		break;
		}
		if(strcmp(account,ptr->account)==0){//找到了 
			if(strcmp(name,ptr->name)==0){//判斷打自己的資訊 
				printf("這是您的帳號不要玩弄我!\n");
				break;
			}else{
				if(fhead==NULL){
					oc=1;
					c++;
					fhead=newfriend(name,ptr->name,oc,c);
				} else{
					yptr=fhead;
					c=1;
					while(yptr->fnext!=NULL){
					yptr=yptr->fnext;
					c++;
				}
				oc=1;
				c++;
				yptr->fnext=newfriend(name,ptr->name,oc,c);
				yptr->fnext==NULL;
			}
			printf("你可以與 '%s' 聊天囉!\n",ptr->name);
			printf("\n-----------------------------------------------\n");
			break;
			}	
		}	
	}	
}
int chat_friend() {
	int meslock = 1;//1可以傳輸 0不可以傳輸 0.5; 
	char content[200];
	char name[10];
	char fname[10];
	char exit[]="exit";
	int line=0,num=0;
	ynf *yptr;
	yptr=fhead;
	
	olineUser *optr;
	optr=ohead;
	
	message *mptr;
	mptr=mhead;
	//history 要設計 使用者名稱的導入
	printf("\n===============================================\n");
	printf("歡迎進入聊天室 %s \n...簡易版\n",optr->name);
	strcpy(name,optr->name);
	printf("您的好友列表");
	printf("\n-----------------------------------------------\n");
	if(yptr==NULL){
		//printf("1");//判斷 
		printf("您還沒有好友可以聊天,快去加一個朋友來聊天吧!\n");
		return 1;
	}
	while(yptr!=NULL){//
		if(strcmp(name,yptr->name)==0){
			printf("%s\n",yptr->fname);
			num++;
		}
		if(strcmp(name,yptr->name)!=0&&yptr->fnext==NULL){
			if(num==0){
				//printf("2");//判斷 
				printf("您還沒有好友可以聊天,快去加一個朋友來聊天吧!\n");
				return 1;
			}else{
				printf("\n以上結果\n");
			}
		}
		yptr=yptr->fnext;
	}
	printf("\n-----------------------------------------------\n");
	printf("輸入您想對話的好友名稱:");
	scanf("%s",fname);
	yptr=fhead;
	
	while(yptr!=NULL){
		if(strcmp(fname,yptr->fname)!=0 && yptr->fnext!=NULL){
			yptr=yptr->fnext;		
		}
		if(yptr->fnext==NULL&&strcmp(fname,yptr->fname)!=0){
			if(strcmp(name,fname)==0){
				printf("不要跟自己說話,搞自閉啦!");
			}else{
				printf("\n您沒有此好友");
				printf("將返回交友大廳");
			}
			break;
		}
		if(strcmp(fname,yptr->fname)==0){
			
			printf("開始與%s對話吧!",fname);
			printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("如果要離開聊天室 請輸入'exit'\n");
			printf("當讀到空白鍵會變成下一行\n");
			printf("\n\n");
			if(mptr!=NULL){
				printf("過去的聊天紀錄\n");
				printf("________________________________________________\n");
			}
			while(mptr!=NULL){
				if(strcmp(name,mptr->name)==0&&strcmp(fname,mptr->fname)==0){//判斷此訊息是否為登入者----//判斷是否為當前聊天的對象的對話 
					printf("                               %s\n",mptr->content);
				}
				if(strcmp(fname,mptr->name)==0&&strcmp(name,mptr->fname)==0){//好友的訊息 
					/*if(yptr->open_close==0){這個打開會把好友訊息都砍了 
						printf("");
					}else{
						printf("%s:%s\n",mptr->name,mptr->content);
					}*/
					if(mptr->fn==0){
						printf("您已將此朋友封鎖\n");
						break;
					}else{
						printf("%s:%s\n",mptr->name,mptr->content);
					}
					//printf("%s:%s\n",mptr->name,mptr->content);
				}
				mptr=mptr->next;
			}
			for(int k=0;;k++) {
				printf("________________________________________________\n");
				printf("輸入您要說的話:");
				scanf("%s",content);
				if(strcmp(exit, content) == 0) {
					printf("\n");
					printf("即將離開聊天室...");
					return 1;
					printf("\n===============================================\n");
				} else { 
					if(meslock==1) {//	loadmeg(content);
						/*if(mhead==NULL){//原本可以的尚未做聊天開關 
							line=1;
							mhead=newmsg(name,fname,line,content);
						}else{
							mptr=mhead;
							while(mptr->next!=NULL){
								mptr=mptr->next;
								line++;
							}
							mptr->next=newmsg(name,fname,line,content);
							mptr->next==NULL; 
						}*/ 
						if(mhead==NULL){
							line=1;
							if(yptr->open_close==1){
								mhead=newmsg(name,fname,line,content,1,1);
							}else{
								mhead=newmsg(name,fname,line,content,1,0);
							}	
						}else{
							mptr=mhead;
							while(mptr->next!=NULL){
								mptr=mptr->next;
								line++;
							}
							if(yptr->open_close==1){
								mptr->next=newmsg(name,fname,line,content,1,1);
								mptr->next==NULL; 
							}else{
								mptr->next=newmsg(name,fname,line,content,1,0);
							}
							
						}
					}
					printf("                                 %s\n",content);
				}
			}
		}
	}	
}
int delete_friend() {
	char name[10];
	char fname[10];
	userinf *ptr;
	ptr=head;
	
	olineUser *optr;
	optr=ohead;
	
	ynf *yptr;
	yptr=fhead;
	
	printf("\n===============================================\n");
	printf("您好您是 %s",optr->name);
	
	strcpy(name,optr->name);
	printf("您的好友列表");
	printf("\n----------------------------\n");
	while(yptr!=NULL){//沒有好友要退出 (? 
		if(strcmp(name,yptr->name)==0){
		printf("%s\n",yptr->fname);
		yptr=yptr->fnext;
		}else {
			yptr=yptr->fnext;
		}
	}
	printf("\n-----------------------------------------------\n");
	printf("輸入您想黑掉的好友名稱:");//還沒判斷完!!! 
	scanf("%s",fname);
	yptr=fhead;
	
	while(yptr!=NULL){
		if(strcmp(fname,yptr->fname)!=0 && yptr->fnext!=NULL){
			yptr=yptr->fnext;
		}
		if(yptr->fnext==NULL&&strcmp(fname,yptr->fname)!=0){
			printf("您沒有此好友");
			break;
		}
		if(strcmp(fname,yptr->fname)==0){//如果相符合黑掉 //尚未做動作 
			yptr->open_close=0;
			printf("此後他的訊息將不會顯示!\n");//*newfriend(char name[10],char fname[10],int open_close,int count);
		//	printf("%s %s %d %d",yptr->name,yptr->fname,yptr->open_close,yptr->count);
			break;
		} 
	}
}
int off_line(){//實作連線因該會要有ex:線上第幾人的問題 下線 
	olineUser *optr;
	optr=ohead;//目前設下線為0上線為1 
	
	localinfo *lptr;
	lptr=lhead;
	//if(ohead==NULL) ,if(ohead->onoff==0)//不因該發生 
	if(strcmp(optr->name,lptr->name)==0&&ohead->onoff==1){//上線者第一筆資料就是本地使用者//但不是是用者的可能性.... //重製head 
		ohead=NULL;
		lhead=NULL;
		//printf("%s %s",lhead->name,ohead->name);
		printf("\n雖然很難過,期待下次您的使用");
		return 1;
	}
	while(strcmp(ohead->name,lptr->name)!=0 &&optr->next!=NULL){//登錄者與本地使用者不吻合 
		optr=optr->next;
	}
	if(optr->next==NULL&&strcmp(optr->name,lptr->name)!=0){//到最後一筆登錄者資料都沒有吻合的本地端資訊 
		printf("out land error\n");//不確定會不會有這bug 
	}
	if(strcmp(optr->name,lptr->name)==0&&optr->onoff==1){//本地端資訊與登錄者資訊相同且為上線狀態 
		optr->next=optr->next->next;
		lhead=NULL;
	//	printf("%s %s",optr->name,lptr->name);
		printf("雖然很難過,期待下次您的使用");
		return 1;
	}else{
		printf("bug是啥呢...\n");
		return 1;
	}

}

