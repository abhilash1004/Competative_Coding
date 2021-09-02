#include<bits/stdc++.h>


#define parent(i) i/2
#define left(i) 2*i
#define right(i) 2*i + 1

using namespace std;

bool _cmp(int a,int b){ return a<b;}

class priorityQueue{
	vector<int> v;
	bool (*compare)(int,int);
public:
	priorityQueue(){
		v.push_back(0);
		compare = _cmp;
	}
	priorityQueue(bool (*fun)(int,int)){
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
		int maxi = v[pos];
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
	void push(int ele){
		v.push_back(ele);
		heapifyUp(v.size()-1);
	}
	int front(){
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

bool cmp(int a,int b){return a>b;}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	priorityQueue pq(cmp);
	pq.push(10);
	//pq.print_queue();
	pq.push(11);
	pq.push(5);
	//pq.print_queue();
	cout<<pq.front()<<endl;
	pq.pop();
	cout<<pq.front()<<endl;
	pq.pop();
	cout<<pq.front()<<endl;
	pq.push(4);
	pq.push(125);
	cout<<pq.front()<<endl;
	pq.pop();
	pq.pop();
	cout<<pq.front()<<endl;
	pq.pop();
	for(int i=0;i<7;i++){
		int temp;
		cin>>temp;
		pq.push(temp);
	}
	while(!pq.empty()){
		cout<<pq.front()<<endl;
		pq.pop();
	}
}