class MapSum
  def initialize()
    @kvpair = {}
    @trie = {}
  end

  def insert(key, val)
    @kvpair[key] = val

    trie = @trie
    key.each_char do |ch|
      trie[ch] = {} unless trie.include?(ch)
      trie = trie[ch]
    end
    trie[nil] = nil
  end

  def sum(prefix)
    trie = @trie
    prefix.each_char do |ch|
      return 0 if !trie.include?(ch)
      trie = trie[ch]
    end

    sum = 0
    string_stack = prefix
    traverse = ->(t) do
      t.each_key do |key|
        if key.nil?
          sum += @kvpair[prefix]
        else
          prefix += key
          traverse.call(t[key])
          prefix = prefix[0...-1]
        end
      end
    end
    traverse.call(trie)

    sum
  end
end

