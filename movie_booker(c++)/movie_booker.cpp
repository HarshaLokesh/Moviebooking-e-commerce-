#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<fstream>
#include <windows.h>  
#include<time.h>

COORD coord= {0,0}; // this is global variable
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
using namespace std;
char pwd[20]="srhl";
char inp_pwd[20];
struct date
{ int dd;
  int mm;
  int yy;
};
struct b_details
{ char code[10];
  char c_name[20];
}book;
void inpdt(date d)
{ cout<<"Enter the day: ";cin>>d.dd;
  cout<<"Enter the month: ";cin>>d.mm;
  cout<<"Enter the year: ";cin>>d.yy;
}
void outdt(date d)
{ cout<<d.dd<<"/"<<d.mm<<"/"<<d.yy<<endl;
}
int cu;
fstream f;
int mnum;
class m_det
{ float rat;
  char title[25];
  char desc[100];
  date d1,d2;
  char genre[15];
  char t1_d1[10];
  char t2_d1[10];
  char t3_d1[10];
  char t1_d2[10];
  char t2_d2[10];
  char t3_d2[10];
  char dur[20];
  public:
  char seatd1_s1[10][10];
  char seatd1_s2[10][10];
  char seatd1_s3[10][10];
  char seatd2_s1[10][10];
  char seatd2_s2[10][10];
  char seatd2_s3[10][10];
  int code; //to identify the movie

