public class Run {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Solution test = new Solution();
		int[][] board = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
		int[][] board2 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
		int[] aloc = {1,0};
		int[] bloc = {1,2};
		int solution = 5;
		System.out.println(test.solution(board, aloc, bloc));



	}

}
