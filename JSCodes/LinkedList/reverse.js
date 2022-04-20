var reverseList = function(head) {
    let prev = null;
    let curr = head;

    while(curr != null) {
        let forw = curr.next;
        curr.next = prev;
        prev = curr;
        curr = forw;
    }

    return prev;
};