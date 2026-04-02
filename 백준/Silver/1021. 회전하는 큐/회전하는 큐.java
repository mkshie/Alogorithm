import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());

        Deque<Integer> dq = new ArrayDeque<>();
        for (int i = 1; i <= N; i++) {
            dq.add(i);
        }

        st = new StringTokenizer(bf.readLine());

        int sum = 0;

        while (st.hasMoreTokens()) {
            int num = Integer.parseInt(st.nextToken());

            int cnt = 0;
            while (!dq.isEmpty() && dq.getFirst() != num) {
                // dq 가 비어있지 않고 올바른 값이 아니라면?
                int copy_num = dq.removeFirst();
                dq.addLast(copy_num);
                cnt++;
            }

            if (cnt > dq.size() / 2) {
                cnt = dq.size() - cnt;
            }
            sum += cnt;
            dq.removeFirst();
        }

        System.out.println(sum);
    }
}
