#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>


using namespace std;

class Student_Management
{
	private :
		int ID_Student,ID_Teacher,Password,assignment_no,quiz_no,obtained_marks,roll_no;
		char name[50],semester[50],address[50],id_card[50],gmail_address[50];
		char question_1[50],question_2[50],question_3[50],question_4[50],question_5[50];
		char answer_1[50],answer_2[50],answer_3[50],answer_4[50],answer_5[50];
		
		
	public :
	void Main_Menu();
	void Registration();
	void Reg_Student();
	void Reg_Teacher();
	void Login_Student();
	void Check_Assignment();
	void Perform_Quiz();
	void Subjects();
//	void Delete_Account_Student();
//	void Edit_Account_Student();
	void Login_Teacher();
	void Upload_Assignmnt();
	int Check_for_Assignment(int);
	int Check_for_Quiz(int);
	void Mark_Assignment();
	void Upload_Quiz();
	void Mark_Quiz();
//	void Delete_Account_Teacher();
//	void Edit_Account_Teacher();
	
	int Check_Student(int,int);
	int Check_Teacher(int,int);	 
};
void Student_Management::Main_Menu()
{
	int opt;
	do
	{
	system("cls");
		cout<<"\t\t\t MAIN MENU \n\n\n";
		
		cout<<" 1: Register Account \n";
		cout<<" 2: Students Login \n";
		cout<<" 3: Teachers Login \n";
		cout<<"\n\n\n Enter a Choice.......!\n";
		cin>>opt;
		if(opt == 1)
		{
			Registration();
		}
		else if(opt == 2)
		{
			Login_Student();
		}
		else if(opt == 3)
		{
			Login_Teacher();
		}
		else if(opt == 0)
		{
			cout<<"\t\t\t Thanks.....!"<<endl;
			cout<<"\t\t\t Press Any Key......!"<<endl;
			getch();
		}
		else
		{
			cout<<"\t\t\t Wrong Input......!"<<endl;
			cout<<"\t\t\t Press Any Key......!"<<endl;
			getch();
		}
	}
	while(opt !=0);
}
void Student_Management::Registration()
{
	int opt;
	system("cls");
		cout<<"\t\t\t REGISTRATION MENU \n\n\n";
		
		cout<<" 1: Student Account \n";
		cout<<" 2: Teacher Account \n";
		
		cout<<"\n Enter a Choice.......! ";
		cin>>opt;
		if(opt == 1)
		{
		    Reg_Student();	
		}
		else if(opt == 2)
		{
		    Reg_Teacher();
		}
			else
		{
			cout<<"\t\t\t Wrong Input......!"<<endl;
			cout<<"\t\t\t Press Any Key......!"<<endl;
			getch();
		}
}
//Reg_Student
void Student_Management::Reg_Student()
{
	int ID,PSWD,flag;
	system("cls");
		cout<<"\t\t\t REGISTRATION MENU FOR STUDENTS \n\n\n";
		
		ofstream fout("DATA.dat",ios::app);
		
		cout<<" ENTER ID       : ";
		cin>>ID;
		cout<<" ENTER PASSWORD : ";
		cin>>PSWD;
		
		flag = Check_Student(ID,PSWD);
		
		if(flag)
            {
   	            cout<<"\n\n\t\t Student Already Registered"<<endl;
   	            cout<<"\t\t Press Any Key.....! \n";
   	            getch();
            }
        else
            {
   	
            	ID_Student = ID;
            	Password = PSWD;
   	
   	            cin.ignore();
                cout<<" 1- Enter Name                : ";
   	            gets(name);
   	            cout<<" 1- Enter Semester            : ";
   	            gets(semester);
   	            cout<<" 1- Enter ID CARD NO          : ";
   	            gets(id_card);
   	            cout<<" 1- Enter Address             : ";
   	            gets(address);
   	            cout<<" 1- Enter Google Mail Address : ";
   	            gets(gmail_address);
      
                fout.write((char*)this,sizeof(Student_Management));
   
                fout.close();
            }
			
}
//Reg_Teacher
void Student_Management::Reg_Teacher()
{
	int ID,PSWD,flag;
	system("cls");
		cout<<"\t\t\t REGISTRATION MENU FOR TEACHERS \n\n\n";
		
		ofstream fout("DATA.dat",ios::app);
		
		cout<<" ENTER ID \t";
		cin>>ID;
		cout<<" ENTER PASSWORD \t";
		cin>>PSWD;
		
		flag = Check_Teacher(ID,PSWD);
		
		if(flag)
            {
   	            cout<<"\n\n\t\t Teacher Already Registered"<<endl;
   	            cout<<"\t\t Press Any Key.....! \n";
   	            getch();
            }
        else
            {
   	
            	ID_Teacher = ID;
            	Password = PSWD;
   	
   	            cin.ignore();
   	            cout<<" 1- Enter Name                : ";
   	            gets(name);
   	            cout<<" 1- Enter Semester            : ";
   	            gets(semester);
   	            cout<<" 1- Enter ID CARD NO          : ";
   	            gets(id_card);
   	            cout<<" 1- Enter Address             : ";
   	            gets(address);
   	            cout<<" 1- Enter Google Mail Address : ";
   	            gets(gmail_address);
      
                fout.write((char*)this,sizeof(Student_Management));
   
                fout.close();
            }
			
}
//Login Student
void Student_Management::Login_Student()
{
	int ID,PSWD,flag;
	system("cls");
		cout<<"\n\n\n\n\n LOGIN AS STUDENT \t\t\t";
		
		cout<<" ENTER ID \t";
		cin>>ID;
		cout<<" ENTER PASSWORD \t";
		cin>>PSWD;
		
		flag = Check_Student(ID,PSWD);
		
		if(flag==0)
		{
			cout<<"\t\t Record Not Found.....! \n";
			cout<<"\t\t Press Any Key.....! \n";
			getch();
		}
		else
		{
			system("cls");
			int choice;
			do
			{
			  cout<<"\t\t\t STUDENT PORTAL \n\n";
			  
			  cout<<" 1- Check Subjects \n";
			  cout<<" 2- Check Assignments \n";
			  cout<<" 3- Perform Quiz \n";
			  cout<<" 4- Delete Account \n";//
			  cout<<" 5- Edit Account \n";//
			  cout<<"\t\t\t Enter a Choice : ";
			  cin>>choice;
			  
			  if(choice == 1)
			  {
			  	Subjects();
			  }
			  else if(choice == 2)
			  {
			  	Check_Assignment();
			  }
			  else if(choice == 3)
			  {
			  	Perform_Quiz();
			  }
			  else if(choice == 4)
			  {
//			  	Delete_Account_Student();
			  }
			  else if(choice == 5)
			  {
//			  	Edit_Account_Student();
			  }
			  else if(choice == 0)
			  {
			  	cout<<"\t\t EXIT  \n";
			  	cout<<"\t\t Press Any Key.....! \n";
			    getch();
			  }
			  else
			  { 
			   cout<<"\t\t Wrong Choice.....! \n";
			   cout<<"\t\t Press Any Key.....! \n";
			   getch();
			  }
			   	
			}while(choice !=0);
		}
		
		
}
void Student_Management::Subjects()
{
	system("cls");
	cout<<"\t\t\t SUBJECTS \n\n";
	
	cout<<" 1- Object Oriented Programming Theory (OOP) \n";
	cout<<" 2- Object Oriented Programming Lab (OOP) \n";
	cout<<" 3- Digital Logic Design Theory (DLD) \n";
	cout<<" 4- Digital Logic Design Lab (DLD) \n";
	cout<<" 5- Financial Accounting \n";
	cout<<" 6- Probability And Statistics \n";
	cout<<" 7- Communication And Presentation Skills \n";
	
	cout<<"\t\t Press Any Key.....! \n";
	getch();
}

