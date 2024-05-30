#include <iostream>
using namespace std;

class Queues {
    private:
        static const int max = 3;
        int FRONT, REAR;
        int queue_array[max];

    public:
        Queues() {
            FRONT = -1;
            REAR = -1;
        }

        void insert() {
            int num;
            cout << "Enter a number : ";
            cin >> num;
            cout << endl;
        

        //cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max -1) || (FRONT == REAR + 1)){
            cout << "\nQueue overflow\n";
            return;
        }

        //cek apakah antrin kosong
        if (FRONT == -1) {
            FRONT = 0;
            REAR = 0;
        }

        else {
            //jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == max -1)
                REAR = 0;
            else    
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
     }

     void remove() {
        // apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\n The element deleted from the  queue is:" << queue_array[FRONT] << "\n";

        // cek jika elemen hanya memiliki satu elemen 
        if (FRONT == REAR) {
            FRONT = -1;
            REAR = -1;
        }
        else {
            //jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
            if (FRONT == max -1)
                FRONT = 0;
            else   
                FRONT = FRONT + 1;
        }
     }

     void display() {
        int FRONT_Position = FRONT;
        int REAR_Position = REAR;

        // Cek apakah antrian kosong 
        if(FRONT_Position == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElement in the queue are....\n";

        //Jika FRONT <= RERAR, iterasi dari FRONT hingga REAR
        if(FRONT_Position <= REAR_Position) {
            while(FRONT_Position <= REAR_Position) {
                cout << queue_array[FRONT_Position] << " ";
                FRONT_Position++;
            }

            FRONT_Position = 0;

            //iterasi dari awal array hingga rear
            while(FRONT_Position <= REAR_Position) {
                cout << queue_array[FRONT_Position] << " ";
                FRONT_Position++;
            }
        }
     }
};