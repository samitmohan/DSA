class Solution {
	public Node connect(Node root) {
		// base case
		if (root == null || root.left == null) return;
		// ans
		connectNodes(root.left, root.right);
	}

	public void connectNodes(Node node1, Node node2) {
		node1.next = node2; // connect node1 and node2
		if (node1.left != null) {
			connectNodes(node1.right, node2.left);
			connectNodes(node1.left, node1.right);
			connectNodes(node2.left, node2.right);
		}
	}
}