//Function For Performing Assignment

void Student_Management::Check_Assignment()
{
    int choice,flag=0,roll;
    cout<<"\t\t\t ASSIGNMENT \n\n";
    
    cout<<"Enter Assignment No to view : ";
    cin>>choice;
    cout<<"Enter Roll no : ";
    cin>>roll;
    
    ofstream fout("DATA.dat",ios::app);
    ifstream fin("DATA.dat",ios::in);
    
 while(!fin.eof())
 {
    
    
    fin.read((char*)this,sizeof(Student_Management));
    
    if( choice == assignment_no )
    {
        
		   	
    	cout<<"Assignment No : "<<assignment_no<<endl;
    	
    	cout<<"Q-no-1 : "<<question_1<<endl;
       	      	
		cout<<"Q-no-2 : "<<question_2<<endl;
		
		cout<<"Q-no-3 : "<<question_3<<endl;
		
		cout<<"Q-no-4 : "<<question_4<<endl;
		
		cout<<"Q-no-5 : "<<question_5<<endl;
		
				  
        flag = 1;
	    break; 	
     	
    }
 }
    if(flag == 1)
	{
		assignment_no = choice;
        roll_no = roll;
		cout<<"Ans- 1 -  ";
		cin.ignore();
		gets(answer_1);
		cout<<"Ans- 2 -  ";
		gets(answer_2);
		cout<<"Ans- 3 -  ";
		gets(answer_3);
		cout<<"Ans- 4 -  ";
		gets(answer_4);
		cout<<"Ans- 5 -  ";
		gets(answer_5);
		
		fout.write((char*)this,sizeof(Student_Management));
        fout.close();
		  cout<<"\t\t\t Assignment Saved \n";
		
	} 
       if(flag == 0)
       {
       	cout<<"\t\t\tAssignment Not Assigned Yet.....! \n";   	
	   }
	   cout<<"\t\t Press Any Key.....! \n";
			   getch();
			    
		fin.close();	   
}


