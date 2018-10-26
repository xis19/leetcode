MINUTES_PER_DAY = 24 * 60
def find_min_difference(time_points)
  time_mins = time_points.map { |item|
    hour, min = item.split(':').map { |s| s.to_i }
    hour * 60 + min
  }.sort

  min_diff = MINUTES_PER_DAY + 1
  (0...time_mins.length - 1).each do |i|
    min_diff = [min_diff, time_mins[i + 1] - time_mins[i], MINUTES_PER_DAY - time_mins[i + 1] + time_mins[i]].min
  end

  min_diff = [min_diff, MINUTES_PER_DAY - time_mins[-1] + time_mins[0]].min

  min_diff
end
