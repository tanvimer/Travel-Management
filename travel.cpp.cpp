#include <bits/stdc++.h> 
#include <cstring>
#include <iostream>
using namespace std;
class travelDetails;
class personalDetails;
void checkYourDetails(travelDetails,personalDetails);
int code;
class travelDetails{
	int No_passengers;
	int day,month,year;
	int bd_pt;
	int dest_pt;
	int tcode;
	public:
	int dck;
	friend void checkYourDetails(travelDetails,personalDetails);
	void input_travel(int);
	void compute();
	int get_code();
	
}tobj;
class personalDetails{
	
	int age;
	char sex;
	//String pass_no;
	string phn_no;
	
	public:
    int pcode;
    int givecode();
	string name;
	friend void checkYourDetails(travelDetails,personalDetails);
	void input_personal(int);
}pobj;
int personalDetails::givecode()
{
  return pcode;
}
void personalDetails :: input_personal(int set_code){
	pcode = set_code;
	cout<<"Enter Name "<<endl;
	cin>>name;
	cout<<"Enter age "<<endl;
	cin>>age;
	cout<<"Enter sex : "<<" M for male  ....  F for female .... O for others"<<endl;
	cin>>sex;
	cout<<"Enter phn_no : "<<endl;
	cin>>phn_no;
	
}
int travelDetails::get_code()
{
  return tcode;
}
void travelDetails :: input_travel(int set_code){
	tcode = set_code;
	cout<<"Enter No. of passengers "<<endl;
	cin>>No_passengers;
    cout<<"Select Boarding point :"<<endl<<" 1.Mumbai	2.Delhi		3.Chandigarh"<<endl;
	cin>>bd_pt;
	cout<<"Select Destination :"<<endl;
	cout<<"1. New York"<<endl;
    cout<<"2. Canada"<<endl;
    cout<<"3. South America"<<endl;
    cout<<"4. Australia"<<endl;
    cout<<"5. Hong Kong"<<endl;
    cout<<"6. Dubai"<<endl;
    cout<<"7. Egypt"<<endl;
    cout<<"8. London"<<endl;
    cout<<"9. Indonesia"<<endl;
    cout<<"10. Singapore"<<endl;
	cin>>dest_pt;
	cout<<"Enter day"<<endl;
	cin>>day;
	while(day>31 || day<1){
	cout<<"Try entering date between 1 and 31"<<endl;
	cin>>day;
    }
	cout<<"Enter month"<<endl;
	cin>>month;
	while(month>12 || month<1)
	{
		cout<<"Try entering month between 1 and 12"<<endl;
		cin>>month;
	}
	cout<<"Enter year"<<endl;
	cin>>year;
	
	cout<<"Enter Deck 1 or 2 or 3"<<endl;
	cin>>dck;
	
}
void boardpt(int c)  //for easy o/p
{
  if(c==1)
  cout<<"Mumbai\t";
  if(c==2)
  cout<<"Delhi\t";
  if(c==3)
  cout<<"Chandigarh\t";
}
void dest(int d) 
{
  switch(d)
  {
    case 1:cout<<"New York";
       break;
    case 2:cout<<"Canada";
       break;
    case 3:cout<<"South America";
       break;
    case 4:cout<<"Australia";
       break;
    case 5:cout<<"Hong Kong";
       break;
    case 6:cout<<"Dubai";
       break;
    case 7:cout<<"Egypt";
       break;
    case 8:cout<<"London";
       break;
    case 9:cout<<"Indonesia";
       break;
   case 10:cout<<"Singapore";
       break;
  }
}
void travelDetails::compute()   //compution+bill generation
{
  long int gttl=0,hr,dcst,dck,spfts=7500,ttr=500;
  switch(dest_pt)
  {
    case 1:;
    case 2:;
    case 3:hr=30*24;
       dcst=250000;
       break;
    case 4:;
    case 5:;
    case 6:hr=7*24;
       dcst=75000;
       break;
    case 7:;
    case 8:;
    case 9:hr=24*24;
       dcst=130000;
       break;
   case 10:;
   case 11:;
   case 12:hr=15*24;
       dcst=100000;
       break;
   case 13:;
   case 14:;
   case 15:hr=12*24;
       dcst=120000;
       break;
  }
  switch(dck)
  {
    case 1:dck=7500;
       break;
    case 2:dck=5000;
       break;
    case 3:dck=1000;
  }
  system("cls");
  cout<<"BILL";
  cout<<"Boarding point: ";
  boardpt(bd_pt);
  cout<<"Destination: ";
  dest(dest_pt);
  cout<<"Date of Departure: ";
  cout<<day<<"/"<<month<<"/"<<year;
   hr=hr/24;         //to calculate date of arrival
  day=day+hr;
  if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
  {
    if(day>31)
    {
      month=month+1;
      day=day%31;
    }
  }
  if(month==4||month==6||month==9||month==11)
  {
    if(day>30)
    {
      month=month+1;
      day=day%30;
    }
  }
  if(month==2)
  {
    if(day>28)
    {
      month=month+1;
      day=day%28;
    }
  }
  if(month==13)
  {
    month=1;
    year++;
  }
  cout<<"\n\n\t\tDate of Arrival: ";
  cout<<day<<"/"<<month<<"/"<<year;
  cout<<"\n\n\t\tSubject\t\tCost(for 1)\tNo of ppl\tTotal";
  cout<<"\n\n\t\tTravel\t\t"<<dcst<<"\t\t   "<<No_passengers<<"\t\t"<<No_passengers*dcst;
  gttl+=No_passengers*dcst;
  cout<<"\n\t\tDeck\t\t"<<dck<<"\t\t   "<<No_passengers<<"\t\t"<<dck*No_passengers;
  gttl+=dck*No_passengers;
  cout<<"\n\n\n\t\t\t Grand Total:Rs ";
  if(gttl>100000)     //to provide comma's for grandtotal
  {
    cout<<gttl/100000<<",";
    gttl=gttl%100000;
  }
  if(gttl>1000)
  {
    cout<<gttl/1000<<",";
    gttl=gttl%1000;
  }
  cout<<gttl;
  if(gttl<10)
  cout<<"00";
  cout<<" ";
  cout<<"\n\n\t ! All Travellers below the age of 5 have not been charged ! ";
 // getch();
}
void checkYourDetails(travelDetails t, personalDetails p){
     	char cp,ct;
		cout<<"This is the personal information you entered"<<endl;
     	cout<<"Name : "<<p.name<<endl;
     	cout<<"Age : "<<p.age<<endl;
     	cout<<"Sex : "<<p.sex<<endl;
        cout<<"Contact : "<<p.phn_no<<endl;
        cout<<"Enter Y if information is correct and N if you want to edit ..... You will be redirected to input screen"<<endl;
        cin>>cp;
        if(cp=='N')
        p.input_personal(p.pcode);
        else if(cp == 'Y') {
        	cout<<"This is the travel information you entered : "<<endl;
        	cout<<"No. of passengers : "<<t.No_passengers<<endl;
        	cout<<"Boarding point : "<<t.bd_pt<<endl;
        	cout<<"Destination : "<<t.dest_pt<<endl;
        	cout<<"Date : "<<t.day<< "/" <<t.month <<"/"<<t.year<<endl;
        	cout<<"Enter Y if information is correct and N if you want to edit ..... You will be redirected to input screen"<<endl;
        	cin>>ct;
        	if(ct == 'N')
        	t.input_travel(t.tcode);
		}
}
void check(int c,int&flag)
{
  flag=0;
  ifstream ifl("PersonalDetails.txt",ios::binary);
  if(!ifl)
  cout<<"\nError";
  ifl.read((char*)&pobj,sizeof(pobj));
  while(!ifl.eof())
  {
    if(pobj.givecode()==c)
    {
      flag=1;
      break;
    }
    ifl.read((char*)&pobj,sizeof(pobj));
  }
  if(flag==1)
  {
   checkYourDetails(tobj,pobj);
  }
  else
  {
    cout<<"\nError in locating record!!";
  }
  ifl.close();
}

