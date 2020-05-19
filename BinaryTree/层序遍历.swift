
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
    func levelOrder(_ root: TreeNode?) -> [[Int]] {
        var res: [[Int]] = []
        var dfs: [TreeNode?] = []
        dfs.append(root!)
        while !dfs.isEmpty {
            var _res: [Int] = []
            var _dfs: [TreeNode?] = []
            for temp in dfs {
                if temp != nil {
                    _res.append(temp!.val)
                    if temp!.left != nil {_dfs.append(temp!.left)}
                    if temp!.right != nil {_dfs.append(temp!.right)}   
                }
            }
            dfs = _dfs
            if _res.count > 0 {
                res.append(_res)
            }
        }
        return res
    }
}