class LRUCache {
public:
    //declare public variable for capacity
    int cap = 0;
    //node structure
    struct Node{
        Node* prev = nullptr;
        Node* next = nullptr;
        int key;
        int value;
    };

    //dict for storing nodes (key->node pointer mapping)
    unordered_map<int,Node*> mapping;

    //dummy head and tail for easier management
    Node* dummy_head = new Node();
    Node* dummy_tail = new Node();



    //pointers for tracked l_used and m_used -> skip as it can be done with dummy head/tail

    LRUCache(int capacity) {
        cap = capacity;
        //need to connect this two otherwise issue in adding the node in the cache
        dummy_head->next = dummy_tail;
        dummy_tail->prev = dummy_head; //also handles the first node issue
    }
    
    int get(int key) {
        //check if present
        if(mapping.count(key)>0){
            //if yes
                //update the m_used
                //update the node and its prev/next
                //return value
            if(dummy_head->next!=mapping[key]){
                //storing values that will be needed
                Node* curr_node = mapping[key];
                Node* old_m_used = dummy_head->next;

                //shortcircuitting the old values of curr
                curr_node->prev->next = curr_node->next; //now curr is detached
                curr_node->next->prev = curr_node->prev;

                //reattaching the curr_node with head
                dummy_head->next = curr_node;
                curr_node->prev = dummy_head;

                //reattching the curr_node with old_head
                curr_node->next = old_m_used;
                old_m_used->prev = curr_node;

                //returning the value
                return mapping[key]->value;
            }
            else{
                return mapping[key]->value;
            }
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        //check if present
        if(mapping.count(key)>0){
            //if yes
                //update the value in the node
                //(same procedure as get-yes)
            if(dummy_head->next!=mapping[key]){
                    //storing values that will be needed
                    Node* curr_node = mapping[key];
                    Node* old_m_used = dummy_head->next;

                    //shortcircuitting the old values of curr
                    curr_node->prev->next = curr_node->next; //now curr is detached
                    curr_node->next->prev = curr_node->prev;

                    //reattaching the curr_node with head
                    dummy_head->next = curr_node;
                    curr_node->prev = dummy_head;

                    //reattching the curr_node with old_head
                    curr_node->next = old_m_used;
                    old_m_used->prev = curr_node;

                    //updating the value
                    mapping[key]->value = value;
                }
                else{
                    mapping[key]->value = value;
                }
        
        
        }
        else{
            //else
                //make a new node
            Node* curr_node = new Node();
            curr_node->key = key;
            curr_node->value = value;

            //save the nodes which we need to manipulate
            Node* old_recent = dummy_head->next;

            //no need to shortcircuit the node as the node is unconnected

            //updating the bond of head and curr
            dummy_head->next = curr_node;
            curr_node->prev = dummy_head;

            //connecting curr_node and old_recent
            curr_node->next = old_recent;
            old_recent->prev = curr_node;

            //inserting this node in mapping
            mapping[key] = curr_node;

            //check whether the size of cache is more than cap
            if(mapping.size()>cap){
                //if yes
                    //remove last value and update l_recent
                //storing nodes for ref
                Node* old_recent = dummy_tail->prev;

                //shortcircuit old_recent's prev and tail
                old_recent->prev->next = dummy_tail;
                dummy_tail->prev = old_recent->prev; //now old_recent is detached

                //remove old_recent from mapping

                mapping.erase(old_recent->key);
                delete old_recent;
            }
                //else
                    //nothing to worry about
        }
    }
};
