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
int insert_list();//���U �����୫�Ʊb�� �W�� ���D 
int landing();//�n��  �� ���H�n�� olineUser�S���g���������D 
//-------------------------------//
int add_friend();//�n�ͦC�� �����ӯ୫�ƪ��P�_�����D 
int chat_friend();//�٤��M���{�����D  ���٨S�[�J �³�or�n�� ���A���P�_ 
int delete_friend();//�٨S�س] 
int chatroom();
//-------------------------------//
struct olineUser {//�ثe��@�����Ȧs�n���̸�ƪ��Ŷ� 
	char name[10];
	char account[10];
	int onoff;
	struct olineUser *next;
};

olineUser *newoluser(char name[10],char account[10]);
olineUser *ohead=NULL;

struct ynf {//�A�ݭn���H�i�H���  �n�ͪ�table 
	char name[10];
	char fname[10];//�A�B�ͪ��W�r 
	int open_close;//1�i��� 0���i��� 
	int count;//�n�ͽs��?���� 
	struct ynf *fnext;
};
ynf *newfriend(char name[10],char fname[10],int open_close,int count);
ynf *fhead=NULL;

struct message { //���Ѫ��T����i�h
	char name[10];//�֯d���T�� 
	//int online;char fname[10]
	int line;
	char content[200];
	char fname[10];//�P�ֲ�Ѫ��T�� 
	struct message *next;
};

