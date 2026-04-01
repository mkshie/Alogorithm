import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // 총핵 이하에서 가능한 최대의 총 예산을 구해야함
        // 1. 모든 요청이 배정될 수 있는 경우에는 요청한 금액을 그대로 배정
        // 2. 배정될 수 없는 경우에는 특정한 정수 상한액을 계산하여 그 이상인 예산 요청에는 모두 상한액을 배정해야함 상한액 이하의 예산 요청에
        // 대해서는 요청한 금액을 그대로 배정

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N; // 지방의 수
        N = Integer.parseInt(st.nextToken());
        int arr[] = new int[N];

        st = new StringTokenizer(br.readLine());

        long initSum = 0;
        long maxNum = 0;
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            initSum += arr[i];
            maxNum = Math.max(maxNum, arr[i]);
        }

        long M = Long.parseLong(br.readLine()); // 총 예산

        if (initSum <= M) {
            System.out.println(maxNum);
            return;
        }

        int arrSize = arr.length;

        int left = 0, right = 100000;

        int answer = 0;

        while (left <= right) {
            int mid = (left + right) / 2;

            long sum = 0;

            for (int i = 0; i < arrSize; i++) {
                if (arr[i] > mid) {
                    sum += mid;
                } else {
                    sum += arr[i];
                }
            }

            if (sum <= M) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        System.out.println(answer);
    }

}
