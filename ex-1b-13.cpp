/*
 * ## EXERCISE 13: Comprehensive Integration [All concepts from 1.b]
 * 
 * Write a student grade management system that uses multiple STL features.
 * 
 * **Requirements:**
 * 1. Use std::map<string, vector<int>> for student_name -> grades
 * 2. Add students: Alice {85, 90, 88}, Bob {78, 85, 80}, Charlie {92, 88, 95}
 * 3. Function to calculate average using std::accumulate
 * 4. Function to find highest grade using std::max_element
 * 5. Sort students by average grade (use vector of pairs and std::sort with lambda)
 * 6. Find all students with average > 85
 * 7. Use string operations to format output
 * 8. Use iterators throughout
 * 
 * **Expected output format:**
 * ```
 * === Student Grade Management System ===
 * 
 * All Students:
 * Alice: grades [85, 90, 88], average: 87.67, highest: 90
 * Bob: grades [78, 85, 80], average: 81.00, highest: 85
 * Charlie: grades [92, 88, 95], average: 91.67, highest: 95
 * 
 * Students sorted by average (descending):
 * 1. Charlie: 91.67
 * 2. Alice: 87.67
 * 3. Bob: 81.00
 * 
 * Students with average > 85:
 * - Alice (87.67)
 * - Charlie (91.67)
 * 
 * Total students: 3
 * Total grades recorded: 9
 * ```
 */ 

#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

int main() {

    std::map<std::string, std::vector<int>> grades;
    std::vector<std::pair<std::string, double>> studentsAndAverages;

    grades["Alice"] = { 85, 90, 88 };
    grades["Bob"] = { 78, 85, 80 };
    grades["Charlie"] = { 92, 88, 95 };

    for (const auto record : grades) {
        std::cout << record.first << ": grades [";
        std::vector<int> scores = record.second;
        bool first = true;
        for (const auto grade : scores) {
            if (first) {
                first = false;
            } else {
                std::cout << ", ";
            }
            std::cout << grade;
        }
        int sum = std::accumulate(scores.begin(), scores.end(), 0);
        double average = (double)sum / scores.size();

        std::cout << "], average: " << std::setprecision(4) << average
            << ", highest: "
            << *std::max_element(scores.begin(), scores.end()) << std::endl;

        studentsAndAverages.push_back({record.first, average});
    }


    std::sort(studentsAndAverages.begin(), studentsAndAverages.end(),
        [](const std::pair<std::string, int> &a,
            const std::pair<std::string, int> &b) {
            return a.second > b.second;
        }
    );

    std::cout << "Students sorted by average (descending):" << std::endl;
    int index = 1;
    for (const auto& student : studentsAndAverages) {
        std::cout << index << ". " << student.first << ": "
            << student.second << std::endl;
        index++;
    }

    std::cout << "Students with average > 85:" << std::endl;
    for (const auto& student : studentsAndAverages) {
        if ( student.second < 85 ) {
            continue;
        }
        std::cout << "- " << student.first << "(" << student.second
            << ")" << std::endl;
    }

    std::cout << "Total students: " << grades.size() << std::endl;

    int totalGrades = 0;
    for (const auto &scores : grades) {
        totalGrades += scores.second.size();
    }

    std::cout << "Total grades recorded: " << totalGrades << std::endl;
}
