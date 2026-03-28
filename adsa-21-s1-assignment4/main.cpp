#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;




int dp(bool arrived[] , int index, int size, vector<int *> country , vector<int> &connected, vector<int> &unisited, int value, int &value2 )
{
	arrived[index] = true;

	int i = 0;
	while( i < size  ){
		if(country[index][i] != 0 && arrived[i] == false ){
			//cout << "country[ "<<  index << " ] " << " [ " << i << " ] " <<  " arrived[ " << i << "]" << arrived[i] << endl;

			connected.push_back(i);
			arrived[i] = true;
			dp(arrived, i , size , country , connected, unisited, value, value2 );
			value ++;
		}else{
			value2 ++;
		}
		
		i++;
	}
	return value;
}	
int dfsLook(vector<vector<int> > &aConnected, vector<int *> country, int size, bool arrived[], vector<int> unisited)
{
	
	int value = 0;
	int value2 = 0;
	int i = 0;
	while( i < size  ){
		vector<int> temp;
		temp.push_back(i);

		int a  = dp(arrived, i ,size , country , temp, unisited, value, value2);
		if(a == 1 ){
		aConnected.push_back(temp);
		}else if (value2 == size ){
			aConnected.push_back(temp);
		}else if (value2 == size + size ){
			aConnected.push_back(temp);
		}
		else if (value2 == size + size +size ){
			aConnected.push_back(temp);
		}

		
		i++;
	}
	int side = aConnected.size();
	return size;
	
}

string checkSidePoint(vector<int> iSconnected, vector<int *> country ){
	int cSize = iSconnected.size();
	int point = iSconnected.size();
	int side = 0;
	int result = 0;
	
	int i = 0;
	while (i < cSize -1 )
	{	
		int j = i+1;
		while ( j < cSize)
		{
			int row = iSconnected[i];
			int col = iSconnected[j];
			if(country[row][col] == 1 ){
				side +=country[row][col];
			}
		j++;
		}
		i++;
	}
	if(side > point -1){
		return "acycle";
	}
	else if (side < point -1){
		return "connected";
	}
	return "notConnected";

}

bool ifCycelorConnected( vector<int> iSconnected, vector<int *> country){
	
	string a = checkSidePoint(iSconnected,country);



	if(a == "acycle"){
		return true;
	}

	return false;
}


bool ifConnected(vector<int> iSconnected, vector<int *> country ){
	string a = checkSidePoint(iSconnected,country);

	if(a == "connected"){
		return true;
	}

	return false;

}

int goDestroy(vector<vector<int> > aConnected, vector<int *> &aCountry, vector<int *> &aDestroy)
{
	int size = 0 ;
	int min = 53;
	int p[2];

	int i1 = 0;
	while( i1 < aConnected.size() )
	{
		while(ifCycelorConnected(aConnected[i1],aCountry)){
			min = 53;
			int j = 0;
			while ( j < aConnected[i1].size()-1){
				int k = j+1;
				while( k < aConnected[i1].size()){
					int row = aConnected[i1][j];
					int col = aConnected[i1][k];
					if (aDestroy[row][col] < min && aCountry[row][col] != 0){
						min = aDestroy[row][col];
						p[0] = row;
						p[1] = col;
					}
					k++;
				}
			j++;
			}
			int p1 = p[0];
			int p2 = p[1];
			aCountry[p1][p2] = 0;

			if (ifConnected(aConnected[i1],aCountry))
			{
				aCountry[p1][p2] = 1;
			}
			else{
				size += aDestroy[p1][p2];
			}
			aDestroy[p1][p2] = 53;
			
		}
		i1++;
	
	}
	return size;

}

int goBuild(vector<vector<int> > aConnected, vector<int *> &aCountry, vector<int *> &aBuild){
	int size = 0 ;
	int min = 53;
	while(aConnected.size() >1){
		int i = 0;
		while ( i < aConnected.size()-1){
			min = 53;
			int j = 1 ;
			while(j < aConnected.size() ){
				int k = 0 ;
				while( k < aConnected[i].size() ){
					int f = 0 ;
					while( f < aConnected[j].size()){
						int row = aConnected[i][k];
						int col = aConnected[j][f];
						if(aBuild[row][col] < min && row != col ){
							int a = aBuild[row][col];
							min = a;

						
						}
						f++;
					}
					k++;
				}
			j ++;
			}
		 i++; 
		 size += min;
		}
		break;

	}
	return size;
}



int main(){
	string input = "";
	string country ;
	string build ;
	string destroy ;
	int size = 0 ;

	getline(cin,input);
	bool iScountry = true ; 
	bool iSbuild = true ; 
	bool iSdestroy = true ; 
	bool checkSize = true;



	string temp = "" ;

	int lenght = 0;

	int inputSize = input.size();

	if(inputSize <= 5) {
		cout << lenght << endl;
		return 0;
	}


	for (int i = 0 ; i < input.size(); i++){
		if(input[i] ==',' && iScountry && checkSize){
			size = i;
			iSbuild = false;
			iSdestroy = false;
			checkSize = false;
		}
		if(input[i] == ' '){
			i++;
			if(iScountry){
				country = temp;
				iScountry = false;
			}else{
				build = temp;
			}
			temp = "";
		}
		temp = temp + input[i];

//011000,101000,110000,000011,000101,000110 ABDFFF,BACFFF,DCAFFF,FFFABD,FFFBAC,FFFDCA ABDFFF,BACFFF,DCAFFF,FFFABD,FFFBAC,FFFDCA
	}
	destroy = temp;

	int aCountryTotal = 0;

	while (input[aCountryTotal] != ','){

		aCountryTotal++;
	} 

	vector <int*>aCountry;
	vector <int*>aBuild;
	vector <int*>aDestroy;

	int index = 0;
	while(index < size ){
		int *c = new int[size];
		int *b = new int[size];
		int *d = new int[size];
		aCountry.push_back(c);
		aBuild.push_back(b);
		aDestroy.push_back(d);
		index++;
	}

	int a = 0;

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
					if(a < country.size() ){
						if(country[a] == ','){
							a++;
						}
						aCountry[i][j] = country[a] - '0';
						if(build[a] >= 'A' && build [a] <= 'Z'){
							aBuild[i][j] = build[a] - 'A';
						}else if(build[a] >= 'a' && build [a] <= 'z'){
							aBuild[i][j] = build[a] - 'a' + 26;
						}
						if(destroy[a] >= 'A' && destroy[a] <= 'Z'){
							aDestroy[i][j] = destroy[a] - 'A';
						}else if(destroy[a] >= 'a' &&  destroy[a] <= 'z'){
							aDestroy[i][j] = destroy[a] - 'a' + 26;
						}

						a++;

					}
					
				
			}
		}
	
	bool arrived[size];
	vector <int> unisited;
	for (int i = 0; i < size; i++)
	{
		arrived[i] = false;
		unisited.push_back(i);

	}	

	vector<vector<int> > iSconnected;
	int re = dfsLook(iSconnected, aCountry , size, arrived, unisited);

	/*for (int i = 0; i < iSconnected.size(); ++i)
	{
		for (int j = 0; j < iSconnected[i].size(); ++j)
		{
			cout << iSconnected[i][j] << " ";
		}
		cout << endl;
	}*/




	

	lenght +=goDestroy(iSconnected, aCountry, aDestroy);
	lenght += goBuild(iSconnected, aCountry, aBuild);


	cout << lenght << endl;
	

	return 0;

}