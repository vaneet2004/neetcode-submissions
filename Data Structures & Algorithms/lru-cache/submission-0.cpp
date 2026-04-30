class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* next;
        Node* prev;
        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> m;
    int limit;

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* oldNext = head->next;

        newNode->next = oldNext;
        newNode->prev = head;

        head->next = newNode;
        oldNext->prev = newNode;
    }

    void delNode(Node* oldNode) {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }

        Node* node = m[key];
        int ans = node->val;

        delNode(node);
        addNode(node);

        return ans;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
        }

        if (m.size() == limit) {
            Node* lru = tail->prev;
            m.erase(lru->key);
            delNode(lru);
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};