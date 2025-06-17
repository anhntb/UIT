package BT;
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author NTB Anh
 */
import java.io.*;
import java.util.*;

public class BTVN_Cau7 {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        // TODO code application logic here
        
        String inputFile = "input.txt"; 
        String outputFile = "output.txt";

        try {
            // Read data
            Scanner scanner = new Scanner(new File(inputFile));
            int days = scanner.nextInt(); // Read the number of days
            double[][] temperatures = new double[days][12];

            // Read temperature data for each day
            for (int i = 0; i < days; i++) {
                for (int j = 0; j < 12; j++) {
                    temperatures[i][j] = scanner.nextDouble();
                }
            }
            scanner.close();

            // Process data
            double[] avgTemps = new double[days];
            double[] maxTemps = new double[days];
            double[] minTemps = new double[days];
            double overallAvg;
            double overallMax = Double.MIN_VALUE;
            double overallMin = Double.MAX_VALUE;

            double sumAvg = 0;
            for (int i = 0; i < days; i++) {
                double sum = 0;
                double maxTemp = Double.MIN_VALUE;
                double minTemp = Double.MAX_VALUE;

                for (int j = 0; j < 12; j++) {
                    sum += temperatures[i][j];
                    if (temperatures[i][j] > maxTemp) maxTemp = temperatures[i][j];
                    if (temperatures[i][j] < minTemp) minTemp = temperatures[i][j];

                    if (temperatures[i][j] > overallMax) overallMax = temperatures[i][j];
                    if (temperatures[i][j] < overallMin) overallMin = temperatures[i][j];
                }
                avgTemps[i] = sum / 12;
                sumAvg += avgTemps[i];
                maxTemps[i] = maxTemp;
                minTemps[i] = minTemp;
            }
            overallAvg = sumAvg / days;

            // Write results
            PrintWriter writer = new PrintWriter(new File(outputFile));
            writer.println("Nhiet do Trung binh, Cao nhat, Thap nhat hang ngay: ");
            for (int i = 0; i < days; i++) {
                writer.printf("Day %d: Average = %.2f, Max = %.2f, Min = %.2f%n",
                        (i + 1), avgTemps[i], maxTemps[i], minTemps[i]);
            }
            writer.printf("\nNhiet do trung binh trong tat ca cac ngay: %.2f%n", overallAvg);
            writer.printf("Nhiet do cao nhat trong tat ca cac ngay: %.2f%n", overallMax);
            writer.printf("Nhiet do thap nhat trong tat ca cac ngay: %.2f%n", overallMin);
            writer.close();

            System.out.println("Du lieu da xu ly va luu vao file " + outputFile);
        } catch (IOException e) {
            System.err.println("Error reading or writing file: " + e.getMessage());
        }
    }
}
