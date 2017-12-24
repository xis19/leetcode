class ValidWordAbbr
  def initialize(dictionary)
    # Be aware the word could be in the dictionary!!!
    # Be aware duplicate words in the dictionary!!!
    @dict = Set.new(dictionary)
    @abbrs = Hash.new { |hash, v| hash[v] = 0 }
    @dict.each do |word|
      @abbrs[simplify(word)] += 1
    end
  end

  def is_unique(word)
    if @dict.include?(word)
      @abbrs[simplify(word)] == 1
    else
      @abbrs[simplify(word)] == 0
    end
  end

  private
  def simplify(word)
    if word.length <= 2
      word
    else
      word[0] + (word.length - 2).to_s + word[-1]
    end
  end
end
