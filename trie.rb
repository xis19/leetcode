=begin
Implement a Trie data structure in Ruby
=end

class Trie
  private
  def get_hash
    Hash.new do |hash, v|
      if !!v == v
        # Boolean?
        hash[v] = nil
      else
        hash[v] = get_hash()
      end
    end
  end

  public
  attr_accessor :trie
  def initialize
    @trie = get_hash()
  end

  def insert(word)
    i = @trie
    word.each_char do |ch|
      i = i[ch]
    end
    i[true]
  end

  def include?(word)
    i = @trie
    word.each_char do |ch|
      return false unless i.include?(ch)
      i = i[ch]
    end
    i.include?(true)
  end
end