message *newmsg(char name[10],char fname[10],int line,char content[200]);
message *mhead=NULL;
int main(void) {
	int select=0;
	printf("�P�¨ϥΦ��t��");
	for(int k=0;;k++) {
		
		printf("\n============================\n");
		printf("�п��:\n1.�s�W�b��\n2.�n�J�Τ�\n0.���}\n\n") ;
		scanf("%d",&select);
		switch(select) {
			case(1):
				insert_list();
				break;
			case(2):
				landing();
				break;
			default:
				printf("�L�Ī����O");
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
	
	
	
	for(int k=0;;k++) {
		printf("\n============================\n");
		printf("�п��:\n1.�d��n��\n2.���\n3.�R��\n0.���}(��J�Ʀr�H����)\n\n") ;
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
				printf("�L�Ī����O");
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
olineUser *newoluser(char name[10],char account[10]) {
	olineUser *temp;
	temp=(olineUser*)malloc(sizeof(olineUser));
	strcpy(temp->name,name);
	strcpy(temp->account,account);
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
message *newmsg(char name[10],char fname[10],int line,char content[200]) {
	message *temp;
	temp=(message*)malloc(sizeof(message));
	strcpy(temp->name,name);
	temp->line=line;
	strcpy(temp->fname,fname);
	strcpy(temp->content,content);
	temp->next=NULL;

	return temp;
}

void printList() {
	userinf *ptr;
	ptr=head;
//	printf("\n============================\n");
	while(ptr!=NULL) {
		printf("�b��:%s �W��:%s \n",ptr->account,ptr->name);//
		ptr=ptr->next;
	}
//	printf("\n============================\n");
}

int insert_list() {//�i�H���Ʊb�K�O�@�Ӱ��D 
	int inselect = 0,exit=0;
	while(inselect!=1) {

		char name[10];
		char account[20];
		char passward[20];

		userinf *ptr;
		printf("\n============================\n");
		printf("�b��:");
		scanf("%s",&account);
		printf("�K�X:");
		scanf("%s",&passward);
		printf("�Τ�W��:");
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
	///int	enter=0;
	///while(enter!=1){
	char temp[10];
	char account[20];
	char passward[20];
	userinf *ptr;
	ptr=head;
	olineUser *optr;
	optr=ohead;
	printf("��J�b��:");
	scanf(" %s",account);
	printf("��J�K�X:");
	scanf(" %s",passward);
	if(ptr==NULL) {
		printf("�ثe�S������Τ���U���{��...qq\n");
		printf("�Y�N��^��l����...");
		return 1;
	}
	while(strcmp(account,ptr->account) != 0 &&ptr->next!=NULL) {
		ptr=ptr->next;
	}
	if(ptr->next==NULL&&strcmp(account,ptr->account) != 0) {//�p�G�P�_�b�����~�|�����o�� 
		printf("�b���αK�X��J���~\n");
		printf("�Y�N��^��l����...");
	}
	if(strcmp(account,ptr->account) == 0) {
		if(strcmp(passward,ptr->passward) == 0) {
			printf("welcome %s\n",ptr->name);
			strcpy(temp,ptr->name);
			//printf("����%s",temp);
			
			if(ohead==NULL) {
				ohead=newoluser(temp,ptr->account);
				//printf("����%s",ohead->name);
			} else {//���� 
				optr=ohead;
				while(optr->next!=NULL) {
					optr=optr->next;
				}
				optr->next=newoluser(temp,ptr->account);
				optr->next==NULL;
				printf("����%s",optr->name);
			}
			chatroom();
		} else {
			printf("�b���αK�X��J���~\n");
			printf("�Y�N��^��l����...");
			return 1;
		}
	}
}
int add_friend() {
	printf("\n============================\n");

	olineUser *optr;
	optr=ohead;
	ynf *yptr;
	yptr=fhead;
	
	userinf *ptr;
	ptr=head;
	
	char name[10];//�O�֭n�n�J�n�� 
	char account[10];
	int oc=0,c=0;
	printf("�z�O%s\n",optr->name);//�٭n�פ@�U�޿� �����w�� 
	strcpy(name,optr->name);
	printf("�i�[�J�W��:");
	printf("\n----------------------------\n");
	while(ptr!=NULL) {
		ptr=ptr->next;
		if(strcmp(name,ptr->name)==0){//�o�O�n���̥�������T���]�ӥX�{ 
			ptr=ptr->next;
		}else{
			printf("�b��:%s �W��:%s \n",ptr->account,ptr->name);
			if(ptr->next==NULL){
				printf("�H�W���G\n");
			break;
			}	
		}
		
	}
	printf("\n----------------------------\n");
	
	printf("�п�J�z�Q�[�J���n�ͱb��:");
	scanf("%s",account);
	
	ptr=head;
	while(ptr!=NULL) {//�P�_��J�����S���b�M�椺 
		if(strcmp(account,ptr->account)!=0&&ptr->next!=NULL){
		ptr=ptr->next;
		}
		if(ptr->next==NULL&&strcmp(account,ptr->account)!=0){
		printf("�d�L���H\n");
		break;
		}
		if(strcmp(account,ptr->account)==0){//���F 
			if(strcmp(name,ptr->name)==0){
				printf("�o�O�z���b�����n���˧�!");
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
			printf("�A�i�H�P%s����o!\n",ptr->name);
			printf("\n----------------------------\n");
			break;
			}	
		}	
	}	
}
int chat_friend() {
	int meslock = 1;//1�i�H�ǿ� 0���i�H�ǿ� 0.5; 
	char content[200];
	char name[10];
	char fname[10];
	char exit[]="exit";
	int line=0;
	ynf *yptr;
	yptr=fhead;
	
	olineUser *optr;
	optr=ohead;
	
	message *mptr;
	mptr=mhead;
	//history �n�]�p �ϥΪ̦W�٪��ɤJ
	printf("\n============================\n");
	printf("�w��i�J��Ѥj�U%s\n...²����",optr->name);
	strcpy(name,optr->name);
	printf("�z���n�ͦC��");
	printf("\n----------------------------\n");
	while(yptr!=NULL){
		if(strcmp(name,yptr->name)==0){
		printf("%s\n",yptr->fname);
		yptr=yptr->fnext;
		}else {
			yptr=yptr->fnext;
		}
	}
	printf("\n----------------------------\n");
	printf("��J�z�Q��ܪ��n�ͦW��:");
	scanf("%s",fname);
	yptr=fhead;
	if(yptr==NULL){
		printf("���֥h�[�Ӧn�Ͳ�ѧa!");
	}
	while(yptr!=NULL){
		if(strcmp(fname,yptr->fname)!=0 && yptr->fnext!=NULL){
			yptr=yptr->fnext;
		}
		if(yptr->fnext==NULL&&strcmp(fname,yptr->fname)!=0){
			printf("�z�S�����n��");
			break;
		}
		if(strcmp(fname,yptr->fname)==0){
			printf("�}�l�P%s��ܧa!",fname);
			printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("�p�G�n���}��ѫ� �п�J'exit'\n");
			if(mptr!=NULL){
				printf("�L�h����Ѭ���\n");
				printf("________________________________________________\n");
			}
			while(mptr!=NULL){
				if(strcmp(name,mptr->name)==0&&strcmp(fname,mptr->fname)==0){//�P�_���T���O�_���n�J��----//�|���P�_�O�_����e��Ѫ���H����� 
					printf("                               %s\n",mptr->content);
					mptr=mptr->next;
				}else if(strcmp(fname,mptr->name)==0&&strcmp(name,mptr->fname)){
					printf("%s:%s\n",mptr->name,mptr->content);
					mptr=mptr->next;
				}else{
					mptr=mptr->next;
				}
			}
			for(int k=0;;k++) {
				printf("________________________________________________\n");
				printf("��J�z�n������:");
				scanf("%s",content);
				if(strcmp(exit, content) == 0) {
					printf("\n");
					printf("�Y�N���}��ѫ�...");
					return 1;
					printf("\n============================\n");
				} else { 
					if(meslock==1) {//	loadmeg(content);
						if(mhead==NULL){
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
						}
					}
					printf(":%s\n",content);
					printf("________________________________________________\n");
				}
			}
		}
	}
	
}
int delete_friend() {
	userinf *ptr;
	ptr=head;
	printf("�z���n�ͥؿ�");
	printf("\n----------------------------\n");
	while(ptr!=NULL) {

		printf("�b��:%s �W��:%s \n",ptr->account,ptr->name);//
		ptr=ptr->next;
	}
	printf("\n-----------------------------\n");

}
	/*	userinf user1 = {"Hoby", "d001", "0001", 1234567};
		userinf user2 = {"Alice", "d002", "0002", 6666677};
		printf("�j�M�i�³檺�n�ͤ�...");
		printf("\n============================\n");
		while(reback){
			if(acc==user1.account||pass==user1.passward){
				printf("�i�³�...");
				if(wearefd!=0){
					printf("ID:%d �W��:%s",user2.id,user2.name);
					printf("��J�n�[�J�n�ͪ�ID");
					scanf("%d",friendID);
					if(friendID==user2.id){
						wearefd=1;
						printf("�A�̥i�H��ѤF");
					}else if(friendID==user1.id){
						printf("�����A���HID�L��");
					}else{
						printf("�d�L����");
					}
				}else{
					printf("�S����L�ϥΪ̤F...");
				}



			}else if(acc==user2.account||pass==user2.passward){
				printf("�i�³�...");
				if(wearefd!=0){
					printf("ID:%d �W��:%s",user2.id,user2.name);
				}else{
					printf("�S����L�ϥΪ̤F...");
				}

				if(friendID==user1.id){
				wearefd=1;

				}else if(friendID==user2.id){
					printf("�����A���HID�L��");
				}else{
					printf("�d�L����");
				}
			}
			printf("�p�n���}�п�J'0'�A�_�h�H�N��J�~�����\n");
			scanf("%d",&reback);
		}*/
