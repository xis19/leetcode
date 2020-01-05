def max_killed_enemies(grid)
  return 0 if grid.empty?
  m = grid.size
  return 0 if grid[0].empty?
  n = grid[0].size

  max_kill = 0
  (0...m).each do |y|
    (0...n).each do |x|
      next if grid[y][x] != '0'

      kill_count = 0
      y.downto(0) do |_y|
        case grid[_y][x]
        when 'E' then kill_count += 1
        when 'W' then break
        end
      end
      y.upto(m - 1) do |_y|
        case grid[_y][x]
        when 'E' then kill_count += 1
        when 'W' then break
        end
      end
      x.downto(0) do |_x|
        case grid[y][_x]
        when 'E' then kill_count += 1
        when 'W' then break
        end
      end
      x.upto(n - 1) do |_x|
        case grid[y][_x]
        when 'E' then kill_count += 1
        when 'W' then break
        end
      end

      max_kill = [max_kill, kill_count].max
    end
  end

  max_kill
end
