class LRUCache {
public:
    struct Node {
        int key;
        int value;
        Node* pre;
        Node* suc;
        Node(int k, int v) : key(k), value(v), pre(nullptr), suc(nullptr) {}
    };

    int cap;
    Node* m_recent = nullptr;
    Node* l_recent = nullptr;
    unordered_map<int, Node*> keynode_map;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (keynode_map.count(key) == 0) return -1;

        Node* curr = keynode_map[key];
        moveToFront(curr);
        return curr->value;
    }

    void put(int key, int value) {
        if (keynode_map.count(key)) {
            Node* curr = keynode_map[key];
            curr->value = value;
            moveToFront(curr);
            return;
        }

        Node* curr = new Node(key, value);
        keynode_map[key] = curr;

        // insert at front
        if (m_recent == nullptr) {
            m_recent = l_recent = curr;
        } else {
            curr->suc = m_recent;
            m_recent->pre = curr;
            m_recent = curr;
        }

        // evict if needed
        if (keynode_map.size() > cap) {
            Node* to_delete = l_recent;
            keynode_map.erase(to_delete->key);

            l_recent = l_recent->pre;
            if (l_recent) l_recent->suc = nullptr;

            delete to_delete;
        }
    }

private:
    void moveToFront(Node* curr) {
        if (curr == m_recent) return;

        // detach
        if (curr->pre) curr->pre->suc = curr->suc;
        if (curr->suc) curr->suc->pre = curr->pre;

        // if it was least recent
        if (curr == l_recent) {
            l_recent = curr->pre;
        }

        // move to front
        curr->pre = nullptr;
        curr->suc = m_recent;
        if (m_recent) m_recent->pre = curr;
        m_recent = curr;
    }
};