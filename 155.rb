class MinStack

  def initialize()
    @min = []
    @stack = []
  end

  def push(x)
    @stack.push(x)
    @min.push(@min.last.nil? ? x : [@min.last, x].min)
  end

  def pop()
    @min.pop
    @stack.pop
  end

  def top()
    @stack.last
  end

  def get_min()
    @min.last
  end

end
