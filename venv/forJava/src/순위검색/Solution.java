package 순위검색;

import java.util.*;
import java.util.stream.Collectors;

class Solution {
    Map<Integer,Integer> score = new HashMap<>();
    class Language{
        Set<Integer> python = new HashSet<>();
        Set<Integer> cpp = new HashSet<>();
        Set<Integer> java = new HashSet<>();

        public void add(int idx,String str){
            if(str.equals("python")) python.add(idx);
            else if(str.equals("java")) java.add(idx);
            else cpp.add(idx);
        }

        public Set<Integer> get(String s) {
            if(s.equals("python")) return python;
            else if(s.equals("java")) return java;
            else return cpp;
        }
    }
    class Job{
        Set<Integer> backend = new HashSet<>();
        Set<Integer> frontend = new HashSet<>();

        public void add(int idx,String str){
            if(str.equals("frontend")) frontend.add(idx);
            else backend.add(idx);
        }
        public Set<Integer> get(String s) {
            if(s.equals("backend")) return backend;
            else return frontend;
        }
    }
    class Career{
        Set<Integer> junior = new HashSet<>();
        Set<Integer> senior = new HashSet<>();

        public void add(int idx,String str){
            if(str.equals("junior")) junior.add(idx);
            else senior.add(idx);
        }
        public Set<Integer> get(String s) {
            if(s.equals("junior")) return junior;
            else return senior;
        }
    }
    class SoulFood{
        Set<Integer> chicken = new HashSet<>();
        Set<Integer> pizza = new HashSet<>();

        public void add(int idx,String str){
            if(str.equals("chicken")) chicken.add(idx);
            else pizza.add(idx);
        }
        public Set<Integer> get(String s) {
            if(s.equals("chicken")) return chicken;
            else return pizza;
        }
    }

    // 언어 직군 경력 소울 점수
    public int[] solution(String[] info, String[] queries) {
        int[] answer = new int[queries.length];
        Set<Integer> total = new HashSet<>();
        Language language = new Language();
        Job job = new Job();
        Career career = new Career();
        SoulFood soulFood = new SoulFood();

        int idx=0;
        for(String str: info){
            String[] tmp = str.split(" ");
            total.add(idx);
            language.add(idx, tmp[0]);
            job.add(idx, tmp[1]);
            career.add(idx, tmp[2]);
            soulFood.add(idx, tmp[3]);
            score.put(idx, Integer.parseInt(tmp[4]));
            idx++;
        }

        idx=0;
        for(String query:queries){
            Set<Integer> people= new HashSet<>(total);
            List<String> require= Arrays.stream(query.split("and")).map(i->i.strip()).collect(Collectors.toList());

            if(!require.get(0).equals("-")) people.retainAll(language.get(require.get(0)));
            if(!require.get(1).equals("-")) people.retainAll(job.get(require.get(1)));
            if(!require.get(2).equals("-")) people.retainAll(career.get(require.get(2)));

            String[] tmp=require.get(3).split(" ");
            if(!tmp[0].equals("-")) people.retainAll(soulFood.get(tmp[0]));
            int reqScore=Integer.parseInt(tmp[1]);

            answer[idx]=(int) people.stream().filter(i->score.get(i)>=reqScore).count();
            idx++;
        }

        return answer;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String[] s1={"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
        String[] s2={"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
        int[] solution1 = solution.solution(s1, s2);
        for(int a:solution1){
            System.out.print(a+" ");
        }
    }
}