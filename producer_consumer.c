#include<stdio.h>
#include<stdlib.h>
int  mutex=1, x, full=0, empty=3;

int wait(int s){
	return --s;}
	
int signal(int s){
	return ++s;}

void produce(){
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	printf("Enter item to produce : ");
	scanf("%d", &x);
	printf("Produced item : %d\n", x);
	mutex=signal(mutex);
	}
	
void consume(){
	
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	printf("consumed item : %d\n", x);
	mutex=signal(mutex);
}	
	


int main()
{
	int opt;
	printf("1. Prodeuce\n2. consume\n3. exit\n");
	while(1){
		printf("Choose option : ");
		scanf("%d", &opt);
		switch(opt){
			case 1: if (mutex==1 && empty!=0)
					produce();
				else printf("buffer full\n");
				break;
			case 2: if (mutex==1 && full!=0)
					consume();
				else printf("buffer empty\n");
				break;
				
			case 3: exit(0);
				}
		}
				
		
}