	void input()
  { cout<<"Input the movie details "<<endl;
	 cout<<"  Enter the movie code: ";cin>>code;
	 cout<<"  Enter the title of the movie: ";gets(title);
	 cout<<"  Enter the description(not more than 100 letters ): ";gets(desc);
	 cout<<"  Enter the current rating(on 10): ";cin>>rat;
	 cout<<"  Enter the genre of the movie: ";gets(genre);
	 cout<<"  Enter the movie duration: ";gets(dur);
	 cout<<"  Input the show details "<<endl;
	 cout<<"  Enter the first date: "<<endl;
	 inpdt(d1);
	 cout<<"  Enter the second date: "<<endl;
	 inpdt(d2);
	 cout<<" Enter timing of the first show on date  1: ";gets(t1_d1);
	 cout<<" Enter timing of the second show on date 1: ";gets(t2_d1);
	 cout<<" Enter timing of the third show on date  1: ";gets(t3_d1);
	 cout<<" Enter timing of the first show on date  2: ";gets(t1_d2);
	 cout<<" Enter timing of the second show on date 2: ";gets(t2_d2);
	 cout<<" Enter timing of the third show on date  2: ";gets(t3_d2);
	 int j;
	 for(int i=0;i<10;i++)
	 {	for(j=0;j<10;j++)
		{  seatd1_s1[i][j]=char(130);
			seatd1_s2[i][j]=char(130);
			seatd1_s3[i][j]=char(130);
			seatd2_s1[i][j]=char(130);
			seatd2_s2[i][j]=char(130);
			seatd2_s3[i][j]=char(130);
		}
	 }
	 cout<<"The movie details have been inserted"<<endl;
  }
  void output()
  { cout<<"Movie code: "<<code<<endl;
	 cout<<title<<endl;
	 cout<<"Description:"<<endl;
	 cout<<desc<<endl;
	 cout<<"Genre: ";cout<<genre<<endl;
	 cout<<"Rating: ";cout<<rat<<"/10"<<endl;
	 cout<<"Movie duration: "<<dur<<endl;
	 cout<<"Date 1: ";outdt(d1);
	 cout<<"       Show 1:"<<t1_d1<<endl;
	 cout<<"       Show 2:"<<t2_d1<<endl;
	 cout<<"       Show 3:"<<t3_d1<<endl;
	 cout<<"Date 2: ";outdt(d2);
	 cout<<"       Show 1:"<<t1_d2<<endl;
	 cout<<"       Show 2:"<<t2_d2<<endl;
	 cout<<"       Show 3:"<<t3_d2<<endl;
  }
  void access(float f)
  { rat=f;
  }
  void access(char des[],int a,int b) //there is b also as there is date and show number for stiming
  { if(a==0 && b==0) //0 is for updation of description
	  strcpy(desc,des);
	 else if(a==1 && b==1)
	  strcpy(t1_d1,des);
	 else if(a==1 && b==2)
	  strcpy(t2_d1,des);
	 else if(a==1 && b==3)
	  strcpy(t3_d1,des);
	 else if(a==2 && b==1)
	  strcpy(t1_d2,des);
	 else if(a==2 && b==2)
	  strcpy(t2_d2,des);
	 else if(a==2 && b==3)
	  strcpy(t3_d2,des);
	 else cout<<"Invalid input"<<endl;
  }
  void access(int dd,int mm,int yy,int a)
  { if(a==1)
	 { d1.dd=dd;d1.mm=mm;d1.yy=yy;}
	 else if(a==2)
	 { d2.dd=dd;d2.mm=mm;d2.yy=yy;}
	 else cout<<"Invalid input"<<endl;
  }

};
m_det movie;
int tries=1;
void addmov() //for inserting a new single movie
{   movie.input();
	 f.open("movie.dat",ios::app|ios::binary);
	 f.write((char*)&movie,sizeof(movie));
	 f.close();
	 cout<<"The movie has been inserted"<<endl;

}
void pwd_chk()
{ int i;
  for(i=0;;i++)
  { inp_pwd[i]=getch();
	 if(inp_pwd[i]!='\r') putch('*');
	 else break;
  }
  inp_pwd[i]=0;
}
void pwdchk()
{ 

system("cls");
  cout<<"Enter the password"<<endl;
  do
  { if(tries>1)
		cout<<"\nincorrect password, re enter the password"<<endl;
	 pwd_chk();
	 if(tries==4 && strcmp(pwd,inp_pwd)!=0)
	 { cout<<"\nNot more that 4 attempts"<<endl;
		break;
	 }
	 tries++;
  }while(strcmp(pwd,inp_pwd)!=0);
  if(strcmp(pwd,inp_pwd)==0)
  { cout<<"\naccess granted";cu=1;}
  else {cu=0;cout<<"\naccess denied";}
  getch();
}
void update() // to change the current data
{
	 int cd,flag=0,ch,nrat,k;
	 int seek= -1*sizeof(movie);
	 char descr[100],ntime[10];
	 int nddd,ndmm,ndyy;
	 cout<<"Enter the code of the movie: ";cin>>cd;
	 f.open("movie.dat",ios::binary|ios::in|ios::out);
	 while(f.read((char*)&movie,sizeof(movie)))
	 { if(movie.code==cd)
		{ flag++;break;}
	 }
	 if(flag==0)
		cout<<"Movie not found "<<endl;
	 else
	 {
		movie.output();
		cout<<"What do you want to update? "<<endl;
		cout<<"1.Movie rating"<<endl;
		cout<<"2.Description"<<endl;
		cout<<"3.Date"<<endl;
		cout<<"4.Show timing"<<endl;
		cout<<"Enter an appropriate choice ";cin>>ch;
		
system("cls");
		switch(ch)
		{ case 1:
					{
					  cout<<"Input the new rating ";cin>>nrat;
					  movie.access(nrat);
					  f.seekp(seek,ios::cur);
					  f.write((char*)&movie,sizeof(movie));
					  cout<<"The rating has been updated"<<endl;
					  break;
					}
		  case 2:
					{
					  cout<<"Enter the new description for the movie(<100 words)"<<endl;
					  gets(descr);
					  movie.access(descr,0,0);//bcos we have the same access for show time and description
					  f.seekp(seek,ios::cur);
					  f.write((char*)&movie,sizeof(movie));
					  cout<<"Updation done"<<endl;
					  break;
					}
		  case 3:
					{ cout<<"Input 1 for change of the first date or 2 for change of second date ";
					  cin>>k;
					  cout<<"Enter the new date"<<endl;
					  cout<<"Enter the day: ";cin>>nddd;
					  cout<<"Enter the month: ";cin>>ndmm;
					  cout<<"Enter the year: ";cin>>ndyy;
					  movie.access(nddd,ndmm,ndyy,k);
					  f.seekp(seek,ios::cur);
					  f.write((char*)&movie,sizeof(movie));
					  cout<<"Updation done"<<endl;
					  break;
					}
		  case 4:
					{ cout<<"Input 1 for change of timings of a movie on the first date and 2 for the second date ";
					  int k1;cin>>k1;
					  cout<<"Enter the show number whose timings must be changed ";
					  int k2;cin>>k2;
					  cout<<"Enter the new show timing"<<endl;gets(ntime);
					  movie.access(ntime,k1,k2);
					  f.seekp(seek,ios::cur);
					  f.write((char*)&movie,sizeof(movie));
					  cout<<"Updation done"<<endl;
					  break;
					}
		  default:{ cout<<"Invalid Input"<<endl;}
		}
	 }
	f.close();

}

