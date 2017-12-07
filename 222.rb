class TreeNode
  attr_accessor :val, :left, :right
  def initialize(val)
    @val = val
    @left, @right = nil, nil
  end
end


def count_nodes(root)
  visit_left = lambda do |node|
    count = 0
    while !node.nil?
      count += 1
      node = node.left
    end
    count
  end

  visit_right = lambda do |node|
    count = 0
    while !node.nil?
      count += 1
      node = node.right
    end
    count
  end

  counter = lambda do |node, lhs, rhs|
    return 0 if node.nil?
    lhs = visit_left.call(node) if lhs.nil?
    rhs = visit_right.call(node) if rhs.nil?
    if lhs == rhs
      2 ** lhs - 1
    else
      counter.call(node.left, lhs - 1, nil) + counter.call(node.right, nil, rhs - 1) + 1
    end
  end

  counter.call(root, nil, nil)
end
