def find_contest_match(n)
  def bend(matches)
    (0...matches.length / 2).map do |index|
      "(#{matches[index]},#{matches[matches.length - index - 1]})"
    end.to_a
  end
  result = (1..n).map { |i| i.to_s }.to_a
  result = bend(result) while result.length > 1

  result[0]
end
