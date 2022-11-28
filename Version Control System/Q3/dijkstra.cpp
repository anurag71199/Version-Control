#include <iostream>
#include <limits.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;

int dist[100000]; 

struct listnode
{
    int dest;
    int wt;
    struct listnode* next;
};

struct mylist
{
   struct listnode *head;
};

struct heapnode
{
    int  v;
    int dist;
};
 
struct myheap
{    
    int cap; 
    int size;    
    int *pos;   
    struct heapnode **arr;
};
 
struct mygraph
{
    int V;
    struct mylist* arr;
};

struct listnode* makenode(int dest, int wt)
{
    struct listnode* newNode = new listnode();
    newNode->dest = dest;
    newNode->wt = wt;
    newNode->next = NULL;
    return newNode;
}

struct mygraph* makegraph(int n)
{
    struct mygraph* graph = new mygraph();
    graph->V = n;

    graph->arr = (struct mylist*)malloc(n * sizeof(struct mylist));

    for (int i = 0; i < n; i++){
        graph->arr[i].head = NULL;
    }
    return graph;
}

void make_edge(struct mygraph* graph, int src,int dest, int wt)
{
    struct listnode* newNode = makenode(dest, wt);
    newNode->next = graph->arr[src].head;
    graph->arr[src].head = newNode;
 
    newNode = makenode(src, wt);
    newNode->next = graph->arr[dest].head;
    graph->arr[dest].head = newNode;
}
 
struct heapnode* make_heapnode(int v,int dist)
{
    struct heapnode* minHeapNode = new heapnode();    
    minHeapNode->v = v;
    minHeapNode->dist = dist;
    return minHeapNode;
}

struct myheap* make_myheap(int cap)
{
    struct myheap* minHeap = new myheap();
    minHeap->pos = (int *)malloc(cap * sizeof(int));
    minHeap->size = 0;
    minHeap->cap = cap;
    minHeap->arr =(struct heapnode**)malloc(cap*sizeof(struct heapnode*));
    return minHeap;
}

void replace_heapnode(struct heapnode** n1,struct heapnode** n2)
{
    struct heapnode* temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void heapify(struct myheap* minHeap,int idx)
{
    int mini = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
 
    if (left < minHeap->size && minHeap->arr[left]->dist < minHeap->arr[mini]->dist){
        mini = left;
    }
 
    if (right < minHeap->size && minHeap->arr[right]->dist < minHeap->arr[mini]->dist){
        mini = right;
    }

    if (mini != idx)
    {
        heapnode *smallestNode = minHeap->arr[mini];
        heapnode *idxNode = minHeap->arr[idx];
 
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = mini;
 
        replace_heapnode(&minHeap->arr[mini], &minHeap->arr[idx]);
        heapify(minHeap, mini);
    }
}

struct heapnode* get_top(struct myheap* minHeap)
{
    if(minHeap->size == 0)
        return NULL;
 
    struct heapnode* root = minHeap->arr[0];
 
    struct heapnode* lastNode = minHeap->arr[minHeap->size - 1];
    minHeap->arr[0] = lastNode;
 
    minHeap->pos[root->v] = minHeap->size-1;
    minHeap->pos[lastNode->v] = 0;

    minHeap->size = minHeap->size - 1;
    heapify(minHeap, 0);
 
    return root;
}

void decreaseKey(struct myheap* minHeap, int v, int dist)
{
    int i = minHeap->pos[v];

    minHeap->arr[i]->dist = dist;
 
    while (i && minHeap->arr[i]->dist < minHeap->arr[(i - 1) / 2]->dist)
    {
        minHeap->pos[minHeap->arr[i]->v] = (i-1)/2;
        minHeap->pos[minHeap->arr[(i-1)/2]->v] = i;
        replace_heapnode(&minHeap->arr[i], &minHeap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void explore(struct mygraph* graph, int src)
{
     
    int V = graph->V;

    struct myheap* minHeap = make_myheap(V);
 
    for (int v = 0; v < V; ++v)
    {
        // if(pass==0)
            dist[v] = INT_MAX;
        // for(int j=0;j<k+1;j++){
            // if(src == police[j]){
                minHeap->arr[v] = make_heapnode(v,dist[v]);
                minHeap->pos[v] = v;
            // }
        // }
    }
 
    minHeap->arr[src] = make_heapnode(src, dist[src]);
    minHeap->pos[src] = src;
    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);
 
    minHeap->size = V;
 
    while (!(minHeap->size == 0))
    {
        struct heapnode* minHeapNode = get_top(minHeap);
       
        int u = minHeapNode->v;

        struct listnode* l = graph->arr[u].head;
        while (l != NULL)
        {
            int v = l->dest;

            if ( minHeap->pos[v] < minHeap->size && dist[u] != INT_MAX && l->wt + dist[u] < dist[v])
            {
                dist[v] = dist[u] + l->wt;
                decreaseKey(minHeap, v, dist[v]);
            }
            l = l->next;
        }
    }
}

void calldijkstra(struct mygraph* graph,int n,int police[],int k)
{
    for(int i=0;i<k;i++){
        make_edge(graph,n,police[i],0);
        //  explore(graph, police[i],i,police,k);
    }
    explore(graph, n);
    for(int i = 0; i < n; i++)
    {
        if(dist[i] == INT_MAX)
            cout<<"-1 ";
        else
            cout<<dist[i]<<" ";
    }
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int u,v,w;
    struct mygraph* graph = makegraph(n+1);

    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        make_edge(graph, u-1, v-1, w);
    }

    int police[n+1];
    int temp;
    int i;
    for(i=0;i<k;i++){
        cin>>temp;
        police[i]=temp-1;
    }
    police[i] = n;
    // auto start = high_resolution_clock::now();

    calldijkstra(graph,n,police,k);

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "\nTime taken by function: "<< duration.count() << " microseconds" << endl;

    return 0;
}