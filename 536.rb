class TreeNode
    attr_accessor :val, :left, :right
    def initialize(val)
        @val = val
        @left, @right = nil, nil
    end
end

def str2tree(s)
  def consume_incoming(str)
    if str == ''
      [nil, '']
    else
      value = str.to_i
      node = TreeNode.new(value)
      remaining = str[value.to_s.length..-1]
      if remaining.start_with?('(')
        node.left, remaining = consume_incoming(remaining[1..-1])
      end
      if remaining.start_with?('(')
        node.right, remaining = consume_incoming(remaining[1..-1])
      end
      # drop )
      [node, remaining[1..-1]]
    end
  end
  consume_incoming(s)[0]
end
