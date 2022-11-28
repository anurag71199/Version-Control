// #include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define N 1000000

struct mypair{
    int u;
    int wt;
    mypair(){
     u = 0;
     wt = 0;   
    }
};

struct myarr{
    int count;
    mypair arr[100];
    myarr(){
        count=0;
    }
    void push(mypair p){
        arr[count] = p;
        count++;
    }
};

// This array stores the distances of the vertices
// from the nearest source
int dist[N];
 
//This boolean array is true if the current vertex
// is visited otherwise it is false
int visited[N];
 
int queue[100]; 
int qsize = 100;
int front = - 1, rear = - 1;
void enqueue(int val) {
      if (front == - 1)
        front = 0;
      rear++;
      queue[rear] = val;
}
void dequeue() {
   if (front == - 1 || front > rear) {
      cout<<"Queue Underflow ";
      exit(1);
      return ;
   } 
   else {
    //   cout<<"Element deleted from queue is : "<< queue[front] <<endl;
      front++;
   }
}

void addEdge(myarr graph[], int u, int v,int w)
{
    //Function to add 2 edges in an undirected graph
    mypair p1;
    mypair p2;
    
    p1.u = v;
    p2.u = u;

    p1.wt = w;
    p2.wt = w;

    // cout<<"init : "<<p1.u<<" "<<p1.wt<<"\n";
    // cout<<"init : "<<p2.u<<" "<<p2.wt<<"\n";
    graph[u].push(p1);
    graph[v].push(p2);
}
 
void Display() {
   if (front == - 1)
   cout<<"Queue is empty"<<endl;
   else {
      cout<<"Queue elements are : ";
      for (int i = front; i <= rear; i++)
      cout<<queue[i]<<" ";
         cout<<endl;
   }
}

// Multisource BFS Function
void Multisource_BFS(myarr graph[])
{
    while(front != rear)
    {
        int j = queue[front];
        cout<<"qf : "<<queue[front]<<" front = "<<front<<" rear: "<<rear<<"\n";
        dequeue();
        cout<<"post deq : \n";
        Display();
        cout<<"-\n";

        for(int i=0;i<graph[j].count;i++)
        {
            if(!visited[graph[j].arr[i].u])
            // {
     
                // Pushing the adjacent unvisited vertices
                // with distance from current source = this
                // vertex's distance + 1
                enqueue(graph[j].arr[i].u);
                // if(dist[graph[j].arr[i].u]>dist[j] + graph[j].arr[i].wt)
                    dist[graph[j].arr[i].u] = dist[j] + graph[j].arr[i].wt; //change plus one to distance
                visited[graph[j].arr[i].u] = 1;
            // }
        }
    }
}
 
 
// This function calculates the distance of each
// vertex from nearest source
void nearestTown(myarr graph[],int n,int police[],int k)
{
 
    //Mark all the source vertices as visited and enqueue it
    for(int i = 0;i<k;i++)
    {
        cout<<"adding : "<<police[i]<<"\n";
        enqueue(police[i]);
        visited[police[i]]=1;
    }
 
    Multisource_BFS(graph);
 
 
    //Printing the distances
    for(int i = 1; i <= n; i++)
    {
        cout<<dist[i]<<" ";
    }
 
}
 
 
// Driver code
int main()
{    
    int n,m,k;
    cin>>n>>m>>k;
    int u,v,w;

    myarr graph[n+1];
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        addEdge(graph, u, v, w);
    }

    //ds:
    // array of vectors
    // cout<<"\n\n";
    // for(int i=1;i<=n;i++){
    //     cout<<"i : "<<i<<"\n";
    //     for(int j=0;j<graph[i].count;j++){
    //         cout<<graph[i].arr[j].u<<" "<<graph[i].arr[j].wt<<"\n";
    //     }
    //     cout<<"\n";
    // }
 

    // vector<int> graph[n + 1];
    int police[n+1];
    int temp;
    for(int i=0;i<k;i++){
        cin>>temp;
        police[i]=temp;
    }
    // // Sources
    // int sources[] = { 1, 5 };
 
    // int S = sizeof(sources) / sizeof(sources[0]);
 
    nearestTown(graph, n, police, k);
 
    return 0;
}



// class myvect {
//     mypair* arr;
//     int capacity;
//     int current;
// public:
//     myvect()
//     {
//         arr = new mypair[1];
//         capacity = 1000;
//         current = 0;
//     }
//     void push(mypair p)
//     {
//         // if (current == capacity) {
//         //     // cout<<"entered if\n";
//         //     mypair* temp = new mypair[2 * capacity];
//         //     // copying old array elements to new array
//         //     for (int i = 0; i < capacity; i++) {
//         //         temp[i] = arr[i];
//         //     }
//         //     // deleting previous array
//         //     delete[] arr;
//         //     capacity *= 2;
//         //     arr = temp;
//         // }
//         // Inserting data
//         arr[current] = p;
//         // cout<<"arrprint "<<arr[p.u].u<<" "<<arr[p.u].wt<<"\n";
//         current++;
//         // cout<<"pushed : "<<p.u<<"\n";
//         // cout<<"pushed wt: "<<p.wt<<"\n";
//     }
//     // function to add element at any index
//     // void push(mypair data, int index)
//     // {
//     //     // if index is equal to capacity then this
//     //     // function is same as push defined above
//     //     if (index == capacity)
//     //         push(data);
//     //     else
//     //         arr[index] = data;
//     // }
//     // function to extract element at any index
//     mypair get(int index)
//     {
 
//         // if index is within the range
//         if (index < current)
//             return arr[index];
//     }
 
//     // function to delete last element
//     void pop() { current--; }
 
//     // function to get size of the vector
//     int size() { return current; }
 
//     // function to get capacity of the vector
//     int getcapacity() { return capacity; }
 
//     // function to print array elements
//     void print()
//     {
//         for (int i = 1; i <= current; i++) {
//             cout <<arr[i].u << " " << arr[i].wt<<"\n";
//         }
//         cout << endl;
//     }
// };