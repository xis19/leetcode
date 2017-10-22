LEADING = {'1': '1', '6': '9', '8': '8', '9': '6'}
MID = ['0', '1', '8']
REMAIN = {'1': '1', '6': '9', '8': '8', '9': '6', '0': '0'}

def find_strobogrammatic(n)
  case n
  when 0
    ['']
  when 1
    MID
  else
    LEADING.keys.product(*([REMAIN.keys] * (n / 2 - 1))).map do |i|
      straight = i.join
      reverse = i.reverse.map { |i| REMAIN[i] }.join
      if n % 2 == 1
        MID.map { |m| straight + m + reverse }
      else
        straight + reverse
      end
    end.flatten
  end
end
