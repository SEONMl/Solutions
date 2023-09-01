package N3;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Solution {

    enum Classification{
        Coupe, Truck, Sedan, RV, Bus;
    }
    static class Car {
        String name;
        boolean terminal;
        Classification classification;
        int people;
        String start;
        String end;

        boolean canBoard(int count){
            return people>=count;
        }
        boolean isProducing(String date){
            return (start.compareTo(date)<=0 && end.compareTo(date)>=0);
        }
        String print(){
            StringBuilder sb = new StringBuilder();
            sb.append(name);
            if(terminal) sb.append("*");
            sb.append("(");
            sb.append(classification.toString());
            sb.append(")");
            return sb.toString();
        }

        public Car(String name, boolean terminal, Classification classification, int people, String start, String end) {
            this.name = name;
            this.terminal = terminal;
            this.classification = classification;
            this.people = people;
            this.start = start;
            this.end = end;
        }
    }

    public static String solution(String param0, int param1) {

        List<Car> model = List.of(
                new Car("Tuscani", true, Classification.Coupe, 2,"200109","200810"),
                new Car("Porter", true, Classification.Truck, 3,"197702","200405"),
                new Car("Cortina", true, Classification.Sedan, 5,"196801","198004"),
                new Car("Elantra", true, Classification.Sedan, 5,"199010","199512"),
                new Car("Equus", true, Classification.Sedan, 5,"199904","200912"),

                new Car("Grandeur", false, Classification.Sedan, 5,"198607","999999"),
                new Car("Pony", true, Classification.Sedan, 5, "197512","198201"),
                new Car("SantaFe", false, Classification.RV, 7,"200006","999999"),
                new Car("Aerotown", false, Classification.Bus, 30,"199406","999999"),
                new Car("Universe", false, Classification.Bus, 45,"200006","999999")
        );

        List<String> result = new ArrayList<>();
        for(Car car: model){
            StringBuilder sb = new StringBuilder();
            if(car.isProducing(param0) && car.canBoard(param1)){
                sb.append(car.print());
                result.add(sb.toString());
            }
        }

        if(result.isEmpty()) return "!";

        Collections.sort(result);
        StringBuilder sb = new StringBuilder();

        for(int i=0;i<result.size();i++){
            sb.append(result.get(i));
            if(i<result.size()-1) sb.append(",");
        }
        return sb.toString();
    }

}
