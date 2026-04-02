import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(bf.readLine());

        while (T-- > 0) {
            int N, M; // N 몇개인지 , M 몇번째인지
            StringTokenizer st = new StringTokenizer(bf.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(bf.readLine());

            Queue<Pair> q = new ArrayDeque<>();
            ArrayList<Integer> list = new ArrayList<>();

            for (int i = 0; i < N; i++) {
                int num = Integer.parseInt(st.nextToken());
                if (i == M) {
                    q.add(new Pair(num, true));
                } else
                    q.add(new Pair(num, false));

                list.add(num);
            }
            Collections.sort(list, Collections.reverseOrder());

            int cnt = 1;
            while (true) {
                Pair front = q.poll();

                if (list.get(0) > front.first) {
                    q.peek();
                    q.add(front);
                } else {
                    if (front.second) {
                        break;
                    }
                    cnt++;
                    q.peek();
                    list.remove(0);
                }
            }

            System.out.println(cnt);
        }

    }

    public static class Pair {
        int first;
        boolean second;

        Pair(int x, boolean y) {
            this.first = x;
            this.second = y;
        }
    }
}
