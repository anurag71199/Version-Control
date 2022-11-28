#include<iostream>
#include<string.h>
#define mapsize 1007
using namespace std;

template <class T1, class T2>
class node{
    public:
    T1 key;
    T2 val;
    node* next;
};

template <class T1, class T2>
class mapchain{
    int count;
    node<T1,T2>* chain;
    public:
    mapchain<T1,T2>(){
        chain = NULL;
        count=0;
    }

    void insert(T1 key, T2 val){
        //if node exists
        if(find(key)){
            node<T1,T2>*it = chain;
            while(it != NULL){
                if(it->key == key){
                    it->val = val;
                    break;
                }
            it = it->next;
            }
        }
        //if node does not exist
        else{
        node<T1,T2>* newnode = new node<T1,T2>;
        newnode->key = key;
        newnode->val = val;
        newnode->next = NULL;
        if(chain == NULL){
            chain = newnode;
        }    
        else{
            newnode->next = chain->next;
            chain->next = newnode;
            // chain = newnode;
        }
        count++;
        }
    }

    bool find(T1 key){
        if( chain == NULL){
            return false;
        }
        node<T1,T2>* it = chain;
        while(it != NULL){
            if(it->key == key){
                return true;
            }
            it = it->next;
        }
        return false;
    }

    void erase(T1 key){
        //if node exists
        if(find(key)){
            node<T1,T2>*it = chain;
            if( it->key == key){
                chain = it->next;
                return;
            }
            while(it->next != NULL){
                if(it->next->key == key){
                    it->next = it->next->next;
                    break;
                }
                it = it->next;
            }
        }
        //if node does not exist
        else{
            return;
        }
    }

    T2 operator[](T1 key){
        if(find(key)){
            node<T1,T2>* it = chain;
            while(it != NULL){
                if(it->key == key){
                    return it->val;
                }
                it = it->next;
            }
            return it->val;
        }
        else{
            return 0; //default val
        }
    }

};

int makehash(int key){
        int keyhash = key%mapsize;
        return keyhash;
} 

int makehash(float key){
        int keyhash = int(key)%mapsize;
        return keyhash;
} 

int makehash(double key){
        int keyhash = int(key)%mapsize;
        return keyhash;
} 

int makehash(string key){
        int keyhash=0;// = key%mapsize;
        for(int i=0;i<key.size();i++){
            keyhash += int(key[i]); //maybe can do /2 
        }
        return keyhash;
} 

int makehash(char key){
        int keyhash = int(key); //maybe can do /2 
        return keyhash;
} 

// template <typename T1,typename T2>
// void unordered_mapadd(mapchain<T1,T2> map[], T1 key,T2 val){
    
//     int hash = makehash(key);
//     map[hash].insert(key,val);
//     return;
// };

// template <typename T1,typename T2>
// bool unordered_mapfind(mapchain<T1,T2> map[], T1 key){
    
//     int hash = makehash(key);
//     return map[hash].find(key);
// };

template <typename T1,typename T2>
T2 unordered_mapop(mapchain<T1,T2> map[], T1 key){
    
    int hash = makehash(key);
    return map[hash][key];
};

// template <typename T1,typename T2>
// void unordered_maperase(mapchain<T1,T2> map[], T1 key){
    
//     int hash = makehash(key);
//     map[hash].erase(key);
//     return;
// };

int main(){
    int q;
    cin>>q;
    int op;
    mapchain<int,int> maparr[mapsize]; //change type here
    int key,val; //change type here
    for(int i=0;i<q;i++){
        cin>>op;
        if(op == 1){
            cin>>key>>val;
            // unordered_mapadd(maparr,key,val);
            int hash = makehash(key);
            maparr[hash].insert(key,val);
        }
        else if(op == 2){
            cin>>key;
            // unordered_maperase(maparr,key);
            int hash = makehash(key);
            maparr[hash].erase(key);
        }
        else if(op == 3){
            cin>>key;
            // cout<<unordered_mapfind(maparr,key)<<"\n";
            int hash = makehash(key);
            cout<<maparr[hash].find(key)<<"\n";
        }
        else if(op == 4){
            cin>>key;
            // cout<<unordered_mapfind(maparr,key)<<"\n";
            cout<<unordered_mapop(maparr,key)<<"\n";
        }
    }
    return 0;
}