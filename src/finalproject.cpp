#include <stdio.h>
#include <stdlib.h>
#include<math.h> 
#include <string.h>

struct userinf{
	char name[10];
	char account[20];
	char passward[20];
	struct userinf *next;	
};

userinf *newUser(char name[10],char account[20],char passward[20]);

void printList();
int insert_list();
int enter_list();
int search_list();

userinf *head=NULL;
//-------------------------------//
void add_friend();
void chat_friend();
void delete_friend();
int chatroom();


struct message{
	char mes;
	int line;
	int canchat;
	struct userinf;
};

int main(void) {
    int select=3;
	while(select!=0){
		printf("\n============================\n");
		printf("�п��:\n1.�s�W�b��\n2.�n�J�Τ�\n0.���}\n\n") ;
		scanf(" %d",&select);	
		switch(select){
			case(1):
				insert_list();
				break;
			case(2):
				enter_list();
				break;
			case(0):
				return 0;
			default:
				printf("�L�Ī����O");
		}
	}
}


void add_friend(){
	printf("\n============================\n");
	printf("�ؿv��...\n");
	//��ƨS��� 
	/*char acc[10],pass[10];	
	int friendID[7];
	int reback=1,wearefd=0;
	userinf user1 = {"Hoby", "d001", "0001", 1234567};
	userinf user2 = {"Alice", "d002", "0002", 6666677}; 
	printf("�j�M�i�[�J���n�ͤ�...");
	printf("\n============================\n");
	while(reback){
		if(acc==user1.account||pass==user1.passward){
			printf("�i�[�J�W��...");
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
			printf("�i�[�J�W��...");
			if(wearefd!=0){
				printf("ID:%d �W��:%s",user2.id,user2.name);
			}else{
				printf("�S����L�ϥΪ̤F...");
			}
			
			if(friendID==user1.id){
			wearefd=1;
			printf("�A�̥i�H��ѤF"); 
			}else if(friendID==user2.id){
				printf("�����A���HID�L��");
			}else{
				printf("�d�L����");
			}
		}
		printf("�p�n���}�п�J'0'�A�_�h�H�N��J�~�����\n");
		scanf("%d",&reback);
	}
	printf("�h�X��...");*/

}
	


void chat_friend(){
	int meslock = 1;//1�i�H�ǿ�0���i�H�ǿ� 
	char content[200];
	char exit[]="exit";
	int reback=1;
	userinf *ptr;
	//history �n�]�p �ϥΪ̦W�٪��ɤJ 
	printf("�i�J��ѫ�...(²����)");
	printf("\n============================\n");
	printf("�p�G�n���}��ѫ� �п�J'exit'\n");
	while(reback){
		
		gets(content);
		if(strcmp(exit, content) == 0){
			printf("\n");
			printf("�Y�N���}��ѫ�...");
			reback=0;
			printf("\n============================\n");
		}else{
			if(meslock=1){
			//	loadmeg(content);
			}
			printf("%s:%s\n",ptr->name,content);	
			//printf("%s:%s\n",name,content);			
		}
	}
}


void delete_friend(){
	//��ƨS��� 
	char acc[10],pass[10];	
	int friendID[7];
	int reback=1,wearefd=0;
	printf("\n============================\n");
	printf("�ؿv��...\n");
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




}

int chatroom(){
	int enter=0,select=1,reback=1;
	char content[200];
	char exit[]= "exit";

	printf("\n============================\n");
	while(select!=0){
		printf("�п��:\n1.�d��n��\n2.���\n3.�R��\n0.���}(��J�Ʀr�H����)\n\n") ;
		scanf(" %d",&select);
		switch(select){
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

userinf *newUser(char account[20],char passward[20],char name[10]){
	userinf *temp;
	temp=(userinf*)malloc(sizeof(userinf));
	strcpy(temp->account,account);
	strcpy(temp->passward,passward);
	strcpy(temp->name,name);
	temp->next=NULL;

	return temp; 
}

void printList(){
	userinf *ptr;
	ptr=head;
	printf("\n============================\n");
	while(ptr!=NULL){
		printf("�b��:%s �K�X:%s �W��:%s \n",ptr->account,ptr->passward,ptr->name);//���\��N�|���ѱ� 
		ptr=ptr->next;
	}
	printf("\n============================\n");
}

int insert_list(){
	int inselect = 0,exit=0;
	while(inselect!=1){
		
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
		if(head==NULL){
			head=newUser(account,passward,name);
		}
	
		else{
			ptr=head;
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			ptr->next=newUser(account,passward,name);
			ptr->next==NULL;
		}
		printList();
		return 1;
	}
}

int enter_list(){
	printf("\n============================\n");
	///int	enter=0;
	///while(enter!=1){
		char name[10];
		char account[20];
		char passward[20];
		int acount = 1;
		userinf *ptr;
		ptr=head;
		printf("��J�b��:");
		scanf(" %s",account);
		printf("��J�K�X:");
		scanf(" %s",&passward);
		if(ptr==NULL){
			printf("�ثe�S������Τ���U���{��...qq\n");
			printf("�Y�N��^��l����...");
			return 1;
		///	enter=1;
		}
		///�j�M�b�� 
		while(strcmp(account,ptr->account) != 0 &&ptr->next!=NULL){
			ptr=ptr->next;
			acount++;
		}
		if(ptr->next==NULL&&strcmp(account,ptr->account) != 0){
			printf("�b���αK�X��J���~\n");
			/*/printf("�p�n���}�п�J 1");
			scanf("%d",&enter);/*/
		}
		if(strcmp(account,ptr->account) == 0){
			if(strcmp(passward,ptr->passward) == 0){
				printf("welcome %s\n",ptr->name);
				chatroom();
			///	enter=1;
			}else{
				printf("�b���αK�X��J���~\n");
				return 1;
			/*/	printf("�p�n���}�п�J 1");
				scanf("%d",&enter);/*/
			}
		}

	///}
}
