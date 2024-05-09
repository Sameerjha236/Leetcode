class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size();
        int m = version2.size();
        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            string num1 = "";
            string num2 = "";
            while (i < n && version1[i] != '.') {
                if (num1 != "0" || version1[i] != '0')
                    num1 += version1[i];
                i++;
            }
            i++;
            while (j < m && version2[j] != '.') {
                if (num2 != "0" || version2[j] != '0')
                    num2 += version2[j];
                j++;
            }
            j++;
            if (num1 == "") {
                num1 = "0";
            }
            if (num2 == "") {
                num2 = "0";
            }
            int Num1 = stoi(num1);
            int Num2 = stoi(num2);
            // cout << Num1 << " " << Num2;
            if (Num1 > Num2) {
                return 1;
            } else if (Num1 < Num2) {
                return -1;
            } else {
            }
        }

        if (i == n + 1 && j == m + 1) {
            return 0;
        } else if (i == n + 1 && j != (m + 1)) {
            for (int k = j; k < m; k++) {
                if (version2[k] != '0' && version2[k] != '.') {
                    return -1;
                }
            }
            return 0;
        } else {
            for (int k = i; k < n; k++) {
                if (version1[k] != '0' && version1[k] != '.') {
                    return 1;
                }
            }
            return 0;
        }
    }
};