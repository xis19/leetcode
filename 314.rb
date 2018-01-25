class TreeNode
  attr_accessor :val, :left, :right
  def initialize(val)
    @val = val
    @left, @right = nil, nil
  end
end

# A tree
#         1
#        / \
#       /   \
#      2    3
#     / \  / \
#     4 5  8 9
#      / \
#      7  6
#
# will be coverted into
# [[4],[2,7],[1,5,8],[3,6],[9]]
#
# while
#
#         3
#        / \
#       /   \
#      9     8
#     / \   / \
#     4 0   1 7
#       \   /
#       2   5
#
# will be converted into
# [[4],[9,5],[3,0,1],[8,2],[7]]
#
# Because we need top-down, left-right order. This implies a rowwise traverse
# of the tree

def vertical_order(root)
  return [] if root.nil?

  hash = Hash.new { |hash, v| hash[v] = [] }
  queue = [[root, 0]]

  while !queue.empty?
    head = queue.shift
    hash[head[1]].push(head[0].val)
    queue.push([head[0].left, head[1] - 1]) unless head[0].left.nil?
    queue.push([head[0].right, head[1] + 1]) unless head[0].right.nil?
  end

  # Find the minimal index of the hash
  min_index = hash.keys.min
  shift = min_index.abs

  # Convert to integer
  result = []
  hash.each { |k, v| result[k + shift] = v }

  result
end


def vertical_order_bad_order(root)
  return [] if root.nil?
  hash = Hash.new { |hash, v| hash[v] = [] }
  (traverse = lambda do |node, index|
    return if node.nil?
    hash[index].push(node.val)
    traverse.call(node.left, index - 1)
    traverse.call(node.right, index + 1)
  end).call(root, 0)

  # Find the minimal index of the hash
  min_index = hash.keys.min
  shift = min_index.abs

  # Convert to integer
  result = []
  hash.each { |k, v| result[k + shift] = v }

  result
end