//void Student_Management::Check_Assignment()
//{
//
// 
//    long flag=0,pos;
//    int choice;
//    cout<<"\t\t\t ASSIGNMENT \n\n";
//    
//    cout<<"Enter Assignment No to view : ";
//    cin>>choice;
//    
//    fstream file("DATA.dat",ios::in|ios::out|ios::binary);
//    
// while(!file.eof())
// {
//    pos=file.tellg();
//    
//    file.read((char*)this,sizeof(Student_Management));
//    
//    if( choice == assignment_no )
//    {
////    	file.read((char*)this,sizeof(Student_Management));
//    	
//    	cout<<"Assignment No : "<<assignment_no<<endl;
//    	
//    	
//       	cout<<"Q-no-1 : "<<question_1<<"\n Ans- ";
//       	cin.ignore();
//       	gets(answer_1);
//		cout<<"Q-no-2 : "<<question_2<<"\n Ans- ";
//		gets(answer_1);
//		cout<<"Q-no-3 : "<<question_3<<"\n Ans- ";
//		gets(answer_1);
//		cout<<"Q-no-4 : "<<question_4<<"\n Ans- ";
//		gets(answer_1);
//		cout<<"Q-no-5 : "<<question_5<<"\n Ans- ";
//		gets(answer_1);
//				 
//		file.seekg(pos);
//        file.write((char*)this,sizeof(Student_Management));	
//        
//		  cout<<"\t\t\t Assignment Saved \n";
//		  
//        flag = 1;
//	    break; 	
//     	
//    }
// }
//       if(flag == 0)
//       {
//       	cout<<"\t\t\tAssignment Not Assigned Yet.....! \n";   	
//	   }
//	   cout<<"\t\t Press Any Key.....! \n";
//			   getch(); 
//		file.close();	   
//}

//Function For Performing Quiz 
void Student_Management::Perform_Quiz()
{

    int choice,flag=0,roll;
    cout<<"\t\t\t ASSIGNMENT \n\n";
    
    cout<<"Enter Assignment No to view : ";
    cin>>choice;
    cout<<"Enter Roll no : ";
    cin>>roll;
    
    ofstream fout("DATA.dat",ios::app);
    ifstream fin("DATA.dat",ios::in);
    
 while(!fin.eof())
 {
    
    
    fin.read((char*)this,sizeof(Student_Management));
    
    if( choice == quiz_no )
    {
        
		   	
    	cout<<"Quiz No : "<<quiz_no<<endl;
    	
    	cout<<"Q-no-1 : "<<question_1<<endl;
       	      	
		cout<<"Q-no-2 : "<<question_2<<endl;
		
		cout<<"Q-no-3 : "<<question_3<<endl;
		
		cout<<"Q-no-4 : "<<question_4<<endl;
		
		cout<<"Q-no-5 : "<<question_5<<endl;
		
				  
        flag = 1;
	    break; 	
     	
    }
 }
    if(flag == 1)
	{
		quiz_no = choice;
        roll_no = roll;
		cout<<"Ans- 1 -  ";
		cin.ignore();
		gets(answer_1);
		cout<<"Ans- 2 -  ";
		gets(answer_2);
		cout<<"Ans- 3 -  ";
		gets(answer_3);
		cout<<"Ans- 4 -  ";
		gets(answer_4);
		cout<<"Ans- 5 -  ";
		gets(answer_5);
		
		fout.write((char*)this,sizeof(Student_Management));
        fout.close();
		  cout<<"\t\t\t Quiz Saved \n";
		
	} 
       if(flag == 0)
       {
       	cout<<"\t\t\t Quiz Not Assigned Yet.....! \n";   	
	   }
	   cout<<"\t\t Press Any Key.....! \n";
			   getch();
			    
		fin.close();	   

}

