public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init(_ val: Int) {
        self.val = val
        self.left = nil
        self.right = nil
    }
}

class Solution {
    var inhash = [Int: Int]()
    func getTree(_ preorder: [Int], _ inorder: [Int], _ preLeft: Int, _ preRight: Int, _ inLeft: Int, _ inRight: Int) -> TreeNode? {
        if preLeft > preRight {
            return nil
        }
        let preorderRoot = preLeft
        let inorderRoot = inhash[preorder[preorderRoot]]
        let root = TreeNode(preorder[preorderRoot])
        let sizeOfSubleft = inorderRoot! - inLeft
        root.left = getTree(preorder, inorder, preLeft + 1, preLeft + sizeOfSubleft, inLeft, inorderRoot! - 1)
        root.right = getTree(preorder, inorder, preLeft + sizeOfSubleft + 1, preRight, inorderRoot! + 1, inRight)
        return root
    }
    func buildTree(_ preorder: [Int], _ inorder: [Int]) -> TreeNode? {
        let preLen = preorder.count, inLen = inorder.count
        for i in 0..<inLen {
            inhash[inorder[i]] = i
        }
        return getTree(preorder, inorder, 0, preLen - 1, 0, inLen - 1)
    }
}