#include<bits/stdc++.h>
using namespace std;
struct symbol{
	string key;
	int value;
};
struct symboltable{
	symbol *table=new symbol[1000001];
	int cnt;
	symboltable(){
	  cnt =0;
	}
	void insert(const string &Key,int value){
	    for(int i=0;i<cnt;i++){
	    	if(table[i].key==Key){
	    		table[i].value=value;
	    		return;
			}
		}
		table[cnt].key=Key;
		table[cnt++].value=value;
	}
	void Delete(const string &Key){
		for(int i=0;i<cnt;i++){
			if(table[i].key==Key){
				for(int j=i;j<cnt-1;j++){
				  	table[j]=table[j+1];
				}
				cnt--;
				return ;
			}
		}
	}
	int search( const string &Key){
		for(int i=0;i<cnt;i++){
			if(table[i].key==Key){
				return table[i].value;
			}
		}
		return -1;
	}
};
int main(){
	symboltable sb;
	sb.insert("x",1);
	sb.insert("y",2);
	sb.insert("z",3);
	sb.insert("h",4);
	sb.Delete("x");
	string s; cin>>s;
	int sum=sb.search(s);
	if(sum!=-1) cout<<sum;
	else cout<<"khong ton tai";
}