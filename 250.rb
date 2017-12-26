class TreeNode
  attr_accessor :val, :left, :right
  def initialize(val)
    @val = val
    @left, @right = nil, nil
  end
end

def count_unival_subtrees(root)
  return 0 if root.nil?

  count = 0
  traverse = lambda do |node|
    lhs_unival, lhs_val = node.left.nil? ? [true, nil] : traverse.call(node.left)
    rhs_unival, rhs_val = node.right.nil? ? [true, nil] : traverse.call(node.right)

    return [false, nil] unless lhs_unival && rhs_unival

    if [lhs_val, rhs_val, node.val].select { |i| !i.nil? }.uniq.length == 1
      count += 1
      [true, node.val]
    else
      [false, nil]
    end
  end

  traverse.call(root)
  count
end
