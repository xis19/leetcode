class TicTacToe
  def initialize(n)
    @dim = n
    @board = (0...n).map { [0] * n }.to_a
    @row_player_count = (0..1).map { [0] * n }.to_a
    @col_player_count = (0..1).map { [0] * n }.to_a
    @diag_player_count = [0, 0]
    @adiag_player_count = [0, 0]
  end

  def move(row, col, player)
    @board[row][col] = player

    @row_player_count[player - 1][row] += 1
    return player if @row_player_count[player - 1][row] == @dim

    @col_player_count[player - 1][col] += 1
    return player if @col_player_count[player - 1][col] == @dim

    if row == col
      @diag_player_count[player - 1] += 1
      return player if @diag_player_count[player - 1] == @dim
    end

    if row == @dim - col - 1
      @adiag_player_count[player - 1] += 1
      return player if @adiag_player_count[player - 1] == @dim
    end

    return 0
  end
end
