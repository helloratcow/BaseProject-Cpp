
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

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
		fgets(content,sizeof(content), stdin);
		if(strncmp(exit, content,4) == 0){
			printf("\n");
			printf("�Y�N���}��ѫ�...");
			reback=0;
			printf("\n============================\n");
		}else{
			printf("A:");
			puts(content);			
		}
	}
}


void delete_friend(){
	

	printf("�|���Ѽg\n");

}

int main(void)
{
	int select=1,reback=1;
	char content[200];
	char exit[]= "exit";
	printf("//�i�h�t�Ϋe�n���n���b���K�X\n");
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
		}
	}
	system("pause");
	return 0;
}


