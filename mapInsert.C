#include<iostream>
#include<map>
#include<bits/stdc++.h>
#include<string>

using namespace std;
/*
struct compare
{
  bool operator()  (pair<student,string> l, pair<student,string>r)
{
 return l.second > r.second;
}
};
*/
class student
{
   string name;
   string roll;
  public:
   student(string nm,string ro):name(nm),roll(ro){}

  bool operator < ( const student &obj) const
  {
     return name < obj.name;
  }

  bool operator > ( const student &obj) const
  {
     return name > obj.name;
  }
 friend ostream& operator <<( ostream &out, const student &obj);

};

/*
template<typename T, typename U>
struct compare
{
  //bool operator()  (pair<student,string> l, pair<student,string>r)
  bool operator()  (pair<T,U> l, pair<T,U>r)
{
 return l.second > r.second;
}
};
*/

template<typename T, typename U>
struct compare
{
  //bool operator()  (pair<student,string> l, pair<student,string>r)
  bool operator()  (pair<T,U> l, pair<T,U>r)
{
 return l.second > r.second;
}
};


 ostream& operator <<(  ostream &out, const student &obj)
 {
    out<<obj.name<<"  " <<obj.roll<<endl;
   return out;
 }
int main()
{
   map<int,string> mymap={{11,"AK"},{12,"DK"}};
    student s1("AK","11");
    student s2("SK","13");
    student s3("DK","17");

   map<string,string> mymapp{{"11","AK"},{"12","DK"}};
   //map<string,string,greater<string> > mymappp(mymapp.begin(),mymapp.end());
  // map<student,string > mymappp(mymapp.begin(),mymapp.end());
   map<student,string,greater<student> > mymappp{{s1,"11"},{s2,"23"},{s3,"34"}};
//   mymappp.insert({"13","AK"});
cout<<"priint map"<< mymappp.size()<<endl;

set< pair<student,string>,compare<student,string> > s(mymappp.begin(),mymappp.end());
  for(const auto &it :mymappp)
  {
    cout<<it.first << "   " <<it.second<<endl;
  }
cout<<"from set"<<endl;
  for(const auto &it :s)
  {
    cout<<it.first << "   " <<it.second<<endl;
  }
/*
//METHOD-1
   mymap[1] = "A"; //map insert using = operator
   mymap[3] = "A"; //map insert using = operator
   mymap[2] = "N"; //map insert using = operator

   map<int,string>::iterator it = mymap.begin();
   cout<<"map size is:"<<mymap.size()<<endl;
//METHOD-2
   mymap.insert(std::pair<int,string>(4,"N")); //map insert using pair
   mymap.insert(std::pair<int,string>(5,"D")); //map insert using pair
//METHOD-3

   mymap.insert(map<int,string>::value_type(6," ")); //map insert using value_type
   mymap.insert(map<int,string>::value_type(7,"K")); //map insert using value_type

//METHOD-4
   mymap.insert(std::make_pair<int,string>(8,"U"));  //map insert using make_pair
   mymap.insert(std::make_pair<int,string>(9,"M"));  //map insert using make_pair
   mymap.insert(std::make_pair<int,string>(10,"A")); //map insert using make_pair
   mymap.insert(std::make_pair<int,string>(11,"R")); //map insert using make_pair


   cout<<"map entries are:"<<endl;
   for(;it!=  mymap.end();it++)
   {
     cout<<it->first <<" "<<it->second<<endl;
   }
*/
return 0;
}
