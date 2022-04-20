class Node {
    constructor(data){
        this.data = data;
        this.next = null;
    }
}

class SinglyLinkedList {
    constructor(){
        this.head = null;
        this.length = 0;
    }

    addFirst(data) {
        let newNode = new Node(data);
        newNode.next = this.head;
        this.head = newNode;
        this.length++;
    }

    addLast(data) {
        let newNode = new Node(data);
        if(this.head === null){
            this.head = newNode;
            this.length++;
        }
        else {
            let currentNode = this.head;
            while(currentNode.next !== null){
                currentNode = currentNode.next;
            }
            currentNode.next = newNode;
            this.length++;
        }
    }

    addIndex(data,index) {
        if(index == 0){
            this.addFirst(data);
        }
        if(index < 0 || index >= this.length) {
            console.log("index out of bound");
        }
        else {
            let newNode = new Node(data);

            let curr, prev;

            curr = this.head;

            let cnt = 0;

            while(cnt < index){
                prev = curr;
                curr = curr.next;
                cnt++;
            }

            newNode.next = curr;
            prev.next = newNode;
            this.length++;
        }
    }

    print() {
        let currentNode = this.head;

        while (currentNode != null) {
            console.log(currentNode.data);
            // console.log(currentNode);
            currentNode = currentNode.next;
        }
    }
}

const ll = new SinglyLinkedList();
ll.addFirst(10);
ll.addFirst(20);
ll.addFirst(30);
ll.addFirst(40);
ll.addLast(50);
ll.addLast(60);
ll.addIndex(70,3);

ll.print();