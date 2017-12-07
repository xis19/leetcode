class TreeNode
    attr_accessor :val, :left, :right
    def initialize(val)
        @val = val
        @left, @right = nil, nil
    end
end

def serialize(root)
  return '' if root.nil?

  tree = []
  traverse = lambda do |node|
    tree.push(node.val)
    if node.left.nil? && node.right.nil?
      tree.push('X')
      return
    end
    if node.left.nil?
      tree.push('#')
    else
      traverse.call(node.left)
    end
    if node.right.nil?
      tree.push('X')
    else
      traverse.call(node.right)
    end
  end
  traverse.call(root)
  puts tree.map { |i| i.to_s }.join(',')
end

def deserialize(data)
  tree = data.split(',')
  return nil if tree.empty?

  root = TreeNode.new(tree[0])
  stack = [[root, :l]]
  (1...tree.length).map { |i| tree[i] }.each do |item|
    if item =~ /[+-]?[0-9]+/
      node = TreeNode.new(item.to_i)
      if stack.last[1] == :l
        stack.last[0].left = node
        stack.last[1] = :r
      else
        stack.last[0].right = node
        stack.last[1] = :d
      end
      stack.push([node, :l])
    elsif item == 'X'
      stack.pop
      stack.pop while !stack.empty? && stack.last[1] == :d
    elsif item == '#'
      stack.last[1] = :r
    end
  end

  root
end
