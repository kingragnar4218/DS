#include <stdio.h>
int stack[5];
int top = -1;

void push();
void pop();
void peep();
void change();
void display();

int main() {
	
	
    int select ;
    
    while (1) {
        
        printf("\nStack Menu\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEP\n");
        printf("4. CHANGE\n");
        printf("5. DISPLAY\n");
        printf("6. Exit\n");
        printf("select your opration : ");
        scanf("%d", &select);
        
        switch (select) {
            case 1:
                push();
                break;
            case 2 : 
				pop();
				break;	    
            case 3 : 
				peep();
				break;
			case 4 : 
				change();
				break;
			case 5 : 
				display();
				break;
			case 6 : 
				printf("exit program ");
				return 0 ;
				break;	
            default:
                printf("Invalid select  try again.\n");
        }
    }
    return 0;
}


void push() {
	int val;
	if(top == top-1 ){
		printf("stack is full you not enter number ");
	}
	else{
		printf("enter number to push :");
		scanf("%d" , &val);
		top++;
		stack[top]=val;
		printf("number is enter in stack ------");
	}	

}
void pop(){
	if(top == -1)
	{
		printf("stack is empty \n  ");
	}
	else {
		printf("delete top of number  %d\n" , stack[top]);
		top--;
	}
}
void peep(){
	if(top == -1)
	{
		printf("stack is empty \n  ");
	}
	else {
		printf(" top of number  %d\n" , stack[top]);
		
	}
}
	void change(){
		int new_val;
		if(top == -1)
		{
			printf("stack is empty \n  ");
		}
		else {
			printf("enter new number to change this  %d\n" );\
			scanf("%d" , &new_val);
			stack[top]=new_val;
			printf("number is change to  %d\n" , new_val );\
			
		}
	}
	void display() {
	
    
    if (top == -1) {
        printf("Stack is empty! No elements to change.\n");
    } else {
    for(int i = top ; i >= 0 ; i--){
    	printf("%d\n" , stack[i]);
	}    
    }
}