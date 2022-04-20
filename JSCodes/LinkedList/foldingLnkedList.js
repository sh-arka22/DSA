// middle of a linked list
var middle = function(head){
    let slow = head;
    let fast = head;
    
    while(fast != null && fast.next != null){
        slow = slow.next;
        fast = fast.next.next;
    }
    
    return slow;
}

// reversing a linked list
var reverseList = (head) => {
    let prev = null;
    let curr = head;

    while (curr != null) {
        let forw = curr.next;
        curr.next = prev;
        prev = curr;
        curr = forw;
    }

    return prev;
}

var reorderList = function(head) {
    let mid = middle(head);
    let nHead = mid.next;
    mid.next = null;
    nHead = reverseList(nHead);
    
    let c1 = head;
    let c2 = nHead;
    let f1 = null;
    let f2 = null;
    
    while(c2 != null){
        f1=c1.next; //backup
        f2=c2.next;//backup

        c1.next=c2;//link
        c2.next=f1;//link

        c1=f1;//move
        c2=f2;//move
    }
};