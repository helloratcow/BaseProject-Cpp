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
	char mes;
	int line;
	struct userinf;
};
void enterList(){
	
	printf("\n============================\n");
	
	printf("\n============================\n");
}



void add_friend(){


	printf("�|���Ѽg\n");

}


void chat_friend(){
	
	char content[200];
	char exit[]="exit";
	int reback=1;
	printf("�i�J��ѫ�...(²����)");
	printf("\n============================\n");
	printf("�p�G�n���}��ѫ� �п�J'exit'\n");
	while(reback){
		printf("A:");
		scanf("%s",content);
		if(strncmp(exit, content,4) == 0){
			printf("\n");
			printf("�Y�N���}��ѫ�...");
			reback=0;
			printf("\n============================\n");
		}else{
			
			puts(content);			
		}
	}
}


void delete_friend(){
	

	printf("�|���Ѽg\n");

}

int main(void)
{
	char acc[10],pass[10];
	userinf user1 = {"Hoby", "d001", "0001", 1234567};
	userinf user2 = {"Alice", "d002", "0002", 6666677}; 
	int enter=0,select=5,reback=1;
	char content[200];
	char exit[]= "exit";
	

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


