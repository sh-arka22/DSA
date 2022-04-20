/**
 * Using Arrays
 */
class Stack {
    constructor() {
        this.data = [];
        this.top = 0;
    }

    push(ele){
        this.data[this.top] = ele;
        this.top = this.top + 1;
    }

    pop(){
        this.top = this.top - 1;
        let del = this.data[this.top];
        this.data[this.top] = -1;
        return del;
    }

    isEmpty() {
        return this.top === 0;
    }

    peek(){
        this.top = this.top - 1;
        let up = this.data[this.top];
        return up;
    }
}

const st = new Stack();

st.push(45);
st.push(40);
st.push("soumi");
st.push("loves arka");

console.log(st.pop());
console.log(st.pop());
console.log(st.isEmpty());
console.log(st.peek());

// ADDING AT THE BOTTOM OF THE STACK
function insertAtBottom(ele) {
    if(st.isEmpty()){
        st.push(ele);
    }

    var val = st.pop();
    insertAtBottom(ele);
    st.push(val);
}

// reversing the stack
function reverse(){
    if(st.isEmpty()){
        return;
    }
    let val = st.pop();
    reverse();
    insertAtBottom(val);
}