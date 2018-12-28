#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <string.h>

struct userinf {//���U�̸��(�w?) 
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
int chatroom();
int add_friend();//�n�ͦC�� �����ӯ୫�ƪ��P�_�����D 
int chat_friend();//�٤��M���{�����D  ���٨S�[�J �³�or�n�� ���A���P�_ 
int delete_friend();// 
int off_line();
//-------------------------------//
struct olineUser {//�W�u���n���̸��(�w) 
	char name[10];
	char account[10];
	int onoff; //1 online, 0 offline 
	struct olineUser *next;
};
olineUser *newoluser(char name[10],char account[10],int onoff);
olineUser *ohead=NULL;

struct localinfo{//��¥u������e�Τ�ݪ����? 
	char name[10];
	struct localinfo *lnext;
};
localinfo *templocalinfo(char name[10]);
localinfo *lhead=NULL;

struct ynf {//�Ҧ��n���̪��n�͸��(�w?) �A�ݭn���H�i�H���  �n�ͪ�table 
	char name[10];
	char fname[10];//�A�B�ͪ��W�r 
	int open_close;//1�i��� 0���i��� //�|���[�J 
	int count;//�n�ͽs��?���� 
	struct ynf *fnext;
};
ynf *newfriend(char name[10],char fname[10],int open_close,int count);
ynf *fhead=NULL;

struct message { //�Ҧ����n���̹�n�ͪ���Ѫ��T�� ���(�w?) 
	char name[10];//�֯d���T�� 
	int line;
	char content[200];
	char fname[10];//�P�ֲ�Ѫ��T�� 
	int nf; 
	int fn;
	struct message *next;
};
message *newmsg(char name[10],char fname[10],int line,char content[200],int nf,int fn);
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
	int select=1;
	
