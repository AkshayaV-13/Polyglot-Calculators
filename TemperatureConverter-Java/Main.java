import java.util.Scanner;

public class Main{



    public static void main(String[] args){

        Scanner scan = new Scanner(System.in);
        System.out.println("Temperature Converter");
        System.out.println("Option 1: Farenheit -> Celcius");
        System.out.println("Option 2: Celcius -> Farenheit");
        System.out.println("Please enter 1 or 2 for the conversion type:    ");
        int choice = scan.nextInt();
        while(choice != 1 && choice != 2){
            System.out.println("Invalid input, please enter 1 or 2: ");
            choice = scan.nextInt();
        }
        System.out.println("Please enter a temperature: ");
        while(!scan.hasNextFloat() ){
            System.out.println("Invalid input! Please enter a numeric value:");
            scan.next();
        }
        float temp = scan.nextFloat();


        if(choice == 1){
            float celcius = getCelcius(temp);
            System.out.println(celcius);
        }else{
            float farenheit = getFarenheit(temp);
            System.out.println(farenheit);
        }        
    }

    public static float getCelcius(float farenheit){

        float celcius = (farenheit - 32) * 5/9;
        
        return celcius;
    }

    public static float getFarenheit(float celcius){

        float farenheit = (celcius * 9/5) + 32;

        return farenheit;
    }

}