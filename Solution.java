import java.util.Stack;
class Solution {
    class Data{
        int turn;
        int[][] field;
        int[] userA;
        int[] userB;
        int count;
        int depth;
        int result;
        public Data(int[][] field,int[] userA, int[] userB,int turn){
            this.field = field;
            this.userA = userA;
            this.userB = userB;
            this.turn = turn;
            this.count = 0;
            this.depth = 0;
            this.result = -1;
        }
    }
    private int maxr;
    private int maxc;
    public int canMove(int[] loc,int[][]field){


        if((loc[0]<0)||(loc[0]>=maxr)){
            return 0;
        }else if((loc[1]<0)||(loc[1]>=maxc)){
            return 0;
        }else if(field[loc[0]][loc[1]] == 0){
            return 0;
        }else{
            return 1;
        }
    }

    public int solution(int[][] board, int[] aloc, int[] bloc) {
        this.maxr = board.length;
        this.maxc = board[0].length;

        int count = 0;
        int check = -1;
        boolean state = false;
        int[][] move = {{-1,0},{1,0},{0,-1},{0,1}};
        int[] naloc = {aloc[0],aloc[1]};
        int[] nbloc = {bloc[0],bloc[1]};
        int[][] nboard = board;

        Stack<Data> path = new Stack<>();
        Stack<Data> pastPath = new Stack<>();
        int[][] field;
        int[] player;
        Data data = new Data(nboard,naloc,nbloc,1);
        path.push(data);

        while(path.size()!=0){
            Data cdata = path.pop();
            field = cdata.field;
            if(cdata.turn == 1){
                player = cdata.userA;
            }else{
                player = cdata.userB;
            }
            count = 0;

            if(field[player[0]][player[1]] != 0) {

                for (int i = 0; i < 4; i++) {
                    int[] newLoc = {player[0] + move[i][0], player[1] + move[i][1]};
                    check = this.canMove(newLoc, field);
                    if (check == 1) {

                        int[][] newField = field.clone();
                        for (int j = 0; j < board.length; j++) {
                            newField[j] = field[j].clone();
                        }

                        newField[player[0]][player[1]] = 0;
                        Data ndata;

                        if (cdata.turn == 1) {
                            ndata = new Data(newField, newLoc, cdata.userB.clone(), 2);
                        } else {
                            ndata = new Data(newField, cdata.userA.clone(), newLoc, 1);
                        }

                        ndata.depth = cdata.depth + 1;

                        path.push(ndata);
                        count += 1;

                    }
                }
            }

            if(count == 0) {
                if(pastPath.size() == 0){
                    pastPath.push(cdata);
                }else{
                    Data d = pastPath.pop();
                    d.count -=1;
                    if(d.result == -1){
                        d.result = cdata.depth;
                    }else{
                        if(d.turn == 2){
                            if((d.result%2==0)&&(cdata.depth%2==0)){
                                if(d.result > cdata.depth){
                                    d.result = cdata.depth;
                                }
                            }
                            if((d.result%2!=0)&&(cdata.depth%2!=0)){
                                if(d.result < cdata.depth){
                                    d.result = cdata.depth;
                                }
                            }
                            if((d.result%2!=0)&&(cdata.depth%2 == 0 )){
                                d.result = cdata.depth;
                            }
                        }else{
                            if((d.result%2==0)&&(cdata.depth%2==0)){
                                if(d.result < cdata.depth){
                                    d.result = cdata.depth;
                                }
                            }
                            if((d.result%2!=0)&&(cdata.depth%2!=0)){
                                if(d.result > cdata.depth){
                                    d.result = cdata.depth;
                                }
                            }
                            if((d.result%2==0)&&(cdata.depth%2 != 0 )){
                                d.result = cdata.depth;
                            }

                        }
                    }

                    while((d.count == 0) && (pastPath.size() != 0) ){
                        Data d2 = pastPath.pop();
                        d2.count -=1;
                        if(d2.result == -1){
                            d2.result = d.result;
                        }else{
                            if(d2.turn == 2){
                                if((d2.result%2==0)&&(d.result%2==0)){
                                    if(d2.result > d.result){
                                        d2.result = d.result;
                                    }
                                }
                                if((d2.result%2!=0)&&(d.result%2!=0)){
                                    if(d2.result < d.result){
                                        d2.result = d.result;
                                    }
                                }
                                if((d2.result%2!=0)&&(d.result%2 == 0 )){
                                    d2.result = d.result;
                                }
                            }else{
                                if((d2.result%2==0)&&(d.result%2==0)){
                                    if(d2.result < d.result){
                                        d2.result = d.result;
                                    }
                                }
                                if((d2.result%2!=0)&&(d.result%2!=0)){
                                    if(d2.result > d.result){
                                        d2.result = d.result;
                                    }
                                }
                                if((d2.result%2==0)&&(d.result%2 != 0 )){
                                    d2.result = d.result;
                                }

                            }

                        }
                        d = d2;
                    }
                    pastPath.push(d);
                }
            }else{
                cdata.count = count;
                pastPath.push(cdata);
            }
    }
        Data result = pastPath.pop();
        return result.result;
    }
}

