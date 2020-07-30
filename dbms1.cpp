#include<iostream>
#include<conio.h>
using namespace std;
struct student
{
 char name[50];
 int rollno;
 float mark;	
}stud;
void insert()
{
 FILE *fp;
 fp=fopen("record","a");
 cout<<"Enter Name:";
 cin>>stud.name;
 cout<<"Enter Roll number:";
 cin>>stud.rollno;
 cout<<"Enter mark:";
 cin>>stud.mark;
 fwrite(&stud,sizeof(stud),1,fp);
 fclose(fp);	
}
void display()
{
 FILE *fp1;
 fp1=fopen("Record","r");
 cout<<"\nName:"<<stud.name;
 cout<<"\nRoll Number:"<<stud.rollno;
 cout<<"\nMark:"<<stud.mark; 
while(fread(&stud,sizeof(stud),1,fp1))    
 fclose(fp1);
}
void search()
{
 FILE *fp2;
 int r,s,avl;
 cout<<"\nEnter the roll number to search:";
 cin>>r;
 if(!avl)
 cout<<"Roll number"<<r<<"is not available in the file\n";
 else
 {
   fp2=fopen("Record","r");
   while(fread(&stud,sizeof(stud),1,fp2))
   {
   	s=stud.rollno;
   	if(s==r)
   	{
   	  cout<<"\nRoll Number="<<stud.rollno;
	  cout<<"\nName="<<stud.name;
	  cout<<"\nMark="<<stud.mark;	 	
	} 
  }
  fclose(fp2); 	
}
}
void del()
{
 FILE *fpo;
 FILE *fpt;
 int r,s,avlrollno(r),avl;
 avlrollno=avl;
 cout<<"\nEnter the roll number to delete:";
 cin>>r;
 if(!avl)
 {
 cout<<"Roll number"<<r<<" is not available in the file";
 }
 else
 {
   fpo=fopen("Record","r");
   fpt=fopen("TempFile","w");
 while (fread(&stud,sizeof(stud),1,fpo))
 {
 	s=stud.rollno;
   if(s!=avl)
   fwrite(&stud,sizeof(stud),1,fpt);	
 fclose(fpo);
 fclose(fpt);
 fpo=fopen("Record","w");
 fpt=fopen("TempFile","r");
  while(fread(&stud,sizeof(stud),1,fpt))
  fwrite(&stud,sizeof(stud),1,fpo);
   cout<<"\nRecord is deleted";
  fclose(fpo);
  fclose(fpt);	
 }
}
}
int empty()
{
 int c=0;
 FILE *fp;
 fp=fopen("Record","r");
 while(fread(&stud,sizeof(stud),1,fp))	
 c=1;
 fclose(fp);
 return c;
}
int main()
{
 int c,emp;
do
{
 cout<<"\n1.INSERT\n2.DISPLAY\n3.SEARCH\n4.DELETE\n5.EXIT";
 cout<<"\n\n***************\n";
 cout<<"Enter your choice:\t";
 cin>>c;
 cout<<"\n\n";
switch(c)
 {
   case 1:insert();
   break;
   case 2:display();
	break;
   case 3:search();
   break;
   case 4:del();
   break;
   case 5:exit(0);
   break;	 
 } 	
}
while(c!=5);
}







































