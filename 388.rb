def length_longest_path(input)
  longest = 0
  # We will see the use later
  path_len = [-1]

  input.split("\n").each do |line|
    tabs = 0
    tabs += 1 while line[tabs] == "\t"

    part_len = line.length - tabs

    case tabs <=> path_len.length - 2
      when -1
        # Pop
        path_len.pop while path_len.length > tabs + 1
      when 0
        # Replace
        path_len.pop
      when 1
        nil
    end

    # Each time we add /path, at the beginning there is no /, so we lead
    # the path_len with -1
    path_len.push(part_len + 1 + path_len.last)
    longest = [longest, path_len.last].max if line.include?('.')
  end

  longest
end
