#include <iostream>
#include <cstdio>
#include <ctime>
#include <stdlib.h>   
using namespace std;
#define INFINITY 9999999999



class Edge{
	int* distance;
	int* travelfrom;
	int Vertex;
	int source;
	struct E_node{
		int from;
		int to;
		int cost;
		E_node *link;
	}*first;
	public:
		Edge(int v){
			
			Vertex=v;
			
			cout<<"source:"<<endl;
			cin>>source;
		
			first=NULL;
			distance=new int[Vertex];
			travelfrom=new int[Vertex];
			distance[source]=0;
			travelfrom[source]=-1; //null
	       for(int i=0;i<Vertex;i++){
	       	if(i!=source)
		    distance[i]=INFINITY;
		    
			}
		}
	void Addedge(int f,int t,int c)	{
		E_node *nE=new E_node;
		nE->from=f;
		nE->to=t;
		nE->cost=c;
		nE->link=NULL;
		if(first==NULL){
			first=nE;
		}else{
			E_node  *p=first;
			E_node *pp=NULL;
			while(p){
				pp=p;
				p=p->link;
			}
			pp->link=nE;
		}
	}
	void bellmenford(){
		relax();
		checkNegativeLoop();
		
	}
	
	void relax(){
		for(int i=0;i<Vertex-1;i++){ //  |V|-1 times
		
		E_node *p=first;
		while(p){
			if(distance[p->to]>distance[p->from]+p->cost)
			{
			distance[p->to]=distance[p->from]+p->cost;	
			travelfrom[p->to]=p->from;
			}
			p=p->link;
		}
	}
    }
	void checkNegativeLoop(){
		bool neg_loop=false;
		E_node *p=first;
		while(p){
			if(distance[p->to]>distance[p->from]+p->cost)
			{neg_loop=true;
			p=NULL;	
			}
			else{	p=p->link;
			}
		
		}
		if(neg_loop==true){
			cout<<"negative loop found"<<endl;
		}
		else{
			cout<<"Result is :\n Travel to vertex <--- from vertex (...)  : cost from source"<<endl;
			for(int i=0;i<Vertex;i++)
			{if(i!=source)
			cout<<i<<" <---- "  <<travelfrom[i]<< "   :"<<distance[i]<<endl;
			else
			cout<<i<<" <---- NIL :"<<distance[i]<<endl;
			}
		}
	}
		
	
};

int main(){
	int E,V,check;
	cout<<"Enter \n1. Check time graph sparse graph where |E|=|V|\n2.Check time graph dense graph where |E|=|V|*|V|\n3. for well known graph"<<endl;
	cin>>check;
	
	/* To make executiontime graph
	where |E|=|V|
	graph is like
	0-->1-->2-->3....-->(V-1)-->0
	*/
	if (check==1){
		cout<<"Enter  number of vertex |V| only as |E|=|V|"<<endl;
	    cin>>V;
	    E=V;
	
	Edge *Elist=new Edge(V);
	
	for(int i=0;i<V;i++){
		//select a random cost b/w 1-10
		int c=rand() % 10 + 1;
	    if(i!=V-1)
	    Elist->Addedge(i,i+1,c);
	    else
	    Elist->Addedge(i,0,c);
	}
	//add timer here to calculate execution time
	clock_t start;
	double duration;
	start = clock();
	Elist->bellmenford();
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	cout<<"for |V|="<<V<<"  |E|="<<E<<" Time:"<<duration <<" seconds"<<endl;
	}
	/* To make executiontime graph
	where |E|=|V| * |V|
	in graph 
	every vertex is connected with each vertex
	*/
	if(check==2){
		cout<<"Enter  number of vertex |V| only as |E|=|V|*|V|"<<endl;
	    cin>>V;
	    E=V*V;
	
	Edge *Elist=new Edge(V);
	
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
		
		//select a random cost b/w 1-10
		int c=rand() % 10 + 1;
	    
	    Elist->Addedge(i,j,c);
	}
	}
	//add timer here to calculate execution time
	clock_t start;
	double duration;
	start = clock();
	Elist->bellmenford();
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	cout<<"for |V|="<<V<<"  |E|="<<E<<" Time:"<<duration <<" seconds"<<endl;
	}
	if(check==3){
		cout<<"Enter  number of vertex |V| Edge |E|"<<endl;
	cin>>V>>E;
	
	Edge *Elist=new Edge(V);
	
	
	cout<<" enter edge.. edge from --> edge to .. and edge cost"<<endl;	
	for(int i=0;i<E;i++){
	    int f,t,c;
	    cin>>f>>t>>c;
	    Elist->Addedge(f,t,c);
	}
	//add timer here to calculate execution time
	clock_t start;
	double duration;
	start = clock();
	Elist->bellmenford();
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	cout<<"for |V|="<<V<<"  |E|="<<E<<" Time:"<<duration <<" seconds"<<endl;
	}
	
	return 0;
}
