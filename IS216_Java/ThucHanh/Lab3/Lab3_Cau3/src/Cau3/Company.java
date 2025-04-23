package Cau3;

import java.util.*;

public class Company {
    private Set<String> employees = new HashSet<>();
    private List<String> employeeList = new ArrayList<>();
    private List<String> tripList = new ArrayList<>();
    private Map<String, Integer> purchaseMap = new HashMap<>();

    public void addEmployee(String name) {
        employees.add(name);
        employeeList.add(name);
    }

    public String pickRandomEmployee() {
        Random rand = new Random();
        if (employeeList.isEmpty()) return null;
        return employeeList.get(rand.nextInt(employeeList.size()));
    }

    public Set<String> getProductNames() {
        return employees;
    }

    public String getMostCommonEmployeeName() {
        Map<String, Integer> freqMap = new HashMap<>();
        for (String name : employeeList) {
            freqMap.put(name, freqMap.getOrDefault(name, 0) + 1);
        }
        return Collections.max(freqMap.entrySet(), Map.Entry.comparingByValue()).getKey();
    }

    public void registerForTrip(String name) {
        if (employeeList.contains(name)) {
            tripList.add(name);
        }
    }

    public List<String> getTripList() {
        return tripList.subList(0, Math.min(20, tripList.size()));
    }

    public void recordPurchase(String name, int amount) {
        purchaseMap.put(name, purchaseMap.getOrDefault(name, 0) + amount);
    }

    public void displayCustomerSales() {
        List<Map.Entry<String, Integer>> list = new ArrayList<>(purchaseMap.entrySet());
        list.sort((a, b) -> b.getValue() - a.getValue());
        for (Map.Entry<String, Integer> entry : list) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
    }
}
