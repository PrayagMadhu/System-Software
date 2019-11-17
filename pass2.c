#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int getopaddr(char var[])
{
	char a[8];
	int b;
	FILE *opt=fopen("optab.txt", "r");
	while(!feof(opt))
	{
		fscanf(opt, "%s %d", a, &b);
		if (strcmp(a, var)==0) return b;
	}
	fclose(opt);
}

int getopraddr(char var[])
{
	FILE *sym=fopen("symtab.txt", "r");
	char a[8];
	int b;
	while(!feof(sym))
	{
		fscanf(sym, "%s %d", a, &b);
		if (strcmp(a, var)==0)
			return b;
	}
	fclose(sym);
}

int main()
{
	FILE *intr=fopen("inter.txt", "r");
	FILE *obj_code=fopen("obj.txt", "w");
	int sa, len, null1;
	char opcode[8], oprnd[8], null2[8], buf[10];
	fscanf(intr, "%d", &sa);
	fseek(intr,0,SEEK_END);
	fscanf(intr,"%*s %d",&len);
	fseek(intr,0,SEEK_SET);
	fprintf(obj_code, "\nH^COPY^%d^%d\n", sa, len);
	fprintf(obj_code, "\nT^%d^%d", sa, 0010);
	while(fgets(buf, sizeof(buf), intr)!=NULL)
	{
		fscanf(intr, "%*d %*s %s %s",opcode, oprnd);
		fprintf(obj_code, "^%d%d^", getopaddr(opcode), getopraddr(oprnd));
	}
	fprintf(intr, "\nE^%d\n", sa);
	fclose(intr);
	fclose(obj_code);
}
