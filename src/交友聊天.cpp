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
		printf("帳號:");
		scanf("%s",acc);
		printf("密碼:");
		scanf("%s",pass);
		printf("\n");
		
		if(strcmp(acc,user1.account) == 0){
			if(strcmp(pass,user1.passward) == 0){
				select=1;
				enter=1;
				//return *acc,*pass;
				printf("welcome Hoby\n");
			}else{
				printf("帳號或密碼錯誤\n");
			}
		}else if(strcmp(acc,user2.account) == 0){
			if(strcmp(pass,user2.passward) == 0){
				select=1;
				enter=1;
				//return acc,pass;
				printf("welcome Alice\n");
			}else{
				printf("帳號或密碼錯誤\n");
			}
		}else{
			printf("帳號或密碼錯誤\n");
		}
	}
	printf("\n============================\n");
}


void add_friend(){
	//資料沒抓到 
	char acc[10],pass[10];	
	int friendID[7];
	int reback=1,wearefd=0;
	userinf user1 = {"Hoby", "d001", "0001", 1234567};
	userinf user2 = {"Alice", "d002", "0002", 6666677}; 
	printf("搜尋可加入的好友中...");
	printf("\n============================\n");
	while(reback){
		if(acc==user1.account||pass==user1.passward){
			printf("可加入名單...");
			if(wearefd!=0){
				printf("ID:%d 名稱:%s",user2.id,user2.name);
				printf("輸入要加入好友的ID");
				scanf("%d",friendID);
				if(friendID==user2.id){
					wearefd=1;
					printf("你們可以聊天了"); 
				}else if(friendID==user1.id){
					printf("此為你本人ID無效");
				}else{
					printf("查無此號");
				}
			}else{
				printf("沒有其他使用者了...");
			}
			
			
		
		}else if(acc==user2.account||pass==user2.passward){
			printf("可加入名單...");
			if(wearefd!=0){
				printf("ID:%d 名稱:%s",user2.id,user2.name);
			}else{
				printf("沒有其他使用者了...");
			}
			
			if(friendID==user1.id){
			wearefd=1;
			printf("你們可以聊天了"); 
			}else if(friendID==user2.id){
				printf("此為你本人ID無效");
			}else{
				printf("查無此號");
			}
		}
		printf("如要離開請輸入'0'，否則隨意輸入繼續執行\n");
		scanf("%d",&reback);
	}
	printf("退出中...");
	printf("\n============================\n");
}
	


void chat_friend(){
	int meslock = 1;//1可以傳輸0不可以傳輸 
	char content[200];
	char exit[]="exit";
	int reback=1;
	//history 要設計 使用者名稱的導入 
	printf("進入聊天室...(簡易版)");
	printf("\n============================\n");
	printf("如果要離開聊天室 請輸入'exit'\n");
	while(reback){
		
		gets(content);
		if(strcmp(exit, content) == 0){
			printf("\n");
			printf("即將離開聊天室...");
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
	//資料沒抓到 
	char acc[10],pass[10];	
	int friendID[7];
	int reback=1,wearefd=0;
	userinf user1 = {"Hoby", "d001", "0001", 1234567};
	userinf user2 = {"Alice", "d002", "0002", 6666677}; 
	printf("搜尋可黑單的好友中...");
	printf("\n============================\n");
	while(reback){
		if(acc==user1.account||pass==user1.passward){
			printf("可黑單...");
			if(wearefd!=0){
				printf("ID:%d 名稱:%s",user2.id,user2.name);
				printf("輸入要加入好友的ID");
				scanf("%d",friendID);
				if(friendID==user2.id){
					wearefd=1;
					printf("你們可以聊天了"); 
				}else if(friendID==user1.id){
					printf("此為你本人ID無效");
				}else{
					printf("查無此號");
				}
			}else{
				printf("沒有其他使用者了...");
			}
			
			
		
		}else if(acc==user2.account||pass==user2.passward){
			printf("可黑單...");
			if(wearefd!=0){
				printf("ID:%d 名稱:%s",user2.id,user2.name);
			}else{
				printf("沒有其他使用者了...");
			}
			
			if(friendID==user1.id){
			wearefd=1;
	
			}else if(friendID==user2.id){
				printf("此為你本人ID無效");
			}else{
				printf("查無此號");
			}
		}
		printf("如要離開請輸入'0'，否則隨意輸入繼續執行\n");
		scanf("%d",&reback);
	}
	printf("退出中...");
	printf("\n============================\n");


}

int main(void)
{
	int enter=0,select=1,reback=1;
	char content[200];
	char exit[]= "exit";

	enterList();

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


