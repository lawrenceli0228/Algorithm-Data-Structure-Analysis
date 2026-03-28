#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Node
{
public:
	string status;
    string value;
};

class HashTable
{
public:
	HashTable(Node n[]);
	int search(Node n[],string s);
	void add(Node n[],string s);
	void dele(Node n[],string s);
	void print(Node n[]);
	~HashTable();
	
};

HashTable::HashTable(Node n[]){
	int i=0;
	while(i<26){
		n[i].status = "never used";
		i++;
	}
}


int HashTable::search(Node n[] ,string k){
	int p = int(k[k.length()-1] - 'a');

	int i = p;


	for ( ; i < 26; i++){
		if(n[i].status == "never used"){
			return -1;
		}
		else if(n[i].status == "occupied" && n[i].value == k){
			return i;
		}
	}
	for ( int j = 0; j < 26; j++){
		if(n[j].status == "never used"){
			return -1;
		}
		else if(n[j].status == "occupied" && n[j].value == k){
			return j;
		}
	}
	return 0;
}


void HashTable::add(Node n[],string s){
   int key = s[s.length()-1] - 'a';

   if(n[key].status == "occupied" && n[key].value == s)
   {
       return;
   }
   else if(n[key].status != "occupied")
   {
       n[key].value = s;
       n[key].status = "occupied";
   }
   else
   {
       for(int i=key+1; i<26;i++)
       {
           if(n[i].status != "occupied")
           {
               n[i].value = s;
               n[i].status = "occupied";
               return;
           }
       }
       for(int i=0;i<key;i++)
       {

           if(n[i].status != "occupied")
           {
               n[i].value = s;
               n[i].status = "occupied";
               return;
           }
       }  
   }
}

void HashTable::dele(Node n[],string k){
	int p = search(n,k);

	if(p == -1 ) {
		return;
	}

	n[p].value = "";
	n[p].status = "tombstone";
}
void HashTable::print(Node n[]){
	int i = 0;
	while(i < 26){
		if(n[i].status == "occupied" ){
			cout << n[i].value << " ";
		}
		i++;
	}
	cout << endl;
}
HashTable::~HashTable(){

}



int main(){
   
	string input = "";
	vector<string> keys;
	string intr = "";
	string temp = "";

	getline(cin,input);

	int i = 0;
	while(i < input.size()){
		if(input[i] == 'A' || input[i] == 'D' ){
			intr = intr + input[i];
		}else if(isalpha(input[i])){
			temp = temp + input[i];
		}
		else{
			keys.push_back(temp);
			temp = "";
		}
		i++;
	}

	keys.push_back(temp);

	Node HT[26];
	HashTable *hash = new HashTable(HT);
	for(int i =0 ; i < keys.size() ; i++){
		if(intr[i] == 'A' ){
			hash->add(HT, keys[i]);
		}else if (intr[i] == 'D'){
			hash->dele(HT, keys[i]);
		}
	}
	hash->print(HT);

	return 0;
}