#include <functional>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool isPalindrome(ListNode* head) {
    if (head == nullptr)
        return true;

    // We find the middle of the list, reverse the latter part and compare the
    // two parts to see if it is palindrome.
    ListNode* slow = head;
    ListNode* fast = head;

    // Two situations
    //  1. even number of elements
    //      1 2 3 4
    //      ^^
    //        ^ ^
    //        ^   ^ -> has to stop
    //     when the fast iterator reach the end of the list, the slow iterator
    //     has to move to the next one, as the beginning of the reverse
    //  2. odd number of elements
    //      1 2 3 4 5
    //      ^^
    //        ^ ^
    //          ^   ^
    //     still the slow iterator has to move to the next one.
    while(fast->next != nullptr) {
        fast = fast->next;
        if (fast->next == nullptr)
            break;
        slow = slow->next;
        fast = fast->next;
    }
    // Only 1 element in the queue?
    if (slow == fast)
        return true;
    slow = slow->next;

    // Recursively reverse the list starting with slow
    std::function<ListNode*(ListNode*)> reverse = [&](ListNode* node) -> ListNode* {
        if (node->next) {
            ListNode* nextNode = reverse(node->next);
            nextNode->next = node;
            node->next = nullptr;
        }
        return node;
    };
    reverse(slow);

    // check list start with fast and head, see if they are the same
    ListNode* i1 = head;
    ListNode* i2 = fast;
    while(i2 != nullptr) {
        if (i1->val != i2->val) {
            return false;
        }
        i1 = i1->next;
        i2 = i2->next;
    }
    return true;
}

/*******************************************************************************
 Ruby version, with stack too deep problem

def is_palindrome(head)
  return true if head.nil?

  iter = head
  len = lambda do
    iter, c = head, 1
    (iter, c = iter.next, c + 1) until iter.next.nil?
    c
  end.call
  return true if len == 1

  # We reverse the second half of the linked list
  half = len / 2 + (len % 2)

  half_head = head
  (0...half).each { half_head = half_head.next }
  reverse = lambda do |node|
    unless node.next.nil?
      next_node = reverse.call(node.next)
      node.next = nil
      next_node.next = node
    end
    node
  end
  reverse.call(half_head)

  # And compare the reversed second half with the first half
  i, j = head, iter
  (0...len / 2).each do
    return false if i.val != j.val
    i, j = i.next, j.next
  end
  true
end
*******************************************************************************/
