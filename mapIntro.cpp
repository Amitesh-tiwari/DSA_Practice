#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){

    unordered_map<string,int> m;

    //insertion k tarike

    //1st
    pair<string,int> p = make_pair("Golu",1);
    m.insert(p);

    //2nd
    m["tiwari"] = 2;

    //3rd
    pair<string,int> p1("hero",3);
    m.insert(p1);

    //Searching in the map
    //1st
    cout<<m["tiwari"]<<endl;

    //2nd
    cout<<m.at("hero")<<endl;
    
    //Accessing an unknown key
    //cout<< m.at("unknown") <<endl;//it gives an error because it 
    //searches for the entry in the map it is not present gives out if range error.

    //Accessing unknown key using another method
    //cout<<m["unknown"]<<endl;//it gives 0 because it creates the entry for the 
    //key which is not present in the map

    cout<<m["unknown"]<<endl;
    cout<< m.at("unknown") <<endl;
    //for both the statements it will return 0 0 because firstly the 
    //key is created and the at method found that the key is 0 so it returned 0.

    //to check presence
    cout<< m.count("bro")<<endl;//it is not present so it will return 0 
    //if present returns 1

    //to erase
    cout<<m.erase("hero")<<endl;
    cout<<m.size()<<endl;

    //for accessing all the elements in the map
    //for(auto i:m){
        //cout<<i.first<<" "<<i.second()<<endl;
   // }

    //using iterator for accessing elements one by one

    unordered_map<string,int> :: iterator it = m.begin();
    while(it != m.end()){
        cout<< it->first <<" " <<it->second<<endl;
        it++;
    }









    return 0;
}
