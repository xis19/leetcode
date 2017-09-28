def add_one_row(root, v, d)

  def traverse(rt, v, d)
    if d > 2
      add_one_row(rt.left, v, d - 1) unless rt.left.nil?
      add_one_row(rt.right, v, d - 1) unless rt.right.nil?
    else
      l = rt.left
      rt.left = TreeNode.new(v)
      rt.left.left = l

      r = rt.right
      rt.right = TreeNode.new(v)
      rt.right.right = r
    end
    rt
  end

  if d == 1
    node = TreeNode.new(v)
    node.left = root
    node
  else
    traverse(root, v, d)
  end
end
