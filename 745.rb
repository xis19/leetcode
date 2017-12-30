require 'set'
def next_greatest_letter(letters, target)
  letter_set = Set.new(letters)
  (target.succ..'z').each { |ch| return ch if letter_set.include?(ch) }
  ('a'..target).each { |ch| return ch if letter_set.include?(ch) }
end
