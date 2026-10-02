class LRUCache {
public:
    struct Node{
        int key,value;
        Node *next, *prev;

        // Node(int k, int v){
        //     key=k;
        //     value=v;
        //     next=prev= NULL;
        // }
    };

    int capacity;
    unordered_map<int, Node*> mpp;
    Node *head, *tail;

    LRUCache(int capacity) {
        this->capacity= capacity;

        head= new Node(0,0);
        tail= new Node(0,0);
        head->next=tail;
        tail->prev=head;    
    }

    void deleteNode(Node* node){
        node->prev->next= node->next;
        node->next->prev= node->prev;
    }

    void insertAfter_head(Node* node){
        node-> next= head->next;
        node-> prev= head;

        head->next->prev=node;
        head->next=node;  
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end())
            return -1;
        Node* node= mpp[key];
        deleteNode(node);
        insertAfter_head(node);

        return node->value;    
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!= mpp.end()){    // key found
           Node* node= mpp[key];
           node->value= value;

           deleteNode(node);
           insertAfter_head(node);
        }
        else{
            if(mpp.size()==capacity){
                Node* oldnode= tail->prev;
                mpp.erase(oldnode->key);
                deleteNode(oldnode);
                delete oldnode;
            }
            Node* node= new Node(key, value);
            mpp[key]= node;
            insertAfter_head(node);
            
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */