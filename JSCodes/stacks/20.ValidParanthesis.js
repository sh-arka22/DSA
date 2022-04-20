var isValid = function(s) {
    
    const stack = [];

    for(let i = 0; i < s.length; i++) {
        let ch = s.charAt(i);
        if(ch == '(' || ch =='[' || ch == '{'){
            stack.push(ch);
        }
        else{
            if(ch == ')' && stack[stack.length - 1] != '('){
                return false;
            }
            else if(ch == '}' && stack[stack.length - 1] != '{'){
                return false;
            }
            else if(ch == ']' && stack[stack.length - 1] != '['){
                return false;
            }
            stack.pop();
        }
    }
    return stack.length == 0;
};

// USING ARROW FUNCTION
var isValid = (s) => { // Arrow function
    
    const stack = [];

    for(let i = 0; i < s.length; i++) {
        let ch = s.charAt(i);
        if(ch == '(' || ch =='[' || ch == '{'){
            stack.push(ch);
        }
        else{
            if(ch == ')' && stack[stack.length - 1] != '('){
                return false;
            }
            else if(ch == '}' && stack[stack.length - 1] != '{'){
                return false;
            }
            else if(ch == ']' && stack[stack.length - 1] != '['){
                return false;
            }
            stack.pop();
        }
    }
    return stack.length == 0;
};