void delmov()
{
	 fstream f1;int cd,flag=0;
	 f.open("movie.dat",ios::in|ios::binary);
	 f1.open("temp.dat",ios::out|ios::binary);
	 cout<<"Enter the movie code ";cin>>cd;
	 while(f.read((char*)&movie,sizeof(movie)))
	 {  if(movie.code!=cd)
			f1.write((char*)&movie,sizeof(movie));
		 else
			flag++;
	 }
	 if(flag==0)
		cout<<"The movie was not found"<<endl;
	 else
		cout<<"The movie has been deleted"<<endl;
	 f.close();
	 f1.close();
	 remove("movie.dat");
	 rename("temp.dat","movie.dat");

}
void view_mov()
{ 
system("cls");
  f.open("movie.dat",ios::in|ios::binary);
  while(f.read((char*)&movie,sizeof(movie)))
  { 
system("cls");
	  movie.output();
	  cout<<"*-*-*-*-*\n\n\n"<<endl;
	  cout<<"Press any key to continue"<<endl;getch();
  }
  f.close();
}
void viewgrid(char seat[10][10])
{  
system("cls");
	int x,y,i,j;
	int a=1,b=65;
	gotoxy(1,1);cout<<char(130)<<" : "<<"Available"<<endl;
	gotoxy(1,2);cout<<"* : Booked";
	for(i=0,j=5;i<=9;i++,j+=6,++a)
		{gotoxy(j,4);cout<<a;}
	for(i=0,j=5;i<=9;++i,++j,++b)
	  {	gotoxy(3,j);cout<<char(b);}

	for(i=0,x=5,y=5;i<=9;++i)
	{
		x=5;
		for(j=0;j<=9;++j)
		{
			gotoxy(x,y);cout<<seat[i][j];
			x+=6;
		}
		++y;
	}
	x=5;
	gotoxy(x,y);cout<<"________________________________________________________\n\n"<<endl;
					cout<<"                             SCREEN"<<endl;
}
void r_gen(char b[])
{
	srand(time(0));
	for(int i=0;i<10;i++)
	{  b[i]=char((rand() % 10)+65);
	}
}
int show_ck(int d,int s,int nos)
{  int i,j,k,count=0,flag=0;   //count is for empty seats
	if(d==1)
	{
	  if(s==1)
	  {  for(i=0;i<=9;i++)
			 for(j=0;j<=9;j++)
				 if(movie.seatd1_s1[i][j]==char(130))
				 { count++;
					if(count>nos)
					{ flag++;break;}
				 }
	  }
	  else if(s==2)
	  {  for(i=0;i<=9;i++)
			 for(j=0;j<=9;j++)
				 if(movie.seatd1_s2[i][j]==char(130))
				 { count++;
					if(count>nos)
					{ flag++;break;}
				 }
	  }
	  if(s==3)
	  {  for(i=0;i<=9;i++)
			 for(j=0;j<=9;j++)
				 if(movie.seatd1_s3[i][j]==char(130))
				 { count++;
					if(count>=nos)
					{ flag++;break;}
				 }
	  }
	}
	else if(d==2)
	{  if(s==1)
	  {  for(i=0;i<=9;i++)
			 for(j=0;j<=9;j++)
				 if(movie.seatd2_s1[i][j]==char(130))
				 { count++;
					if(count>nos)
					{ flag++;break;}
				 }
	  }
	  if(s==2)
	  {  for(i=0;i<=9;i++)
			 for(j=0;j<=9;j++)
				 if(movie.seatd2_s2[i][j]==char(130))
				 { count++;
					if(count>nos)
					{ flag++;break;}
				 }
	  }
	  if(s==3)
	  {  for(i=0;i<=9;i++)
			 for(j=0;j<=9;j++)
				 if(movie.seatd2_s3[i][j]==char(130))
				 { count++;
					if(count>nos)
					{ flag++;break;}
				 }
	  }
	}
	return flag;
}
void booking()
{ int cd,flag=0,d,s,nos,col,i,j;int seek=-1*sizeof(movie);
  char row;
  LAB:
  view_mov();
  system("cls");
  cout<<"Enter the appropriate movie code: ";cin>>cd;
  f.open("movie.dat",ios::in|ios::out);
  fstream f2;
  f2.open("booking.dat",ios::in|ios::out);
  while(f.read((char*)&movie,sizeof(movie)))
  { if(movie.code==cd)
	 {  ++flag;
		 break;
	 }
  }
  if(flag==0)
  {  cout<<"Invalid movie code"<<endl;


  }
  else
  {  LABEL:
	  system("cls");
	  movie.output();
	  cout<<" Enter 1 if you want to watch it on day 1\n Enter 2 if you want to watch this movie on day 2 "<<endl;
	  cin>>d;
	  cout<<" Enter the show that you want to watch(1,2,3)"<<endl;
	  cin>>s;
	  cout<<" Enter the number of seats you want to book"<<endl;
	  cin>>nos;
	  if(!show_ck(d,s,nos))
	  {  cout<<" There are not enough seats remaining for this show"<<endl;
		  getch();
		  goto LABEL;
	  }
	  if(d==1)
	  {
		  if(s==1)
		  {

			  for(int i=1;i<=nos;i++)
			  { A:
				 viewgrid(movie.seatd1_s1);
				 cout<<"Enter the row ";cin>>row;
				 cout<<"Enter the column ";cin>>col;
				 row=toupper(row);row-=65;--col;
				 if(movie.seatd1_s1[row][col]=='*')
				 {  cout<<"Seat unavailable"<<endl;
					 getchar();

					 goto A;
				 }
				 else movie.seatd1_s1[row][col]='*';
			  }
			  viewgrid(movie.seatd1_s1);
			  cout<<"\nPress any key to continue"<<endl;getch();
			  f.seekp(seek,ios::cur);
			  f.write((char*)&movie,sizeof(movie));
			  r_gen(book.code);
			  cout<<"\nEnter your name :"<<endl;
			  gets(book.c_name);
			  f2.write((char*)&book,sizeof(book));
			  system("cls");
			  cout<<"Your UID is "<<book.code<<endl;
			  cout<<"Show this code at the cinema  hall to gain entry to the movie(Cash on arrival)"<<endl;
			  cout<<"Press any key to continue"<<endl;

			}
		  if(s==2)
		  {

			  for(int i=1;i<=nos;i++)
			  { B:
				 viewgrid(movie.seatd1_s2);
				 cout<<"Enter the row ";cin>>row;
				 cout<<"Enter the column ";cin>>col;
				 row=toupper(row);row-=65;--col;
				 if(movie.seatd1_s2[row][col]=='*')
				 {  cout<<"Seat unavailable"<<endl;
					 getchar();
					 --i;
					 goto B;
				 }
				 else movie.seatd1_s2[row][col]='*';
			  }
			  viewgrid(movie.seatd1_s2);
			  cout<<"\nPress any key to continue";getch();
			  r_gen(book.code);
			  f.seekp(seek,ios::cur);
			  f.write((char*)&movie,sizeof(movie));
			  cout<<"\nEnter your name ";gets(book.c_name);
			  f2.write((char*)&book,sizeof(book));
			  system("cls");
			  cout<<"Your UID is "<<book.code<<endl;
			  cout<<"Show this code at the cinema  hall to gain entry to the movie(Cash on arrival)"<<endl;
			  cout<<"Press any key to continue"<<endl;
		  }
		  if(s==3)
		  {

			  for(int i=1;i<=nos;i++)
			  { C:
				 viewgrid(movie.seatd1_s3);
				 cout<<"Enter the row ";cin>>row;
				 cout<<"Enter the column ";cin>>col;
				 row=toupper(row);row-=65;--col;
				 if(movie.seatd1_s3[row][col]=='*')
				 {  cout<<"Seat unavailable"<<endl;
					 getchar();

					 --i;
					 goto C;
				 }
				 else movie.seatd1_s3[row][col]='*';
			  }
			  viewgrid(movie.seatd1_s3);
			  cout<<"\nPress any key to continue";getch();
			  r_gen(book.code);
			  f.seekp(seek,ios::cur);
			  f.write((char*)&movie,sizeof(movie));
			  cout<<"\nEnter your name ";gets(book.c_name);
			  f2.write((char*)&book,sizeof(book));
			  system("cls");
			  cout<<"Your UID is "<<book.code<<endl;
			  cout<<"Show this code at the cinema  hall to gain entry to the movie(Cash on arrival)"<<endl;
			  cout<<"Press any key to continue"<<endl;
		  }
		}
		else if(d==2)
		{
		  if(s==1)
		  {

			  for(int i=1;i<=nos;i++)
			  { D:
				 viewgrid(movie.seatd2_s1);
				 cout<<"Enter the row ";cin>>row;
				 cout<<"Enter the column ";cin>>col;
				 row = toupper(row);row-=65;--col;
				 if(movie.seatd2_s1[row][col]=='*')
				 {  cout<<"Seat unavailable"<<endl;
					 getchar();

					 --i;
					 goto D;
				 }
				 else movie.seatd2_s1[row][col]='*';
			  }
			  viewgrid(movie.seatd2_s1);
			  cout<<"\nPress any key to continue";getch();
			  r_gen(book.code);
			  f.seekp(seek,ios::cur);
			  f.write((char*)&movie,sizeof(movie));
			  cout<<"\nEnter your name ";gets(book.c_name);
			  f2.write((char*)&book,sizeof(book));
			  system("cls");
			  cout<<"Your UID is "<<book.code<<endl;
			  cout<<"Show this code at the cinema  hall to gain entry to the movie(Cash on arrival)"<<endl;
			  cout<<"Press any key to continue"<<endl;
			}
		  if(s==2)
		  {

			  for(int i=1;i<=nos;i++)
			  { E:
				 viewgrid(movie.seatd2_s2);
				 cout<<"Enter the row ";cin>>row;
				 cout<<"Enter the column ";cin>>col;
				 row=toupper(row);row-=65;--col;
				 if(movie.seatd2_s2[row][col]=='*')
				 {  cout<<"Seat unavailable"<<endl;
					 getchar();
					 --i;
					 goto E;
				 }
				 else movie.seatd2_s2[row][col]='*';
			  }
			  viewgrid(movie.seatd2_s2);
			  cout<<"\nPress any key to continue";getch();
			  f.seekp(seek,ios::cur);
			  f.write((char*)&movie,sizeof(movie));
			  r_gen(book.code);
			  cout<<"\nEnter your name ";gets(book.c_name);
			  f2.write((char*)&book,sizeof(book));
			  system("cls");
			  cout<<"Your UID is "<<book.code<<endl;
			  cout<<"Show this code at the cinema  hall to gain entry to the movie(Cash on arrival)"<<endl;
			  cout<<"Press any key to continue"<<endl;
		  }
		  if(s==3)
		  {

			  for(int i=1;i<=nos;i++)
			  { F:
				 viewgrid(movie.seatd2_s3);
				 cout<<"Enter the row ";cin>>row;
				 cout<<"Enter the column ";cin>>col;
				 row=toupper(row);row-=65;--col;
				 if(movie.seatd2_s3[row][col]=='*')
				 {  cout<<"Seat unavailable"<<endl;
					 getchar();
					 --i;
					 goto F;
				 }
				 else movie.seatd2_s3[row][col]='*';
			  }
			  viewgrid(movie.seatd2_s3);
			  cout<<"\nPress any key to continue";getch();
			  f.seekp(seek,ios::cur);
			  f.write((char*)&movie,sizeof(movie));
			  r_gen(book.code);
			  cout<<"\nEnter your name ";gets(book.c_name);
			  f2.write((char*)&book,sizeof(book));
			  system("cls");
			  cout<<"Your UID is "<<book.code<<endl;
			  cout<<"Show this code at the cinema  hall to gain entry to the movie(Cash on arrival)"<<endl;
			  cout<<"Press any key to continue"<<endl;

		  }
		}
	}
	getch();
	f2.close();
	f.close();
}
void ex_it()
{ cout<<"Thank you for visiting"<<endl;
  for(unsigned long i=0;i<=99999999;i++);
  for(int i=0;i<=99999999;i++);
  for(int i=0;i<=99999999;i++);
  cout<<"Please visit us again!!"<<endl;
  exit(0);
}

