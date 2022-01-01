#include&lt;iostream&gt;
#include&lt;conio.h&gt;
#include&lt;fstream&gt;
#include&lt;stdio.h&gt;
#include&lt;string.h&gt;
using namespace std;
class room //declaration of two classes Room(for room details) and
customerdetails(for customer details )
{
private:
int roomno;
char roomtype;
char roomstatus;
public:
void setrroomno(int r1)
{
roomno=r1;
}
void setrroomstatus(char rs)
{
roomstatus=rs;
}
void setrroomtype(char rt)
{
roomtype=rt;
}
int getrroomno()
{
return roomno;
}
char getrroomstatus()
{
return roomstatus;
}
char getrroomtype()
{
return roomtype;
}
};
class customerdetails
{
private:
int roomno;

char Name[100];
char phoneno[14];
char address[100];
int noofdays;
public:
void setcroomno(int r)
{
roomno=r;
}
int getcroomno()
{
return roomno;
}
char *getcname()
{
return Name;
}
char *getcphoneno()
{
return phoneno;
}
char *getcadd()
{
return address;
}
int getcnoofdays()
{
return noofdays;
}
void acceptcustomerdetails1();
int book();
};
void customerdetails::acceptcustomerdetails1() //definition of fn to accept details
from the user.
{
cout&lt;&lt;&quot;\n Enter Your Name:&quot;;
cin&gt;&gt;Name;
cout&lt;&lt;&quot;\n Enter Your Phone no:&quot;;
cin&gt;&gt;phoneno;
cout&lt;&lt;&quot;\n Enter Your address:&quot;;
cin&gt;&gt;address;
cout&lt;&lt;&quot;\n Enter the no of days for which you want to book the room:&quot;;
cin&gt;&gt;noofdays;
}

