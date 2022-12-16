package 주차요금계산;

import java.time.Duration;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.*;

class Solution {
    Map<String, LocalTime> parking = new HashMap<>();
    Map<String, Long> parkingDuration = new HashMap<>();


    public int[] solution(int[] fees, String[] records) {
        for(String s:records){
            String[] tmp=s.split(" ");
            String car=tmp[1];
            LocalTime parsed = transTime(tmp[0]);

            if(tmp[2].equals("IN")) {
                parking.put(car, parsed);
            }else{
                LocalTime inTime = parking.remove(car);
                long parkingTime = getParkingTime(inTime,parsed);
                parkingDuration.put(car, parkingDuration.getOrDefault(car,0l)+parkingTime);
          }
        }

        for(Map.Entry<String,LocalTime> entry:parking.entrySet()){
            LocalTime lastTime=LocalTime.of(23,59,0);
            String car=entry.getKey();
            long parkingTime=getParkingTime(entry.getValue(), lastTime);
            parkingDuration.put(car, parkingDuration.getOrDefault(car,0l)+parkingTime);
        }

        List<String> keyList=new ArrayList<>(parkingDuration.keySet());
        Collections.sort(keyList);

        int[] answer = new int[parkingDuration.size()];
        for(int i = 0; i< parkingDuration.size(); i++){
           long duration= parkingDuration.get(keyList.get(i));
           answer[i]=calculateFee(fees,duration);
        }

        return answer;
    }

    private long getParkingTime(LocalTime inTime, LocalTime outTime) {
        Duration duration = Duration.between(inTime, outTime);
        return duration.getSeconds()/60;
    }

    public int calculateFee(int[] fees,long duration){
        int fee=fees[1];
        duration-=fees[0];
        if(duration>0) {
            fee += (duration / fees[2]) * fees[3];
            duration %= fees[2];
            fee+=(duration>0)?fees[3]:0;
        }
        return fee;
    }

    public LocalTime transTime(String strTime){
        DateTimeFormatter format=DateTimeFormatter.ofPattern("HH:mm");
        LocalTime parsed = LocalTime.parse(strTime, format);
        return parsed;
    }

    public static void main(String[] args) {
        Solution a = new Solution();
        int[] fee={1, 461, 1, 10};
        String[] re={"00:00 1234 IN"};
        for(int s:a.solution(	fee, re)){
            System.out.println(s);
        }
    }
}