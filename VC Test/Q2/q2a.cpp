#include <iostream>
#include <string.h>
#include <vector>
#define mapsize 1007
using namespace std;

template <class T1, class T2>
class node
{
public:
    T1 key;
    T2 val;
    node *next;
};

template <class T1, class T2>
class mapchain
{
    int count;
    node<T1, T2> *chain;

public:
    mapchain<T1, T2>()
    {
        chain = NULL;
        count = 0;
    }

    void insert(T1 key, T2 val)
    {
        // if node exists
        if (find(key))
        {
            node<T1, T2> *it = chain;
            while (it != NULL)
            {
                if (it->key == key)
                {
                    it->val = val;
                    break;
                }
                it = it->next;
            }
        }
        // if node does not exist
        else
        {
            node<T1, T2> *newnode = new node<T1, T2>;
            newnode->key = key;
            newnode->val = val;
            newnode->next = NULL;
            if (chain == NULL)
            {
                chain = newnode;
            }
            else
            {
                newnode->next = chain->next;
                chain->next = newnode;
            }
            count++;
        }
    }

    bool find(T1 key)
    {
        if (chain == NULL)
        {
            return false;
        }
        node<T1, T2> *it = chain;
        while (it != NULL)
        {
            if (it->key == key)
            {
                return true;
            }
            it = it->next;
        }
        return false;
    }

    void erase(T1 key)
    {
        // if node exists
        if (find(key))
        {
            node<T1, T2> *it = chain;
            if (it->key == key)
            {
                chain = it->next;
                return;
            }
            while (it->next != NULL)
            {
                if (it->next->key == key)
                {
                    it->next = it->next->next;
                    break;
                }
                it = it->next;
            }
        }
        // if node does not exist
        else
        {
            return;
        }
    }

    T2 operator[](T1 key)
    {
        T2 a;
        if (find(key))
        {
            node<T1, T2> *it = chain;
            while (it != NULL)
            {
                if (it->key == key)
                {
                    return it->val;
                }
                it = it->next;
            }
            return it->val;
        }
        else
        {
            return a; // default val
        }
    }
};

int makehash(int key)
{
    int keyhash = key % mapsize;
    return keyhash;
}

int makehash(float key)
{
    int keyhash = int(key) % mapsize;
    return keyhash;
}

int makehash(double key)
{
    int keyhash = int(key) % mapsize;
    return keyhash;
}

int makehash(string key)
{
    int keyhash = 0; // = key%mapsize;
    for (int i = 0; i < key.size(); i++)
    {
        keyhash += int(key[i]); // maybe can do /2
    }
    return keyhash;
}

int makehash(char key)
{
    int keyhash = int(key); // maybe can do /2
    return keyhash;
}

int main(){
    int tests,op,hash;
    int key; //change data types here
    int val; //change data types here
    cin>>tests;
    mapchain<int,int> maparr[mapsize+1]; //change data types here
    for(int i=0;i<tests;i++){
        cin>>op;
        if(op == 1){
            cin>>key;
            cin>>val;
            hash = makehash(key);
            maparr[hash].insert(key,val);
        }
        if(op == 2){
            cin>>key;
            hash = makehash(key);
            maparr[hash].erase(key);
        }
        if(op == 3){
            cin>>key;
            hash = makehash(key);
            cout<<maparr[hash].find(key)<<"\n";
        }
        if(op == 4){
            cin>>key;
            hash = makehash(key);
            cout<<maparr[hash][key]<<"\n";
        }
    }
    return 0;
}