//Login Teacher 
void Student_Management::Login_Teacher()
{
	int ID,PSWD,flag;
	system("cls");
		cout<<"\n\n\n\n\n LOGIN AS TEACHER \t\t\t\n";
		
		cout<<" ENTER ID \t";
		cin>>ID;
		cout<<" ENTER PASSWORD \t";
		cin>>PSWD;
		
		flag = Check_Teacher(ID,PSWD);
		
		if(flag==0)
		{
			cout<<"\t\t Record Not Found.....! \n";
			cout<<"\t\t Press Any Key.....! \n";
			getch();
		}
		else
		{
			system("cls");
			int choice;
			do
			{
			  cout<<"\t\t\t TEACHER PORTAL \n\n";
			  
			  cout<<" 1- Assign Assignments \n";
			  cout<<" 2- Check Assignments \n";
			  cout<<" 3- Assign Quiz \n";
			  cout<<" 4- Check Quiz \n";
			  
//			  cout<<" 3- Delete Account \n";
//			  cout<<" 4- Edit Account \n";

			  cout<<"\t\t\t Enter a Choice : ";
			  cin>>choice;
			  
			  if(choice == 1)
			  {
			  	Upload_Assignmnt();
			  }
			  else if(choice == 2)
			  {
			  	Mark_Assignment();
			  }
			  else if(choice == 3)
			  {
			  	Upload_Quiz();
			  }
			  else if(choice == 4)
			  {
			  	Mark_Quiz();
			  }
//			  else if(choice == 5)
//			  {
//			  	Edit_Account_Student();
//			  }
			  else if(choice == 0)
			  {
			  	cout<<"\t\t EXIT  \n";
			  	cout<<"\t\t Press Any Key.....! \n";
			    getch();
			  }
			  else
			  { 
			   cout<<"\t\t Wrong Choice.....! \n";
			   cout<<"\t\t Press Any Key.....! \n";
			   getch();
			  }
			   	
			}while(choice !=0);
		}		
}
//Upload Quiz 
void Student_Management::Upload_Assignmnt()
{
	
	system("cls");
	int Assignment_no,flag;
		cout<<"\t\t\t UPLOAD ASSIGNMENT \n\n\n";
		
		ofstream fout("DATA.dat",ios::app);
		
		cout<<" ENTER ASSIGNMENT NO : \t";
		cin>>Assignment_no;
		
		
		flag = Check_for_Assignment(Assignment_no);
		
		if(flag==1)
            {
   	            cout<<"\n\n\t\t ASSIGNMENT Already Registered"<<endl;
   	            cout<<"\t\t Press Any Key.....! \n";
   	            getch();
            }
        else
            {
   	
            	assignment_no = Assignment_no;
            	
            cin.ignore();	
        cout<<"Q-no-1 : ";
    	gets(question_1);
		cout<<"Q-no-2 : ";
		gets(question_2);
		cout<<"Q-no-3 : ";
		gets(question_3);
		cout<<"Q-no-4 : ";
		gets(question_4);
		cout<<"Q-no-5 : ";
		gets(question_5);
		
               fout.write((char*)this,sizeof(Student_Management));
                
            }
            fout.close();
}
void Student_Management::Upload_Quiz()
{
	int Quiz_no,flag;
	system("cls");
		cout<<"\t\t\t UPLOAD ASSIGNMENT \n\n\n";
		
		ofstream fout("DATA.dat",ios::app);
		
		cout<<" ENTER ASSIGNMENT NO : \t";
		cin>>Quiz_no;
		
		
		flag = Check_for_Quiz(Quiz_no);
		
		if(flag==1)
            {
   	            cout<<"\n\n\t\t Teacher Already Registered"<<endl;
   	            cout<<"\t\t Press Any Key.....! \n";
   	            getch();
            }
        else
            {
   	
            	quiz_no = Quiz_no;
            	
            cin.ignore();	
        cout<<"Q-no-1 : ";
    	gets(question_1);
		cout<<"Q-no-2 : ";
		gets(question_2);
		cout<<"Q-no-3 : ";
		gets(question_3);
		cout<<"Q-no-4 : ";
		gets(question_4);
		cout<<"Q-no-5 : ";
		gets(question_5);
                
            fout.write((char*)this,sizeof(Student_Management));
			    
                
            }
            fout.close();
}

