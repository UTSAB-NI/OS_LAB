#include <stdio.h>
typedef struct {
	int sid;
	char name[25];
	int age,dob;
}
STD;
STD s;
void display(FILE *);
int search(FILE *,int);
void main() {
	int i,n,sid_key,opn;
	FILE *fp;
	printf(" How many Records ? ");
scanf("%d",&n);
	fp=fopen("stud.dat","w");
	for (i=0;i<n;i++) {
		printf("Read the Info for Student: %d (sid,name,age,dob) \n",i+1);
		scanf("%d%s%d%d",&s.sid,&s.name,&s.age,&s.dob);
		fwrite(&s,sizeof(s),1,fp);
	}
	fclose(fp);
	fp=fopen("stud.dat","r");
	do {
        printf("\nProgram Menu:\n");
		printf("1- Display\n2- Search\n3- Exit\n");
		scanf("%d",&opn);
		switch(opn) {
			case 1: printf("\nStudent Records in the File \n");
                    printf("SID\tName\tAge\tDob\n");
			display(fp);
			break;
			case 2: printf("Read the sid of the student to be searched?\n");
			scanf("%d",&sid_key);
			if(search(fp,sid_key)) {
				printf("Success ! Record found in the file\n");
				 printf("SID\tName\tAge\tDob\n");
				printf("%d\t%s\t%d\t%d\n",s.sid,s.name,s.age,s.dob);
			} else
			   printf("Failure!! Record with sid %d not found\n",sid_key);
			break;
			case 3:  printf("Exit!! Press a key . . .");
			getch();
			break;
			default:  printf("Invalid Option!!! Try again !!!\n");
			break;
		}
	}
	while(opn != 3);
	fclose(fp);
}
/* End of main() */
void display(FILE *fp) {
	rewind(fp);
	while(fread(&s,sizeof(s),1,fp))
	  printf("%d\t%s\t%d\t%d\n",s.sid,s.name,s.age,s.dob);
}
int search(FILE *fp, int sid_key) {
	rewind(fp);
	while(fread(&s,sizeof(s),1,fp))
	  if( s.sid == sid_key) return 1;
	return 0;
}
