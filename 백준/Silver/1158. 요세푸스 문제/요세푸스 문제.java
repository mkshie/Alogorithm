import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(bf.readLine());

        int N, K; // N 은 총 인원 , K 지워야하는 인원

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        ArrayList<Integer> list = new ArrayList<>();

        for (int i = 1; i <= N; i++) {
            list.add(i);
        }

        StringBuilder sb = new StringBuilder("<");

        sb.append(list.get(K - 1));
        list.remove(K - 1);
        int idx = 0;
        if (!list.isEmpty()) {
            idx = 2 * (K - 1) % list.size();
        }

        while (!list.isEmpty()) {
            sb.append(", ");
            sb.append(list.get(idx));
            list.remove(idx);
            // 배열 제거 완료
            // idx 위치 수정

            if (list.isEmpty())
                break;

            idx = (idx + K - 1) % list.size();
        }

        sb.append(">");

        System.out.println(sb.toString());
    }
}
