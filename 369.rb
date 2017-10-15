class ListNode
  attr_accessor :val, :next
  def initialize(val)
    @val = val
    @next = nil
  end
end

def plus_one(head)
  def plus(head)
    if head.nil?
      1
    else
      head.val = (head.val + plus(head.next)) % 10
      if head.val == 0
        1
      else
        0
      end
    end
  end
  plus(head)
  head
end
