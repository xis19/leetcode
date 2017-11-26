class TreeNode
  attr_accessor :val, :left, :right
  def initialize(val)
    @val = val
    @left, @right = nil, nil
  end
end

def closest_value(root, target)
  traverse = lambda do |node|
    v = node.val
    d = (node.val - target).abs

    v1, d1 = v, d
    if target < node.val && !node.left.nil?
      v1, d1 = traverse.call(node.left)
    elsif target > node.val && !node.right.nil?
      v1, d1 = traverse.call(node.right)
    end

    if d1 < d
      [v1, d1]
    else
      [v, d]
    end
  end
  traverse.call(root)[0]
end
