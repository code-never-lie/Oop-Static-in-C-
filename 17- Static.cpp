Static
- related to life time
1- Static variables
2- static data members
3- Static methods

Static variables
- life of static variables is equal whole program life time
- created Once in memory 
- allocated when program started(c++ when dec elaborates)
- deallocated when program terminates
.......................................................
void main() {
int i=1;
while (i<=3){
   int j=1;// allocated in memory at each iterative step
   j++;
   cout<<j<<endl
   i++;
}
}
- J alloactes and deallocatd three times
 OUTput 
2
2
2
...................................................
same program with static J
void main() {
int i=1;
while (i<=3){
static int j=1;//allocated once when program loaded 
   j++;
   cout<<j<<endl;
   i++;
}
}
- J alloactes once and terminated when program terminates
 OUTput 
2
3
4
........................................................
class Cup{
public :
 Cup() { cout<<" Cup created \n";}
~Cup() { cout<<" Cup expired \n";}
};
void main() {
cout<<" start of main \n";
int i=1;
while (i<=3){
static Cup c;//allocated once when program loaded 
    i++;
}
cout<<" end of main \n";
}
oUTput
Start of main 
cup created
end of main
cup expired
.........................................................
same program without static
class Cup{
public :
 Cup() { cout<<" Cup created \n";}
~Cup() { cout<<" Cup expired \n";}
};
void main() {
cout<<" start of main \n";
int i=1;
while (i<=3){
  Cup c;//allocated each time in iterative process 
    i++;
}
cout<<" end of main \n";
}
oUTput
Start of main 
cup created
cup expired
cup created
cup expired
cup created
cup expired
end of main
.................................................................
Why Static variables?

Advantages
1- performance (it will save allocation/deallocation time)
2- history sensitive functions
   (save their state after return)
...............................................................
e.g Random() function

int  f() {
static int i=1;// allocated once
i++;
 return i;
}
void main() {
cout<<f()<<endl;
cout<<f()<<endl;
cout<<f()<<endl;
}
OUTput 
2
3
4
.......................................................
Disadvantages

1- It will manopolize memory
2- Don't use until mandatory requirement(history sensitive, performance)
..........................................................     
static data members
- within class static data members
- when data sharing between objects is a requirement
- can't be initialized within class
- can only be initialized outside classs
- can be accessed with class reference

e.g. data sharing between objects
Picnic Fund 
Student wants to contribute in picnic fund. Picnic Fund is a shared fund between students

class Student {
private:
int id;//exclusive
public :
static int pfund;//shared (allocated once)
public :
Student() { }
Student (int id ) {this->id=id;}

};
int Student::pfund=0;
void main () {
cout <<Student::pfund;
Student::pfund=10000;//univesity contributes 10000
Student goher(1),fraz(2),baig(3),ayesha(4);
goher.pfund=goher.pfund+100;
fraz.pfund=fraz.pfund+500;
baig.pfund=baig.pfund+200;
ayesha.pfund=ayesha.pfund+0;

cout<<"Goher wants to check Pfund ="<<goher.pfund<<endl;
cout<<"fraz wants to check Pfund ="<<fraz.pfund<<endl;
baig.pfund=baig.pfund-200;// baig wants to revoke his money
cout<<"ayesha wants to check Pfund ="<<ayesha.pfund<<endl;
cout<<"university wants to check Pfund ="<<Student::pfund<<endl;

}
............................................................
e.g object Counting

How many objects exist at present?

punjab wants to track laptop objects that are distributed to students


class LapTop{
public:
static int count;
LapTop() { count++;}

};
 int LapTop::count=0;
void main () {
cout<<" Total LapTop delivered = "<<LapTop::count<<endl;
LapTop t1;
cout<<" Total LapTop delivered = "<<LapTop::count<<endl;
LapTop t2;
cout<<" Total LapTop delivered = "<<LapTop::count<<endl;
LapTop t3;
cout<<" Total LapTop delivered = "<<LapTop::count<<endl;
LapTop a[47];
cout<<" Total LapTop delivered = "<<LapTop::count<<endl;
}

Output
Total LapTop delivered =0
Total LapTop delivered =1
Total LapTop delivered =2
Total LapTop delivered =3
Total LapTop delivered =50
..............................................................
3- Static methods
- class member function can also be static
- can be called without object instanciation with class reference
    Student::getPFUnd();
- static functions can use only static data members
- 
e.g Pfund again 


class Student {
private:
int id;//exclusive
static int pfund;//shared (allocated once)
public :
Student() { }
Student (int id ) {this->id=id;}
static int getpfund() { return pfund;}
static void  contribute(int amt) { pfund=pfund+amt;}

};
int Student::pfund=0;
void main () {
cout <<Student::getpfund();
Student::contribute(10000);//univesity contributes 10000 
Student goher(1),fraz(2),baig(3),ayesha(4);
goher.contribute(100);
fraz.contribute(100);
baig.contribute(100);
ayesha.contribute(0);
cout<<"Goher wants to check Pfund ="<<goher.getpfund()<<endl;
cout<<"fraz wants to check Pfund ="<<fraz.getpfund()<<endl;
baig.contribute(-200);
cout<<"ayesha wants to check Pfund ="<<ayesha.getpfund()<<endl;
cout<<"university wants to check Pfund ="<<Student::getpfund()<<endl;

}
..............................................................

e.g Meta classes
  - A class witout data members
 Stateless Objects
  - Object without Data

class Math {
public :
int sq (int p ) { return p*p;}
int power (int x , int y){
      if (y==0)
         return 1;
      else
          return x * power(x,y-1);
}

};
void main () {
Math m; //state less object (object without data members)
cout<<m.sq(2)<<endl;
cout<<m.power(2,3)<<endl;

}
..........................................................
Rule of Thumb
- don't create state less objects
Remedy
- use static data members
................................................................
e.g Math Class Again ( Math meta class)

class Math {
public :
static int sq (int p ) { return p*p;}
static int power (int x , int y){
      if (y==0)
         return 1;
      else
          return x * power(x,y-1);
}

};
void main () {

cout<<Math::sq(2)<<endl;
cout<<Math::power(2,3)<<endl;

}
................................................................

