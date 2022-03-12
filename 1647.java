import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main{
	static class Node implements Comparable<Node>{
		int no, weight;

		public Node(int no, int weight){
			this.no = no;
			this.weight = weight;
		}

		@Override
		public int compareTo(Node o){
			return Integer.compare(this.weight, o.weight);
		}
	}

	private static int N, M, resMin;
	private static List<Node>[] maplist;

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stt = new StringTokenizer(br.readLine(), " ");

		N = Integer.parseInt(stt.nextToken());
		M = Integer.parseInt(stt.nextToken());
		maplist = new ArrayList[N + 1];

		for (int i = 1; i <= N; i++){
			maplist[i] = new ArrayList<Node>();
		}
		
		
		for (int i = 0; i < M; i++){
			stt = new StringTokenizer(br.readLine());
			int first = Integer.parseInt(stt.nextToken());
			int sec = Integer.parseInt(stt.nextToken());
			int weight = Integer.parseInt(stt.nextToken());

			maplist[first].add(new Node(sec, weight));
			maplist[sec].add(new Node(first, weight));
		}

		resMin = 0;
		prim();
		System.out.println(resMin);
	}

	private static void prim(){
		PriorityQueue<Node> pQueue = new PriorityQueue<Node>();
		int[] minEdge = new int[N + 1];
		Arrays.fill(minEdge, Integer.MAX_VALUE);
		boolean visited[] = new boolean[N + 1];

		int start_vertex = 1;
		int nodeCnt = 0;
		int max = 0;

		minEdge[start_vertex] = 0;
		pQueue.offer(new Node(start_vertex, 0));

		while (!pQueue.isEmpty()){
			Node minVertex = pQueue.poll();
			int cur_Vertex = minVertex.no;

			if (visited[cur_Vertex]){
				continue;
			}

			visited[cur_Vertex] = true;

			if (max < minVertex.weight){
				max = minVertex.weight;
			}

			resMin += minVertex.weight;

			for (int j = 0; j < maplist[cur_Vertex].size(); j++){
				Node node = maplist[cur_Vertex].get(j);
				int next = node.no;
				if (!visited[next] && node.weight < minEdge[next]){
					minEdge[next] = node.weight;
					pQueue.offer(new Node(next, node.weight));
				}
			}

			if (++nodeCnt == N){
				break;
			}
		}
		resMin -= max;
	}
}