def max_area_of_island(grid)
  max_area = 0

  rr, cc = grid.size, grid[0].size

  (0...rr).each do |r|
    (0...cc).each do |c|
      next if grid[r][c] != 1

      area = 0
      queue = Array.new
      queue.push([r, c])
      while !queue.empty?
        r1, c1 = queue.shift
        next if grid[r1][c1] != 1

        area += 1
        grid[r1][c1] = -1

        queue.push([r1 - 1, c1]) if r1 > 0
        queue.push([r1 + 1, c1]) if r1 < rr - 1
        queue.push([r1, c1 - 1]) if c1 > 0
        queue.push([r1, c1 + 1]) if c1 < cc - 1
      end

      max_area = [area, max_area].max
    end
  end

  max_area
end
