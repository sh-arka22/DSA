function reverse(){
    if(st.isEmpty()){
        return;
    }
    let val = st.pop();
    reverse();
    insertAtBottom(val);
}