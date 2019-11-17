#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char a[15], b[15], c[15], buf[15];
	int loc, sa, d;
	FILE *fp=fopen("input.txt", "r");
	FILE *symtab=fopen("symtab.txt", "w");
	FILE *inter=fopen("inter.txt", "w");
	fscanf(fp, "%s %s %d", a, b, &d);
	if (strcmp(b,"START")==0)
	{
		sa=d;
		loc=sa;
	}
	else
	{
		loc=0;
		
	}
	while(fgets(buf, sizeof(buf), fp)!=NULL)
	{
		fscanf(fp, "%s %s %s", a, b, c);
		if (strcmp(a, "-")!=0) 
		{
			if (strcmp(b, "WORD")==0){ 			//replace if - else if with OPTAB
				fprintf(inter, "\n%d %s\t%s\t%s\n", loc, a, b, c);
				fprintf(symtab, "\n%s %d\n", a, loc);
				loc+=3;}
				
			else if (strcmp(b, "RESW")==0){
				fprintf(inter, "\n%d %s\t%s\t%s\n", loc, a, b, c);
				fprintf(symtab, "\n%s %d\n", a, loc);
				loc+=3*atoi(c);}
				
			else if (strcmp(b, "RESB")==0){
				fprintf(inter, "\n%d %s\t%s\t%s\n", loc, a, b, c);
				fprintf(symtab, "\n%s %d\n", a, loc);
				loc+=atoi(c);}
			
			else{
				fprintf(inter, "\n%d %s\t%s\t%s\n", loc, a, b, c);
				fprintf(symtab, "\n%s %d\n", a, loc);
				loc+=strlen(c)-2;}		
		}
		else{
			fprintf(inter, "\n%d %s\t%s\t%s\n", loc, a, b, c);
			loc+=3;}
			
	}
	fprintf(inter, "\nProgram length : %d\n", loc-sa);	

}
