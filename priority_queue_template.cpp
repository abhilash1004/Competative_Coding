#include<bits/stdc++.h>


#define parent(i) i/2
#define left(i) 2*i
#define right(i) 2*i + 1

using namespace std;

template<typename T>
bool _cmp(T a,T b){ return a<b;}


template<typename T>
class priorityQueue{
	vector<T> v;
	bool (*compare)(T,T);
	
public:
	priorityQueue(){
		v.push_back(0);
		compare = _cmp;
	}
	priorityQueue(bool (*fun)(T,T)){
		v.push_back(0);
		compare = fun;
	}
	void heapifyDown(int pos){
		if(pos==0 || v.size()==1){
			return;
		}
		if(pos>=v.size()){
			return;
		}
		int l = left(pos), r = right(pos);
		T maxi = v[pos];
		int largest = pos;
		if(l<v.size()){
			if(/*maxi<v[l]*/compare(maxi,v[l])){
				maxi = v[l];
				largest = l;
			}
		}
		if(r<v.size()){
			if(/*maxi<v[r]*/compare(maxi,v[r])){
				maxi = v[r];
				largest = r;
			}
		}
		if(largest!=pos){
			swap(v[largest],v[pos]);
			heapifyDown(largest);
		}
	}
	void heapifyUp(int pos){
		if(pos==0 || v.size()==1){
			return;
		}
		int p = parent(pos);
		if(p>0){
			if(/*v[p]<v[pos]*/compare(v[p],v[pos])){
				swap(v[p],v[pos]);
				heapifyUp(p);
			}
		}
	}
	int size(){
		return v.size()-1;
	}
	bool empty(){
		return (v.size()==1);
	}
	void push(T ele){
		v.push_back(ele);
		heapifyUp(v.size()-1);
	}
	T front(){
		if(v.size()>1){
			return v[1];
		}
		return -1;
	}
	void pop(){
		swap(v[1],v[v.size()-1]);
		v.pop_back();
		heapifyDown(1);
	}
	private:
	void print_queue(){
		for(int i=1;i<v.size();i++){
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}
};

bool cmp(char a,char b){return a>b;}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	priorityQueue<char> pq(cmp);
	pq.push('a');
	//pq.print_queue();
	pq.push('@');
	pq.push('Z');
	//pq.print_class
	cout<<pq.front()<<endl;
	pq.pop();
	cout<<pq.front()<<endl;
	pq.pop();
	cout<<pq.front()<<endl;
	pq.push('A');
	pq.push('\n');
	cout<<pq.front()<<endl;
	pq.pop();
	pq.pop();
	cout<<pq.front()<<endl;
	pq.pop();
	/*for(int i=0;i<8;i++){
		char temp;
		cin>>temp;
		pq.push(temp);
	}*/
	while(!pq.empty()){
		cout<<pq.front()<<endl;
		pq.pop();
	}
}