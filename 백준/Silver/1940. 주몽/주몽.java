import java.util.*;
import java.io.*;;

class Main {
    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N, M; // 재료의 개수 , 갑옷을 만드는데 필요한 수

        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        int arr[] = new int[N];
        HashSet<Integer> set = new HashSet<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            set.add(Integer.parseInt(st.nextToken()));
        }

        int sum = 0;

        for (int i : set) {
            if (set.contains(M - i)) {
                sum += 1;
            }
        }

        System.out.println(sum / 2);

    }
}
