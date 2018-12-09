
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

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
		fgets(content,sizeof(content), stdin);
		if(strncmp(exit, content,4) == 0){
			printf("\n");
			printf("即將離開聊天室...");
			reback=0;
			printf("\n============================\n");
		}else{
			printf("A:");
			puts(content);			
		}
	}
}


void delete_friend(){
	

	printf("尚未書寫\n");

}

int main(void)
{
	int select=1,reback=1;
	char content[200];
	char exit[]= "exit";
	printf("//進去系統前要先登錄帳號密碼\n");
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
		}
	}
	system("pause");
	return 0;
}