//Mark Quiz
void Student_Management::Mark_Assignment()
{
	ofstream fout("DATA.dat",ios::app);
    ifstream fin("DATA.dat",ios::in);
    int choice,flag=0,roll;
    
    cout<<"\t\t\t QUIZ \n\n";
    cout<<"Enter Assignment No to Check : ";
    cin>>choice;
    cout<<"Enter Roll No of Student : ";
    cin>>roll;
    
 while(!fin.eof())
 {
    fin.read((char*)this,sizeof(Student_Management));
    
 	if( assignment_no == choice && roll_no == roll  )
    {
    	cout<<"Assignment No : "<<assignment_no<<endl;
    	
    	cout<<"Q-no-1 : "<<question_1<<"\n Ans- "<<answer_1<<endl;
		cout<<"Q-no-2 : "<<question_2<<"\n Ans- "<<answer_2<<endl;
		cout<<"Q-no-3 : "<<question_3<<"\n Ans- "<<answer_3<<endl;
		cout<<"Q-no-4 : "<<question_4<<"\n Ans- "<<answer_4<<endl;
		cout<<"Q-no-5 : "<<question_5<<"\n Ans- "<<answer_5<<endl;
		
        flag = 1;
	    break; 	
    } 	
 }
       if(flag == 1)
       {
       	quiz_no == choice;
		roll_no == roll;
       	cout<<"Enter Marks Obtained : ";
		cin>>obtained_marks;    
		fout.write((char*)this,sizeof(Student_Management));	
        
		  cout<<"\t\t\t Assignment Marked \n";
	   } 
 
       if(flag == 0)
       {
       	cout<<"\t\t\t Assignment Not Assigned Yet.....! \n";
       	cout<<"\t\t Press Any Key.....! \n";
			   getch();       	
	   }
	
  	
}
void Student_Management::Mark_Quiz()
{
	ofstream fout("DATA.dat",ios::app);
    ifstream fin("DATA.dat",ios::in);
    int choice,flag=0,roll;
    
    cout<<"\t\t\t QUIZ \n\n";
    cout<<"Enter Quiz No to Check : ";
    cin>>choice;
    cout<<"Enter Roll No of Student : ";
    cin>>roll;
    
 while(!fin.eof())
 {
    fin.read((char*)this,sizeof(Student_Management));
    
 	if( quiz_no == choice && roll_no == roll  )
    {
    	cout<<"Quiz No : "<<quiz_no<<endl;
    	
    	cout<<"Q-no-1 : "<<question_1<<"\n Ans- "<<answer_1<<endl;
		cout<<"Q-no-2 : "<<question_2<<"\n Ans- "<<answer_2<<endl;
		cout<<"Q-no-3 : "<<question_3<<"\n Ans- "<<answer_3<<endl;
		cout<<"Q-no-4 : "<<question_4<<"\n Ans- "<<answer_4<<endl;
		cout<<"Q-no-5 : "<<question_5<<"\n Ans- "<<answer_5<<endl;
		
        flag = 1;
	    break; 	
    } 
		
   }   
       if(flag == 1)
       {
       	quiz_no == choice;
		roll_no == roll;
       	cout<<"Enter Marks Obtained : ";
		cin>>obtained_marks;    
		fout.write((char*)this,sizeof(Student_Management));	
        
		  cout<<"\t\t\t Quiz Marked \n";
	   }
       if(flag == 0)
       {
       	cout<<"\t\t\t Quiz Not Assigned Yet.....! \n";
       	cout<<"\t\t Press Any Key.....! \n";
			   getch();       	
	   }
	
  	
}
//ChecK Functions
int Student_Management::Check_for_Assignment(int A)
{
	int flag = 0;
 
 ifstream fin("DATA.dat",ios::in);
 
 while(!fin.eof())
 {
 	fin.read((char*)this,sizeof(Student_Management));
 	if(A == assignment_no )
    {
        flag = 1;
	    break; 	
    }   	
 }
 
    fin.close();
    return flag;
}
int Student_Management::Check_for_Quiz(int A)
{
	int flag = 0;
 
 ifstream fin("DATA.dat",ios::in);
 
 while(!fin.eof())
 {
 	fin.read((char*)this,sizeof(Student_Management));
 	if(A == quiz_no )
    {
        flag = 1;
	    break; 	
    }   	
 }
 
    fin.close();
    return flag;
}
int Student_Management::Check_Student(int ID,int PSWD)
{
 
 int flag = 0;
 
 ifstream fin("DATA.dat",ios::in);
 
 while(!fin.eof())
 {
 	fin.read((char*)this,sizeof(Student_Management));
 	if(ID == ID_Student )
    {
        flag = 1;
	    break; 	
    }   	
 }
 
    fin.close();
    return flag;
}
int Student_Management::Check_Teacher(int ID,int PSWD)
{
 
 int flag = 0;
 
 ifstream fin("DATA.dat",ios::in);
 
 while(!fin.eof())
 {
 	fin.read((char*)this,sizeof(Student_Management));
 	if(ID == ID_Teacher)
    {
        flag = 1;
	    break; 	
    }   	
 }
 
    fin.close();
    return flag;
}
int main()
{
	Student_Management S;
	S.Main_Menu();
}

