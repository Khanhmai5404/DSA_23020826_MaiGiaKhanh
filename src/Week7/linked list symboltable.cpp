#include<bits/stdc++.h>
using namespace std;
struct Node{
	int value;
	string key;
	Node* next;
	Node(const string& k,int x){
		key=k;
		value=x;
		next=nullptr;
	}
};
typedef Node* node;
struct symboltable{
	node head;
	symboltable() : head(nullptr){}
	void insert(const string Key,int Value){
		for(node i=head;i!=nullptr;i=i->next){
			 if(i->key==Key){
			 	i->value=Value;
			 	return;
			 }
		}
		node tmp=new Node(Key,Value);
		if(head==nullptr){
			head=tmp;
			return;
		}
		tmp->next=head;
		head=tmp;
	}
	void Delete(const string &Key){
		node tmp=nullptr;
		 for(node i=head;i!=nullptr;i=i->next){
			 if(i->key==Key){
			 	if(tmp==nullptr){
			 		 delete i;
			 		 head=nullptr;
				 }
			 	else {
			 		tmp->next=i->next;
                    delete i;
				 }
			 }
	        tmp=i;
		}
	}
	int search(const string &Key){
		for(node i=head;i!=nullptr;i=i->next){
			 if(i->key==Key){
			    return i->value;
			 }
		}
		return -1;
	}
	~symboltable() {
        while (head != nullptr) {
            node temp = head;
            head = head->next;
            delete temp;
        }
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