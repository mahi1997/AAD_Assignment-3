#include <iostream>
using namespace std;
#define INFINITY 99999

class Edge{
	int* distance;
	int* travelfrom;
	int Vertex;
	struct E_node{
		int from;
		int to;
		int cost;
		E_node *link;
	}*first;
	public:
		Edge(){
			cin>>Vertex;
			
			first=NULL;
			distance=new int[Vertex];
			travelfrom=new int[Vertex];
			distance[0]=0;
	       for(int i=1;i<Vertex;i++){
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
			p=p->link;
		}
		if(neg_loop==true){
			cout<<"negative loop found"<<endl;
		}
		else{
			cout<<"Result is : Travel vertex <--- from  vertex (...)  cost:"<<endl;
			for(int i=1;i<Vertex;i++)
			cout<<i<<" <---- "  <<travelfrom[i]<< "   :"<<distance[i]<<endl;
		}
	}
		
	
};

int main(){
	int E, V;
	cout<<"Enter number of vertex |V| and number of Edge |E|"<<endl;
	cin>>V>>E;
	
	Edge Elist;
	
	
	cout<<" enter edge.. edge from --> edge to .. and edge cost"<<endl;	
	for(int i=0;i<E;i++){
	    int f,t,c;
	    cin>>f>>t>>c;
	    Elist.Addedge(f,t,c);
	}
	//add timer here to calculate execution time
	Elist.relax();
	Elist.checkNegativeLoop();
	
}

