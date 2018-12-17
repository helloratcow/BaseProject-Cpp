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


	printf("尚未書寫\n");

}


void chat_friend(){
	
	char content[200];
	char exit[]="exit";
	int reback=1;
	printf("進入聊天室...(簡易版)");
	printf("\n============================\n");
	printf("如果要離開聊天室 請輸入'exit'\n");
	while(reback){
		printf("A:");
		scanf("%s",content);
		if(strncmp(exit, content,4) == 0){
			printf("\n");
			printf("即將離開聊天室...");
			reback=0;
			printf("\n============================\n");
		}else{
			
			puts(content);			
		}
	}
}


void delete_friend(){
	

	printf("尚未書寫\n");

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
		printf("請選擇:\n1.查找好友\n2.聊天\n3.刪除\n0.離開(輸入數字以執行)\n\n") ;
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
				printf("無效的指令");
		}
	}
	system("pause");
	return 0;
}


