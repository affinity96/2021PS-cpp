#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class Student {
    public:
        string name;
        int kor;
        int eng;
        int mat;
    Student(string name_, int kor_, int eng_, int mat_){
        this->name = name_;
        this->kor = kor_;
        this->eng = eng_;
        this->mat = mat_;
    }
    bool operator < (Student &a){
        if(this->kor == a.kor){
            if(this->eng == a.eng){
                if(this->mat == a.mat){
                    return this->name < a.name;
                }else{
                    return this->mat > a.mat;
                }
            }else{
                return this->eng < a.eng;
            }
        }else{
            return this->kor > a.kor;
        }
    }
};
int main(){
    cin.tie(0);
    ios_base :: sync_with_stdio(false);
    vector<Student> stu;
    int N; cin >> N;
    for(int n=0; n<N; n++){
        string name;
        int kor;
        int eng;
        int mat;
        cin>>name>>kor>>eng>>mat;
        stu.push_back(Student(name,kor,eng,mat));
    }
    sort(stu.begin(), stu.end());

    for(int n=0; n<N; n++){
        cout << stu[n].name << "\n";
    }
}