void load()
{system("cls");
char c;
cout<<"                    __            __ \n";
cout<<"              |\\/| |  | \\    / | |   \n";
cout<<"              |  | |  |  \\  /  | |-- \n";
cout<<"              |  | |__|   \\/   | |__ \n";
cout<<"                                             \n";
cout<<"           __   __   __        ___  __            \n";
cout<<"          |  | |  | |  | | /  |    | _|         \n";
cout<<"          |--  |  | |  | |/   |--- | \\             \n";
cout<<"          |__| |__| |__| | \\  |___ |  \\             \n";
cout<<endl;
cout<<endl;
cout<<"                 by-Harsha Lokesh                          \n";
cout<<"\n\n\n\n";
cout<<"   Enter e if you want to exit,\n   press any other key to continue";
c=getch();
cout<<endl;
if(toupper(c)=='E')
 ex_it();
}
int main()
{ int ch;char c;
  LAB:
  cu=0;
  load();
  system("cls");
  cout<<"Enter 1 if you are the administrator and 0 if you are a customer"<<endl;
  cin>>ch;
  if(ch)
  {pwdchk();}
  if(cu==1)
  { do
	 { system("cls");
		cout<<"Menu"<<endl;
		cout<<"1.Add Movie"<<endl;
		cout<<"2.Update details"<<endl;
		cout<<"3.Delete"<<endl;
		cout<<"4.View Movies"<<endl;
		cout<<"5.Exit"<<endl;
		cout<<"Enter an appropriate choice ";cin>>ch;
		switch(ch)
		{ case 1:{addmov();break;}
		  case 2:{update();break;}
		  case 3:{delmov();break;}
		  case 4:{view_mov();break;}
		  case 5: goto LAB;
		  default:cout<<"Invalid choice"<<endl;
		}
		cout<<"Press any key to continue ";getch();
	  }while(1);
	}
	else if(cu==0)
	{ do
	  {system("cls");
		cout<<"MENU:"<<endl;
		cout<<"1.Booking"<<endl;
		cout<<"2.Exit"<<endl;
		cout<<"Enter an appropriate choice"<<endl;
		cin>>ch;
		switch(ch)
		{ case 1:{booking();break;}
		  case 2:goto LAB;
		  default:cout<<"Invalid choice"<<endl;
		}
		cout<<"Press any key to continue"<<endl;
	  }
	while(1);}  }

