class TreeNode
  attr_accessor :val, :left, :right
  def initialize(val)
    @val = val
    @left, @right = nil, nil
  end
end

def print_tree(root)
  # First check the depth, then fill the matrix
  depth_recursive = lambda do |node|
    unless node.nil?
      [depth_recursive.call(node.left) + 1,
       depth_recursive.call(node.right) + 1].max
    else
      0
    end
  end
  depth = depth_recursive.call(root)

  cols = 2 ** depth - 1
  output = (0...depth).map { [''] * cols }.to_a
  fill_element = lambda do |node, l, r, d|
    i = (r - l) / 2 + l
    output[d][i] = node.val.to_s
    fill_element.call(node.left, l, i - 1, d + 1) unless node.left.nil?
    fill_element.call(node.right, i + 1, r, d + 1) unless node.right.nil?
  end
  fill_element.call(root, 0, cols - 1, 0)

  output
end
