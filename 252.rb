class Interval
    attr_accessor :start, :end
    def initialize(s=0, e=0)
        @start = s
        @end = e
    end
end

def can_attend_meetings(intervals)
  sorted = intervals.sort { |i, j| i.start <=> j.start }
  (0...sorted.length - 1).each { |i| return false if sorted[i].end > sorted[i + 1].start }
  true
end
