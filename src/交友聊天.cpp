#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct{
	char name[10];
	char account[8];
	char passward[8];
	int id[7];
} userinf, *puserinf;

struct message{
	char mes[200];
	int line;
	struct userinf;
	struct message *next;
}*head;

void loadmeg(char content)
{
    struct message *temp,*right;
    temp= (struct message *)malloc(sizeof(struct message));
    temp->mes[200]=content;
    right=(struct message *)head;
    while(right->next != NULL)
    right=right->next;
    //right->next =temp;
    (*right).next = temp;
    right=temp;
    right->next=NULL;
}
void enterList(){
	char acc[10],pass[10];	
	userinf user1 = {"Hoby", "d001", "0001", 1234567};
	userinf user2 = {"Alice", "d002", "0002", 6666677}; 
	int enter=0,select=0,reback=1;
	printf("\n============================\n");
	while(enter!=1){
		printf("�b��:");
		scanf("%s",acc);
		printf("�K�X:");
		scanf("%s",pass);
		printf("\n");
		
		if(strcmp(acc,user1.account) == 0){
			if(strcmp(pass,user1.passward) == 0){
				select=1;
				enter=1;
				//return *acc,*pass;
				printf("welcome Hoby\n");
			}else{
				printf("�b���αK�X���~\n");
			}
		}else if(strcmp(acc,user2.account) == 0){
			if(strcmp(pass,user2.passward) == 0){
				select=1;
				enter=1;
				//return acc,pass;
				printf("welcome Alice\n");
			}else{
				printf("�b���αK�X���~\n");
			}
		}else{
			printf("�b���αK�X���~\n");
		}
	}
	printf("\n============================\n");
}


void add_friend(){
	//��ƨS��� 
	char acc[10],pass[10];	
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
	printf("�h�X��...");
	printf("\n============================\n");
}
	


void chat_friend(){
	int meslock = 1;//1�i�H�ǿ�0���i�H�ǿ� 
	char content[200];
	char exit[]="exit";
	int reback=1;
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
			printf("%s\n",content);	
			//printf("%s:%s\n",name,content);			
		}
	}
}


void delete_friend(){
	//��ƨS��� 
	char acc[10],pass[10];	
	int friendID[7];
	int reback=1,wearefd=0;
	userinf user1 = {"Hoby", "d001", "0001", 1234567};
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
	}
	printf("�h�X��...");
	printf("\n============================\n");


}

int main(void)
{
	int enter=0,select=1,reback=1;
	char content[200];
	char exit[]= "exit";

	enterList();

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
	system("pause");
	return 0;
}


