class Solution 
{
    public Node connect(Node root) 
	{
        if(root == null) return null;
        connect(root.left, root.right);
        return root;
    }
    
    public void connect(Node left, Node right) 
	{
        // Since it's perfect binary checking left is null is sufficient for base condition.
        if( left == null ) return;
        
        // Set left's next {left.next} pointer to {right} node.
        left.next = right;
        
        // Call {connect} for left's left and right, left's right and right's left, and right's left and right.
        connect(left.left, left.right);
        connect(left.right, right.left);
        connect(right.left, right.right);
    }
}
