
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void printList(){
	
	printf("\n============================\n");
	
	printf("\n============================\n");
}



void add_friend(){


	printf("�S���Ѽg\n");

}


void chat_friend(){


	
}


void delete_friend(){
	

	printf("�S���Ѽg\n");

}

int main(void)
{
	int select=1,reback=1;
	char content[200];
	char exit[]= "exit";
	while(select!=0){
		printf("�п��:\n1.�d��n��\n2.���\n3.�R��\n0.���}\n\n") ;
		scanf(" %d",&select);
		switch(select){
			case(1):
				add_friend();
				break;
			case(2):
				printf("�i�J��ѫ�...");
				printf("\n============================\n");
				printf("A:");
				fgets(content,sizeof(content), stdin);
				do{
					fgets(content,sizeof(content), stdin);
					if(strcmp(exit, content) == 0){
						printf("�Y�N���}��ѫ�...");
						reback=0;
					}else{
						puts(content);
						printf("A:");
					
					}
				}while(reback);
				
				break;
			case(3):
				delete_friend();
				break;
		

		}
	}

	system("pause");
	return 0;
}


