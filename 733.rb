def flood_fill(image, sr, sc, new_color)
  # Be careful when new_color == old_color
  color = image[sr][sc]
  if color != new_color
    image[sr][sc] = new_color

    flood_fill(image, sr - 1, sc, new_color) if sr > 0 && image[sr - 1][sc] == color
    flood_fill(image, sr + 1, sc, new_color) if (!image[sr + 1].nil?) && image[sr + 1][sc] == color
    flood_fill(image, sr, sc - 1, new_color) if sc > 0 && image[sr][sc - 1] == color
    flood_fill(image, sr, sc + 1, new_color) if image[sr][sc + 1] == color
  end

  image
end
