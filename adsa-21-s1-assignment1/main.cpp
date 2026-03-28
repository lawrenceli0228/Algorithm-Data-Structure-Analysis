#include <string>
#include <iostream>
#include<cstdlib>     

using namespace std;
string addZero (string l, string r){
	string z = "" ;
	for(int i =0 ; i < abs(static_cast<int>(l.length()-r.length())) ; i++){
         z = z + "0";
	}

	return z;

}

string sub(string cin1, string cin2, int b){
	if(cin1.length() > cin2.length()){
		cin2 = addZero(cin1, cin2) +cin2;
	}else {
		cin1 = addZero(cin1, cin2) +cin1;
	}

	if(cin1 < cin2){
		 
		string subSum = "-" + sub(cin2, cin1,b);

		return subSum;
	}
	else if(cin1 == cin2 ){
		string subSum ="0";
		return	subSum;
	}
	else{
		int c = 0;
		int s;
		string subSum = "";
		int length = cin1.length()-1;
		for(int i =length; i > -1 ; i--){
			int left = cin1[i] - '0';
			int right = cin2[i] - '0';
			if( left >= right + c){
				subSum = char(left - right - c + '0') +subSum;
				c = 0;
			}
			else{
				subSum = char(left + b - right - c + '0') +subSum;
				c = 1;
			}
		}
		int j = 0;
		string newSub = "";
		while(subSum[j] == '0' && j < subSum.length()){
			j++;
		}
		newSub = subSum.substr(j, subSum.length());

		return newSub;	
	}
}

string add(string cin1, string cin2, int b){
	int c = 0;
	int s;

	if(cin2[0] == '-'){
		string newCin2 = cin2.substr(1, cin2.length());

		return sub(cin1, newCin2,b);
	}
	string addSum = "";
	if(cin1.length() > cin2.length()){
		cin2 = addZero(cin1, cin2) +cin2;
	}else {
		cin1 = addZero(cin1, cin2) +cin1;
	}
	int length = cin1.length()-1;
	for(int i =length; i > -1 ; i--){
		s =(cin1[i] - '0') + (cin2[i] - '0') +c;
		c = s/b;
		s = s%b;

		addSum = char(s + '0') + addSum;
	}
	if(c != 0){
		addSum = char(c + '0') +addSum;
	}

	return addSum;


}
string KaratsubaMult(string cin1, string cin2, int b){
	if(cin1.length() > cin2.length()){
		cin2 = addZero(cin1, cin2) +cin2;
	}else {
		cin1 = addZero(cin1, cin2) +cin1;
	}

	if(cin1.length()<=1){
		int left = cin1[0] - '0';
		int right = cin2[0] - '0';

		int decimalR = left*right;

		string MultResult = "";
		while(decimalR >0){
			MultResult = char(decimalR %b + '0') +MultResult;
			decimalR = decimalR / b; 
		}

		return MultResult;
	}

	int k = cin1.length()/2;
	string a1(cin1.begin(), cin1.end()-k);
	string a0(cin1.end()-k, cin1.end());
	string b1(cin2.begin(), cin2.end()-k);
	string b0(cin2.end()-k, cin2.end());


	string p0, p1, p2, a1a0, b1b0;
	p2 = KaratsubaMult(a1,b1,b);
	p0 = KaratsubaMult(a0,b0,b);

	a1a0 = add(a1,a0,b);
	b1b0 = add(b1,b0,b);

	p1 = KaratsubaMult(a1a0, b1b0,b);

	string pp1, mid;
	pp1 = add(p2,p0,b);
	mid = sub(p1,pp1,b);

	string bk = "";
	for(int i = 0; i <k; i++){
		bk = bk +"0";
	}
	string p2bk;
	p2bk = p2 +bk+bk;
	mid += bk;
	string result1 = add(p2bk, mid,b);
	string p  = add(result1 , p0,b);

	int j = 0;
		string newP = "";
		while(p[j] == '0' && j < p.length()){
			j++;
		}
		newP = p.substr(j, p.length());
	return newP;

}




int main(){
	string cin1, cin2;
	int b;

	cin >> cin1;
	cin >> cin2;
	cin >> b;

	string result = "" ;
	string result2 = "";
	result = add(cin1,cin2,b);

	result2 = KaratsubaMult(cin1,cin2,b);
	cout << result<< " "<< result2 << endl;

	return 0;

}