	for(int k=0;;k++) {
		printf("\n===============================================\n");
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
				off_line();
				return 1;
			default:
				printf("�L�Ī����O");
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
localinfo *templocalinfo(char name[10]){//���a�ݦs���覡���դ�... 
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

void printList() {//�L�X�i�[�J�n�ͥ� //�������եΪ����βz 
	userinf *ptr;
	ptr=head;
//	printf("\n============================\n");
	while(ptr!=NULL) {
		printf("�b��:%s �W��:%s \n",ptr->account,ptr->name);//
		ptr=ptr->next;
	}
//	printf("\n============================\n");
}

int insert_list() {//�i�H���Ʊb�K�O�@�Ӱ��D  �j��n���i�H�A�ק� 
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
	char temp[10];
	char account[20];
	char passward[20];
	userinf *ptr;
	ptr=head;
	olineUser *optr;
	optr=ohead;
	localinfo *lptr;
	lptr=lhead;
	printf("��J�b��:");
	scanf(" %s",account);
	printf("��J�K�X:");
	scanf(" %s",passward);
	if(ptr==NULL) {
		printf("�ثe�S������Τ���U���{��...qq\n");
		printf("�Y�N��^�n������...");
		return 1;
	}
	while(strcmp(account,ptr->account) != 0 &&ptr->next!=NULL) {
		ptr=ptr->next;
	}
	if(ptr->next==NULL&&strcmp(account,ptr->account) != 0) {//�p�G�P�_�b�����~�|�����o�� 
		printf("�b���αK�X��J���~\n");
		printf("�Y�N��^�n������...");
	}
	if(strcmp(account,ptr->account) == 0) {
		if(strcmp(passward,ptr->passward) == 0) {
			printf("\n----------------\n");
			printf("Welcome %s\n",ptr->name);
			strcpy(temp,ptr->name);//�n�� ���a�ݨϥΪ� 
			//printf("temp����%s\n",temp);
			printf("\n----------------\n");
			
			if(lhead==NULL){
				lhead=templocalinfo(ptr->name);
				//printf("��ڴ���%s",lhead->name);
			}else{
				lptr=lhead;
				lhead=templocalinfo(ptr->name);
				//printf("��ڴ���%s",lhead->name);
			}	
			if(ohead==NULL) {
				ohead=newoluser(temp,ptr->account,1);
				//printf("����%s",ohead->name);
			} else {//���� 
				optr=ohead;
				while(optr->next!=NULL) {
					optr=optr->next;
				}
				optr->next=newoluser(temp,ptr->account,1);
				optr->next==NULL;
			}
			chatroom();
		} else {
			printf("�b���αK�X��J���~\n");
			printf("�Y�N��^�n������...");
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
	
	char name[10];//�O�֭n�n�J�n�� 
	char account[10];
	int oc=0,c=0;
	printf("�z�O%s\n",optr->name);//�n���̤~��[�n�� �٭n�פ@�U�޿� �����w�� 
	strcpy(name,optr->name);
	//printf(" %s",name);
	printf("�i�[�J�W��:");
	printf("\n-----------------------------------------------\n");
	while(ptr!=NULL) {
		if(strcmp(name,ptr->name)==0){//�o�O�n���̥�������T���]�ӥX�{ 
			ptr=ptr->next;
		}else{
			printf("�b��:%s �W��:%s \n",ptr->account,ptr->name);
			if(ptr->next==NULL){
				printf("\n�H�W���G");
			break;
			}
			ptr=ptr->next;	
		}
	}
	printf("\n-----------------------------------------------\n");
	
	printf("�п�J�z�Q�[�J���n��'�b��'!: ");
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
			if(strcmp(name,ptr->name)==0){//�P�_���ۤv����T 
				printf("�o�O�z���b�����n���˧�!\n");
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
			printf("�A�i�H�P '%s' ����o!\n",ptr->name);
			printf("\n-----------------------------------------------\n");
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
	int line=0,num=0;
	ynf *yptr;
	yptr=fhead;
	
	olineUser *optr;
	optr=ohead;
	
	message *mptr;
	mptr=mhead;
	//history �n�]�p �ϥΪ̦W�٪��ɤJ
	printf("\n===============================================\n");
	printf("�w��i�J��ѫ� %s \n...²����\n",optr->name);
	strcpy(name,optr->name);
	printf("�z���n�ͦC��");
	printf("\n-----------------------------------------------\n");
	if(yptr==NULL){
		//printf("1");//�P�_ 
		printf("�z�٨S���n�ͥi�H���,�֥h�[�@�ӪB�ͨӲ�ѧa!\n");
		return 1;
	}
	while(yptr!=NULL){//
		if(strcmp(name,yptr->name)==0){
			printf("%s\n",yptr->fname);
			num++;
		}
		if(strcmp(name,yptr->name)!=0&&yptr->fnext==NULL){
			if(num==0){
				//printf("2");//�P�_ 
				printf("�z�٨S���n�ͥi�H���,�֥h�[�@�ӪB�ͨӲ�ѧa!\n");
				return 1;
			}else{
				printf("\n�H�W���G\n");
			}
		}
		yptr=yptr->fnext;
	}
	printf("\n-----------------------------------------------\n");
	printf("��J�z�Q��ܪ��n�ͦW��:");
	scanf("%s",fname);
	yptr=fhead;
	
	while(yptr!=NULL){
		if(strcmp(fname,yptr->fname)!=0 && yptr->fnext!=NULL){
			yptr=yptr->fnext;		
		}
		if(yptr->fnext==NULL&&strcmp(fname,yptr->fname)!=0){
			if(strcmp(name,fname)==0){
				printf("���n��ۤv����,�d�۳���!");
			}else{
				printf("\n�z�S�����n��");
				printf("�N��^��ͤj�U");
			}
			break;
		}
		if(strcmp(fname,yptr->fname)==0){
			
			printf("�}�l�P%s��ܧa!",fname);
			printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("�p�G�n���}��ѫ� �п�J'exit'\n");
			printf("��Ū��ť���|�ܦ��U�@��\n");
			printf("\n\n");
			if(mptr!=NULL){
				printf("�L�h����Ѭ���\n");
				printf("________________________________________________\n");
			}
			while(mptr!=NULL){
				if(strcmp(name,mptr->name)==0&&strcmp(fname,mptr->fname)==0){//�P�_���T���O�_���n�J��----//�P�_�O�_����e��Ѫ���H����� 
					printf("                               %s\n",mptr->content);
				}
				if(strcmp(fname,mptr->name)==0&&strcmp(name,mptr->fname)==0){//�n�ͪ��T�� 
					/*if(yptr->open_close==0){�o�ӥ��}�|��n�ͰT������F 
						printf("");
					}else{
						printf("%s:%s\n",mptr->name,mptr->content);
					}*/
					if(mptr->fn==0){
						printf("�z�w�N���B�ͫ���\n");
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
				printf("��J�z�n������:");
				scanf("%s",content);
				if(strcmp(exit, content) == 0) {
					printf("\n");
					printf("�Y�N���}��ѫ�...");
					return 1;
					printf("\n===============================================\n");
				} else { 
					if(meslock==1) {//	loadmeg(content);
						/*if(mhead==NULL){//�쥻�i�H���|������Ѷ}�� 
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
	printf("�z�n�z�O %s",optr->name);
	
	strcpy(name,optr->name);
	printf("�z���n�ͦC��");
	printf("\n----------------------------\n");
	while(yptr!=NULL){//�S���n�ͭn�h�X (? 
		if(strcmp(name,yptr->name)==0){
		printf("%s\n",yptr->fname);
		yptr=yptr->fnext;
		}else {
			yptr=yptr->fnext;
		}
	}
	printf("\n-----------------------------------------------\n");
	printf("��J�z�Q�±����n�ͦW��:");//�٨S�P�_��!!! 
	scanf("%s",fname);
	yptr=fhead;
	
	while(yptr!=NULL){
		if(strcmp(fname,yptr->fname)!=0 && yptr->fnext!=NULL){
			yptr=yptr->fnext;
		}
		if(yptr->fnext==NULL&&strcmp(fname,yptr->fname)!=0){
			printf("�z�S�����n��");
			break;
		}
		if(strcmp(fname,yptr->fname)==0){//�p�G�۲ŦX�±� //�|�����ʧ@ 
			yptr->open_close=0;
			printf("����L���T���N���|���!\n");//*newfriend(char name[10],char fname[10],int open_close,int count);
		//	printf("%s %s %d %d",yptr->name,yptr->fname,yptr->open_close,yptr->count);
			break;
		} 
	}
}
int off_line(){//��@�s�u�]�ӷ|�n��ex:�u�W�ĴX�H�����D �U�u 
	olineUser *optr;
	optr=ohead;//�ثe�]�U�u��0�W�u��1 
	
	localinfo *lptr;
	lptr=lhead;
	//if(ohead==NULL) ,if(ohead->onoff==0)//���]�ӵo�� 
	if(strcmp(optr->name,lptr->name)==0&&ohead->onoff==1){//�W�u�̲Ĥ@����ƴN�O���a�ϥΪ�//�����O�O�Ϊ̪��i���.... //���shead 
		ohead=NULL;
		lhead=NULL;
		//printf("%s %s",lhead->name,ohead->name);
		printf("\n���M�����L,���ݤU���z���ϥ�");
		return 1;
	}
	while(strcmp(ohead->name,lptr->name)!=0 &&optr->next!=NULL){//�n���̻P���a�ϥΪ̤��k�X 
		optr=optr->next;
	}
	if(optr->next==NULL&&strcmp(optr->name,lptr->name)!=0){//��̫�@���n���̸�Ƴ��S���k�X�����a�ݸ�T 
		printf("out land error\n");//���T�w�|���|���obug 
	}
	if(strcmp(optr->name,lptr->name)==0&&optr->onoff==1){//���a�ݸ�T�P�n���̸�T�ۦP�B���W�u���A 
		optr->next=optr->next->next;
		lhead=NULL;
	//	printf("%s %s",optr->name,lptr->name);
		printf("���M�����L,���ݤU���z���ϥ�");
		return 1;
	}else{
		printf("bug�Oԣ�O...\n");
		return 1;
	}

}