int customerdetails::book() //for booking of a particular room
{
int choice;
cout&lt;&lt;&quot;\n Enter the type of room you want to select by entering the number
corresponding to it.The prices per day are given in front of it.&quot;;
cout&lt;&lt;&quot;\n Economy:1 Cost:2000\n Delux:2 Cost:10000\n Luxury:3 Cost:10000\n :&quot;;
cin&gt;&gt;choice;
switch (choice)

{
case 1:cout&lt;&lt;&quot;\n You have selected Economy class Rooms:\n\n&quot;;
cout&lt;&lt;&quot;\n Economy rooms are perfect for guests who want to live comfortably

but for less money&quot;;

cout&lt;&lt;&quot; \n The comfort is the same as the standard rooms but the rooms are a bit

smaller.&quot;;

cout&lt;&lt;&quot;\n These rooms grant access to the gym and hotel wifi \n &quot;;
return 1; //returning a particular value
corresponding to roomtype
break;
case 2:cout&lt;&lt;&quot;\n You have chosen Delux type rooms:\n\n&quot;;
cout&lt;&lt;&quot;\n High ceilings and polished wood finishing define Deluxe Rooms,

which exudes a warm elegance.&quot;;

cout&lt;&lt;&quot;\n Each room is stocked with a plentiful supply of luxurious amenities&quot;;
cout&lt;&lt;&quot;\n These rooms grant access to gym, pool,hotel wifi and lounge \n &quot;;
return 2;
break;
case 3:cout&lt;&lt;&quot;\n You have chosen Luxuxry type rooms:\n\n&quot;;
cout&lt;&lt;&quot;\n THE BEST ROOMS ! \n &quot;;
cout&lt;&lt;&quot;These rooms grant access to everyting in the hotel \n &quot;;
return 3;
break;
default:cout&lt;&lt;&quot;\n INVALID! \n &quot;;
break;
}
}
void main()
{
char contc;
do
{
ifstream finroom,fincustomer,fr;
ofstream foutroom,foutcustomer;
room r[14];
int i,count1=600,count2=700,count3=800;
int e=0;
int eof();
char str[234];

int x;
int check=0;
long pos;
fstream f;
fstream f2;
fstream f1;
const char password=&#39;*&#39;;
char cpass;
int choice;
int filecheck=0;
int cdrc=0;
ofstream of;
cout&lt;&lt;&quot;\n\t\t\t****************************&quot;;
cout&lt;&lt;&quot;\n\t\t\t* SEASONS HOTEL *&quot;;
cout&lt;&lt;&quot;\n\t\t\t****************************&quot;;
cout&lt;&lt;&quot;\n&quot;;
cout&lt;&lt;&quot;\n SEASONS HOTEL are a group of luxury 5 star business hotels across India.&quot;;
cout&lt;&lt;&quot;\n&quot;;
room a;
customerdetails c;
finroom.open(&quot;E:\\ROOM.dat&quot;,ios::in|ios::binary);
for(i=0;i&lt;9;i++)
{
while(finroom.read((char*)&amp;r[i],sizeof(r[i])))
{
filecheck=1;
}
}
finroom.close();
if(filecheck==0)
{
foutroom.open(&quot;E:\\ROOM.dat&quot;,ios::out|ios::binary); //using open() to open a new file if
file doesnt exist and assigning rooms.
for(i=0;i&lt;3;i++)
{
r[i].setrroomno(count1+1);
r[i].setrroomstatus(&#39;V&#39;);
r[i].setrroomtype(&#39;E&#39;);
count1++;
foutroom.write((char*)&amp;r[i],sizeof(r[i]));
}
for(i=0;i&lt;3;i++)
{
r[i].setrroomno(count2+1);
r[i].setrroomstatus(&#39;V&#39;);
r[i].setrroomtype(&#39;D&#39;);

count2++;
foutroom.write((char*)&amp;r[i],sizeof(r[i]));
}
for(i=0;i&lt;3;i++)
{
r[i].setrroomno(count3+1);
r[i].setrroomstatus(&#39;V&#39;);
r[i].setrroomtype(&#39;L&#39;);
count3++;
foutroom.write((char*)&amp;r[i],sizeof(r[i]));

}
foutroom.close(); //delinking file with stream
}
cout &lt;&lt; &quot;\n Please enter your choice: &quot;; // giving choice to the customer
cout &lt;&lt; &quot;\n 1:Book a Room&quot;;
cout &lt;&lt; &quot;\n 2:Display Details&quot;;
cout &lt;&lt; &quot;\n 3:Edit your Details&quot;;
cout &lt;&lt; &quot;\n 4:Cancel your booking&quot;;
cout &lt;&lt; &quot;\n 5:Show rooms(admin only):&quot;;
cin&gt;&gt;choice;
switch(choice)
{
case 1: //book option for booking a room
x=c.book(); // calling fn with return value assigned to roomtype
cout&lt;&lt;&quot;\n Please Enter your details&quot;;
c.acceptcustomerdetails1();
f.open(&quot;E:\\ROOM.dat&quot;,ios::in|ios::out|ios::binary);
if(x==1) //if else loop to check what type of room
{
for(i=0;i&lt;9;i++)
{
pos=f.tellg();
f.read((char*)&amp;r[i],sizeof(r[i]));
if((r[i].getrroomstatus()==&#39;V&#39;)&amp;&amp;(r[i].getrroomtype()==&#39;E&#39;))
{
r[i].setrroomstatus(&#39;F&#39;); //modifying in roomfile Vacant to

full

f.seekg(pos);
f.write((char*)&amp;r[i],sizeof(r[i]));
c.setcroomno(r[i].getrroomno());
e=1;

cout&lt;&lt;&quot;\n Your room no is:&quot;&lt;&lt;c.getcroomno();

break;
}
}

}
else
{
if(x==2)
{
for(i=0;i&lt;9;i++)
{
pos=f.tellg();
f.read((char*)&amp;r[i],sizeof(r[i]));
if((r[i].getrroomstatus()==&#39;V&#39;)&amp;&amp;(r[i].getrroomtype()==&#39;D&#39;))
{
r[i].setrroomstatus(&#39;F&#39;);

f.seekg(pos);
f.write((char*)&amp;r[i],sizeof(r[i]));
c.setcroomno(r[i].getrroomno());
e=1;

cout&lt;&lt;&quot;\n Your room no is:&quot;&lt;&lt;c.getcroomno();

break;
}
}
}
else
{
if(x==3)
{
for(i=0;i&lt;9;i++)
{
pos=f.tellg();
f.read((char*)&amp;r[i],sizeof(r[i]));
if((r[i].getrroomstatus()==&#39;V&#39;)&amp;&amp;(r[i].getrroomtype()==&#39;L&#39;))
{
r[i].setrroomstatus(&#39;F&#39;);
f.seekg(pos);
f.write((char*)&amp;r[i],sizeof(r[i]));
c.setcroomno(r[i].getrroomno());
e=1;

cout&lt;&lt;&quot;\n Your room no is:&quot;&lt;&lt;c.getcroomno();

break;
}
}
}
}
}
f.close();
if(e==0)

{
cout&lt;&lt;&quot;\n No rooms available in your choice!&quot;;
getch();
return;
}
if(e==1)
{ //writing details to customer file
foutcustomer.open(&quot;E:\\CUSTOMER.dat&quot;,ios::app|ios::binary);
foutcustomer.write((char*)&amp;c,sizeof(c));
foutcustomer.close();
}
break;
case 2:

customerdetails c3;
int roomnocd;
int flag;
flag=0;
cout&lt;&lt;&quot;\n Enter Your Room no:\n &quot;;
cin&gt;&gt;roomnocd;
fincustomer.open(&quot;E:\\CUSTOMER.dat&quot;,ios::in|ios::binary);
while(fincustomer.read((char*)&amp;c3,sizeof(c3)))

{
if(c3.getcroomno()==roomnocd) //searching for record in customer file
{
cout&lt;&lt;&quot;\n Name: &quot;&lt;&lt;c3.getcname();
cout&lt;&lt;&quot;\n Phone: &quot;&lt;&lt;c3.getcphoneno();
cout&lt;&lt;&quot;\n Address: &quot;&lt;&lt;c3.getcadd();
cout&lt;&lt;&quot;\n No of days booked: &quot;&lt;&lt;c3.getcnoofdays();
cout&lt;&lt;&quot;\n Room no: &quot;&lt;&lt;c3.getcroomno();
if(roomnocd&gt;1000&amp;&amp;roomnocd&lt;1000)
{
cout&lt;&lt;&quot;\n Room type is Economy&quot;;
cout&lt;&lt;&quot;\n Cash to be paid: 2000&quot;;
}
if(roomnocd&gt;1000&amp;&amp;roomnocd&lt;1000)
{
cout&lt;&lt;&quot;\n Room type is Delux&quot;;
cout&lt;&lt;&quot;\n Cash to be paid: 10000&quot;;
}
if(roomnocd&gt;1000&amp;&amp;roomnocd&lt;1000)
{
cout&lt;&lt;&quot;\n Room type is Luxury:&quot;;
cout&lt;&lt;&quot;\n Cash to be paid: 10000&quot;;
}
flag=1;
break;

}
}

fincustomer.close();
finroom.close();
if(flag==0)
{
cout&lt;&lt;&quot;\n room number invalid or vacant!&quot;;
}
break;
case 3: //edit details option customer has the option to edit any one of the 3
details at one time

customerdetails c2;
int cc;
long pos;
char nname[100],nadd[100],nphno[14];
char phno[14];
int rno3;
int flag4;
cout&lt;&lt;&quot;\n Enter Your Room no:&quot;;
cin&gt;&gt;rno3;
room r1;
flag4=0;
f2.open(&quot;E:\\CUSTOMER.dat&quot;,ios::in|ios::out|ios::binary);

while(f2.read((char*)&amp;c2,sizeof(c2)))
{
pos=sizeof(c2)*-1;
if(c2.getcroomno()==rno3) //searching for customer
{
flag4=1;
cout&lt;&lt;&quot;\n Name is: &quot;&lt;&lt;c2.getcname();
cout&lt;&lt;&quot;\n Phone no is:&quot;&lt;&lt;c2.getcphoneno();
cout&lt;&lt;&quot;\n Address is:&quot;&lt;&lt;c2.getcadd();
cout&lt;&lt;&quot;\n No of days booked:&quot;&lt;&lt;c2.getcnoofdays();
cout&lt;&lt;&quot;\n The room no is:&quot;&lt;&lt;c2.getcroomno();
cout&lt;&lt;&quot;\n Select which detail you want to change \n Name::1\n Phone no::2\n

Address::3&quot;;

cin&gt;&gt;cc;
switch(cc)
{
case 1:
cout&lt;&lt;&quot;\n Enter new name:&quot;;
cin&gt;&gt;nname;
strcpy(c2.getcname(),nname);// modifying particular record
cout&lt;&lt;&quot;\n Name changed sucessfully&quot;;
break;

case 2:cout&lt;&lt;&quot;\n Enter new phno:&quot;;
cin&gt;&gt;phno;
strcpy(c2.getcphoneno(),phno);
cout&lt;&lt;&quot;\n Phone no changed sucessfully&quot;;
break;
case 3:cout&lt;&lt;&quot;\n Enter new address:&quot;;
cin&gt;&gt;nadd;
strcpy(c2.getcadd(),nadd);
cout&lt;&lt;&quot;\n Address changed sucessfully&quot;;
break;
default:cout&lt;&lt;&quot;\n INVALID&quot;;
break;

}
f2.seekp(pos,ios::cur);
f2.write((char*)&amp;c2,sizeof(c2));
break;
}
}
f2.close();
if(flag4==0)
{
cout&lt;&lt;&quot;\n Customer not found error!&quot;;
}
break;
case 4: //cancel booking option

int roomnoc,flag2;
customerdetails c1;
flag2=0;
cout&lt;&lt;&quot;\n Please Enter Your Room No:&quot;;
cin&gt;&gt;roomnoc;
f1.open(&quot;E:\\ROOM.dat&quot;,ios::in|ios::out|ios::binary);
fincustomer.open(&quot;E:\\CUSTOMER.dat&quot;,ios::in|ios::binary);
of.open(&quot;E:\\temporary.dat&quot;,ios::out|ios::binary);
for(i=0;i&lt;9;i++)
{

pos=f1.tellg();
f1.read((char*)&amp;r[i],sizeof(r[i]));

if((roomnoc==r[i].getrroomno())&amp;&amp;(r[i].getrroomstatus()==&#39;F&#39;))
{

r[i].setrroomstatus(&#39;V&#39;); //changing details in room file if record found
f1.seekg(pos);
f1.write((char*)&amp;r[i],sizeof(r[i]));
while(fincustomer.read((char*)&amp;c1,sizeof(c1)))

{

if(c1.getcroomno()==roomnoc)

{
flag2=1;
}
else
{
of.write((char*)&amp;c1,sizeof(c1));
}
}
break;
}
}
f1.close();
of.close();
fincustomer.close(); //deletion in customer file
remove(&quot;E:\\CUSTOMER.dat&quot;);
rename(&quot;E:\\temporary.dat&quot;,&quot;E:\\CUSTOMER.dat&quot;);
if(flag2==1)
{
cout&lt;&lt;&quot;\n Booking canceled successfully&quot;;
}
if(flag2==0)
{
cout&lt;&lt;&quot;\nError in canceling&quot;;
}
break;
case 5:cout&lt;&lt;&quot;\n Enter password:&quot;; //show rooms option if rooms are full or vacant
cin&gt;&gt;cpass;
fr.open(&quot;E:\\ROOM.dat&quot;,ios::in|ios::binary);
if(cpass==password)// checking for password
{
for(i=0;i&lt;9;i++)
{
fr.read((char*)&amp;r[i],sizeof(r[i]));
cout&lt;&lt;&quot; \n Room no:&quot;&lt;&lt;r[i].getrroomno();
cout&lt;&lt;&quot; \n Room status:&quot;&lt;&lt;r[i].getrroomstatus();
cout&lt;&lt;&quot; \n Room type:&quot;&lt;&lt;r[i].getrroomtype();
}
}
else
{
cout&lt;&lt;&quot;\n Wrong password!&quot;;
}
fr.close();
break;
default:cout&lt;&lt;&quot;\n INVALID!!&quot;;
}

cout&lt;&lt;&quot;\n Do you want to continue?(Y/N):&quot;;
cin&gt;&gt;contc;
}while(contc==&#39;Y&#39;||contc==&#39;y&#39;);
if(contc==&#39;N&#39;||contc==&#39;n&#39;)
{
return;
}
getch();
return;
}