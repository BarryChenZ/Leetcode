class Solution {
public:
    string intToRoman(int num) {
        int I = 0;
        int V = 0;
        int X = 0;
        int L = 0;
        int C = 0;
        int D = 0;
        int M = 0;
        string result;
        //900 400 90 40 9 4 特殊處理
        M = num/1000;
        num = num%1000;
        for(int i = 0; i < M; ++i){
            result += "M";
        }
        M = 0;
        
        D = num/500;
        num = num%500;
        C = num/100;
        num = num%100;
        if(D+C == 5 &&  D == 1){//900
            result += "CM";
        }
        else if(D+C == 4 &&  C == 4){//400
            result += "CD";
        }
        else{
            for(int i = 0; i < D; ++i){
                result += "D";
            }
            for(int i = 0; i < C; ++i){
                result += "C";
            }
        }
        L = num/50;
        num = num%50;
        X = num/10;
        num = num%10;
        if(L+X == 5 &&  L == 1){//90
            result += "XC";
        }
        else if(L+X == 4 &&  X == 4){//40
            result += "XL";
        }
        else{
            for(int i = 0; i < L; ++i){
                result += "L";
            }
            for(int i = 0; i < X; ++i){
                result += "X";
            }
        }
        V = num/5;
        num = num%5;
        I = num/1;
        num = num%1;
        if(V+I == 5 &&  V == 1){//9
            result += "IX";
        }
        else if(V+I == 4 &&  I == 4){//4
            result += "IV";
        }
        else{
            for(int i = 0; i < V; ++i){
                result += "V";
            }
            for(int i = 0; i < I; ++i){
                result += "I";
            }
        }
        return result;
    }
};
