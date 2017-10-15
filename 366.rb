class TreeNode
    attr_accessor :val, :left, :right
    def initialize(val)
        @val = val
        @left, @right = nil, nil
    end
end


def find_leaves(root)
  result  = []

  # Introduce a "depth" variable, so the node knows when it will be removed.
  # e.g.
  #        1(2)
  #      /   \
  #     2(1)  3(0)
  #   /   \
  #  4(0)  5(0)
  visit = lambda do |node|
    return 0 if node.nil?

    depth = [visit.call(node.left), visit.call(node.right)].max
    if depth >= result.length
      result << []
    end
    result[depth].push(node.val)

    return depth + 1
  end

  visit.call(root)
  return result
end
