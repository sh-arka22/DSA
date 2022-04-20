
//105. Construct Binary Tree from Preorder and Inorder Traversal

var buildTree = (preorder, inorder) => {
    
    return construct(preorder, inorder,0 ,preorder.length-1, 0, inorder.lenght-1);
};

function construct(pre, ino, plo, phi, ilo, ihi){
    if(plo > phi || ilo >ihi){
        return null;;
    }

    let nn = TreeNode();
    nn.val = pre[plo];
    let si = -1;

    for(let i=ilo; i <= ihi ; i++){
        
    }
}