class MyLinkedList {
    struct Node{
        int val;
        Node* next;
        Node(int x){
            val=x;
            next=NULL;
        }
    };
    Node* dummy;
    int size;
public:
    MyLinkedList() {
        dummy=new Node(-1);
        size=0;
    }
    
    int get(int index) {
        if(index<0||index>=size){return -1;
        }
        Node* cur=dummy->next;
        while(index--){
            cur=cur->next;}
        return cur->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        if(index<0||index>size){
            return;
        }
        Node* cur=dummy;
        for(int i=0;i<index;i++){
            cur=cur->next;
        }
        Node* temp1=new Node(val);
        temp1->next=cur->next;
        cur->next=temp1;
        size++;
    }
    
    void deleteAtIndex(int index){
        if(index<0||index>=size){
            return;
        }
        Node* cur=dummy;
        for(int i=0;i<index;i++){
            cur=cur->next;
        }
        Node* temp1=cur->next;
        cur->next=temp1->next;
        delete temp1;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */