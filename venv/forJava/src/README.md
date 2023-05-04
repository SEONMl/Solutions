# 코테용 Java 실전 압축 정리
```java
import java.util.*;
import java.lang.*; // Math
```

## 배열/2차원배열 초기화
```java
int[][] arr = new int[4][4]; // 0으로 초기화
int size = arr.length;
// array to list
Arrays.asList(int[]);
// list to array
list.toArray(ArrayList)
list.stream().toArray(String::new);
list.stream().mapToInt(i-> i).toArray();
```

## 자료형
int long char String 

## String 
- .charAt(index)
- .substring(start, end)
- .substring(start) // start부터 끝까지
- .split(regex)
- .length()
- String.valueOf(int)
- .toUpperCase()
- .toLowerCase()
- .replace("대상","바꿀 문자")

## StringBuilder
StringBuilder sb = new StringBuilder();
- .toString()
- .append(data)
- .reverse()
- .isEmpty()
- .length()
- .setLength(len)

---
# 자료구조

## Stack
Stack<> stack = new Stack();

**push, pop**
- .peek() 맨 위 객체 반환
- .pop() 스택에 제거
- .push() 스택에 추가

## queue
Queue<> queue = new LinkedList();

**offer, poll**
- .offer(data) // 큐에 추가
- .peek() // 가장 먼저 보관한 값 참조 back
- .poll() // 가장 먼저 보관한 값 꺼내고 반환 pop

## heap
Queue<> pq = new PriorityQueue<>(); // 최소힙
- .offer()
-  .poll()

## deque
Deque<> dq = new ArrayDeque();
- .offerFirst()
- .offerLast()
- .pollFirst()
- .pollLast()
- .peek()


## set
Set<> set = new HashSet<>();

순서 보장 LinkedHashSet
- .add()
- .remove()
- .contains()
- .addAll(set<>) // Union 합집합
- .retainAll(set<>) // Intersection 교집합


## map
Map<> map = new HashMap();

순서보장 LikedHashMap
- .put()
- .get()
- .remove()

---
# 정렬
## 정렬(오름,내림)
- Collections.sort(Object) -> 오름차순
- Collections.sort(O, Collections.reverseOrder()) -> 내림차순
- Arrays.sort(array);
- Arrays.sort(arr, Collections.reverseOrder());

## min max min_element max_element
Math.max(a,b);

list.stream().max();

mapToInt().sum();

Integer.parseInt(string)

## 정렬 커스텀
커스텀 소팅할 일이 있을까...?

Comparator 구현, Override, int 반환..
아니면 stream.sorted(람다).collect(Collectors.toList()) 로 정렬해도 됨.
```java
 class MyCompare implements Comparator<String> {
        @Override
        public int compare(String a, String b){
            if(a.charAt(0)>b.charAt(0)) return 1;
            else if(a.charAt(0)==b.charAt(0)){
                return (a.length()<b.length())?1:0;
            }
            return 0;
        }
    }
```
-----------------------------------
### Date 클래스
```java
String strDate1 = "202201061515";
DateTimeFormatter format1 = DateTimeFormatter.ofPattern("yyyyMMddHHmm");
LocalDateTime strToLocalDateTime1 = LocalDateTime.parse(strDate1, format1);

Duration duration = Duration.between(startDateTime, endDateTime);
```
------------------------
### BFS
```java
int[] dx={0,1,0,-1};
int[] dy={1,0,-1,0};
class Position {
    int x;
    int y;
    int dis;

    public Position(int x, int y,int dis) {
        this.x = x;
        this.y = y;
        this.dis=dis;
    }
}
bfs(int[][] g,int a,int b){
        Queue<Position> q = new LinkedList<>();
        q.add(new Position(a,b,0));
        boolean[][] visit = new boolean[N][N];
        visit[a][b]=true;

        while(!q.isEmpty()){
            Position cur = q.poll();
            for(int i=0;i<4;i++){
                int nx= cur.x+dx[i];
                int ny= cur.y+dy[i];
                int dis=cur.dis;

                if(0<=nx&&nx<N&&0<=ny&&ny<N &&!visit[nx][ny] &&g[nx][ny]==1){
                    visit[nx][ny]=true;
                    q.add(new Position(nx,ny,dis+1));
                }
            }
        }
    }
```