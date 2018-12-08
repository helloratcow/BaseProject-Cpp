
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void printList(){
	
	printf("\n============================\n");
	
	printf("\n============================\n");
}



void add_friend(){


	printf("沒有書寫\n");

}


void chat_friend(){


	
}


void delete_friend(){
	

	printf("沒有書寫\n");

}

int main(void)
{
	int select=1,reback=1;
	char content[200];
	char exit[]= "exit";
	while(select!=0){
		printf("請選擇:\n1.查找好友\n2.聊天\n3.刪除\n0.離開\n\n") ;
		scanf(" %d",&select);
		switch(select){
			case(1):
				add_friend();
				break;
			case(2):
				printf("進入聊天室...");
				printf("\n============================\n");
				printf("A:");
				fgets(content,sizeof(content), stdin);
				do{
					fgets(content,sizeof(content), stdin);
					if(strcmp(exit, content) == 0){
						printf("即將離開聊天室...");
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