void p_modify(int c)  //to edit persdetails
{
  ofstream ofl2("temp1.txt",ios::binary);
  if(!ofl2)
  cout<<"Error While Opening File";
  ifstream ifl4("PersonalDetails.txt",ios::binary);
  if(!ifl4)
  cout<<"Error While Opening File";
  ifl4.read((char*)&pobj,sizeof(pobj));
  while(!ifl4.eof())
  {
    if(pobj.givecode()==c)
    {
      system("cls");
      cout<<"Please Enter the New details of the record"<<endl;
      pobj.input_personal(c);
      ofl2.write((char*)&pobj,sizeof(pobj));
      cout<<"\n\t\t\tModification Succesful!!!";
      ifl4.read((char*)&pobj,sizeof(pobj));
    }
    else
    {
      ofl2.write((char*)&pobj,sizeof(pobj));
      ifl4.read((char*)&pobj,sizeof(pobj));
    }
  }
  remove("PersonalDetails.txt");
  rename("temp1.txt","PersonalDetails.txt");
  ifl4.close();
  ofl2.close();
 // getch();
}
void t_modify(int c)  //to edit travdetails
{
  ofstream ofl2("temp1.txt",ios::binary);
  if(!ofl2)
  cout<<"Error While Opening File";
  ifstream ifl4("TravelDetails.txt",ios::binary);
  if(!ifl4)
  cout<<"Error While Opening File";
  ifl4.read((char*)&tobj,sizeof(tobj));
  while(!ifl4.eof())
  {
    if(tobj.get_code()==c)
    {
      system("cls");
      cout<<"Please Enter the New details of the record"<<endl;
      tobj.input_travel(c);
      ofl2.write((char*)&tobj,sizeof(tobj));
      cout<<"\n\t\t\tModification Succesful!!!";
      ifl4.read((char*)&tobj,sizeof(tobj));
    }
    else
    {
      ofl2.write((char*)&tobj,sizeof(tobj));
      ifl4.read((char*)&tobj,sizeof(tobj));
    }
  }
  remove("TravelDetails.txt");
  rename("temp1.txt","TravelDetails.txt");
  ifl4.close();
  ofl2.close();
  //getch();
}
int main(){
		int check_t,ch,flag;
	cout<<" WELCOME TO OUR TRAVEL MANAGEMENT";
	 fstream fl("INITIAL.txt",ios::binary); 
     if(!fl)
       cout<<"\nError opening file "<<endl;
     fl.read((char*)&code,sizeof(code));
     fl.close();
     do{
     	cout<<"Select the kind of user you are : "<<endl;
   		cout<<"1 for NEW USER"<<endl;
		cout<<"2 for REGISTERED USER"<<endl;
		int ch;
		cin>>ch;
		while(ch!=1 && ch!=2){
		cout<<"WRONG CHOICE ENTERED ... TRY BETWEEN 1 OR 2"<<endl;
		cin>>ch;
		}
		system("cls");
		switch(ch){
			case 1:
				{
				code++;
				cout<<"HELLO NEW USER..."<<endl<<"ENTER YOUR PERSONAL AND TRAVEL DETAILS TO PROCEED"<<endl;
				pobj.input_personal(code);
				ofstream ofl("PersonalDetails.txt",ios::binary|ios::app);
            	if(!ofl)
            	cout<<"\n\n\t\tSorry.The File Cannot Be Opened For Writing"<<endl;
            	ofl.write((char*)&pobj,sizeof(pobj));
            	ofl.close();
				system("cls");
				tobj.input_travel(code);
            	ofstream ofl1("TravelDetails.txt",ios::binary|ios::app);
                if(!ofl1)
                cout<<"\n\n\t\tSorry.The File Cannot Be Opened For Writing"<<endl;
                ofl1.write((char*)&tobj,sizeof(tobj));
                ofl1.close();
				system("cls");
				checkYourDetails(tobj,pobj);
				system("cls");
				cout<<"Dear "<<pobj.name<<" you have been registered as a user .. Please remember the travel code that is "<<pobj.pcode<<endl;
			
				break;
				exit(0);
			}
			case 2:
				{
				cout<<"Enter Your Travel Code"<<endl;
				cin>>check_t;
				cout<<"Choose what you will like to do : "<<endl;
				cout<<"1. View Details"<<endl;
				cout<<"2. Compute Bill"<<endl;
				cout<<"3. Modify Details"<<endl;
				cout<<"4. Back"<<endl;
				cin>>ch;
				switch(ch){
					case 1:{
						
						check(check_t,flag);
						break;
					}
					case 2:{
						tobj.compute();
						break;
					}
					case 3:{
						int select;
						cout<<"Enter what to edit : 1. personal details 2. travel details"<<endl;
						cin>>select;
						if(select == 1)
						p_modify(check_t);
						else if (select == 2)
						t_modify(check_t);
						break;
					}
					case 4:{
						break;
					}
				}
				break;
			}
		}     	
	} while(1);
	 cout<<" THANKYOU FOR USING OUR TRAVEL MANAGEMENT SYSTEM ........ HAVE  A HAPPY AND SAFE JOURNEY !!!!!!!!!!!"<<endl;
}
