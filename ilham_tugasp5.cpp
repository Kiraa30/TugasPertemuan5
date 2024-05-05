#include <iostream>
using namespace std;

const int maksimal = 3;
int top_A = 0, top_B = 0, top_C = 0;
int place_A[maksimal], place_B[maksimal], place_C[maksimal];

void pushNilai(int place[], int &top, int nilai){
    if (top >= maksimal){
        cout << "Tower penuh" << endl;
    } else {
        place[top] = nilai;
        top++;
    }
}

void PopNilai(int place[], int &top){
    if(top <= 0){
        cout << "Tower kosong " << endl;
    } else {
        top--;
        place[top] = 0;
    }
}

void DisplayNilai(const string &placeName, const int place[], int top){
    cout << "Nilai di " << placeName << ": ";
    if(top == 0){
        cout << "Tower ini kosong" << endl;
        }else{
        for (int i = 0; i < top; ++i){
            cout << place[i] << " ";
        } cout << endl;
    }
}

int main(){
    pushNilai(place_A, top_A, 20);
    pushNilai(place_A, top_A, 40);
    pushNilai(place_A, top_A, 60);

    DisplayNilai("Town A", place_A, top_A);
    DisplayNilai("Town B", place_B, top_B);
    DisplayNilai("Town C", place_C, top_C);

    if(top_A > 0){
        pushNilai(place_B, top_B, place_A[top_A - 1]);
        PopNilai(place_A, top_A);
    }

    if (top_B > 0){
        pushNilai(place_C, top_C, place_B[top_B - 1]);
        PopNilai(place_B, top_B);
    }

    if (top_A > 0){
        pushNilai(place_C, top_C, place_A[top_A - 1]);
        PopNilai(place_A, top_A);
    }

    cout << "\n Setelah pemindahan :" << endl;
    DisplayNilai("Tower A", place_A, top_A);
    DisplayNilai("Tower B", place_B, top_B);
    DisplayNilai("Tower C", place_C, top_C);

    cout << "Program selesai." << endl;
    cout << "Program dibuat oleh: M. Ilham Syahputra (2310631170027)" << endl;
    return 0;
}
